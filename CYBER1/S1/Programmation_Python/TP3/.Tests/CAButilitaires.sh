#!/usr/bin/env bash

# DESCRIPTION
#
# Fonctions facilitant l'écriture des scripts de test.
#
# USAGE
#
# source un/chemin/utilitaires.sh 2>/dev/null || source utilitaires.sh
#

# CONSTANTES
#
readonly NOTE="note.txt"
readonly JOURNAL="journal.txt"

# VARIABLES GLOBALES
#
# TIMEOUT
# TRACE

# DESCRIPTION
#
# Affiche le nom du test en cours d'exécution.
#
# USAGE
#
# CABexercice
#
CABexercice() {
    local nom="$(basename $0 .sh)"
    if [[ "${nom}" == "test" ]]; then
        nom="$(basename $(dirname $0))"
    fi
    nom="$(echo ${nom} | cut -d '-' -f 2-)"
    echo ${nom}
}

# DESCRIPTION
#
# Teste si une valeur est vide ou non spécifiée
#
# USAGE
#
# CABestVide VALEUR
#
CABestVide() {
    [[ -z "$@" ]] || [[ "$@" == "-" ]]
}

# DESCRIPTION
#
# Affiche la différence entre les deux répertoires spécifiés.
#
# USAGE
#
# CABdifference REPERTOIRE1 REPERTOIRE2
#
CABdiffArbos() {
    CABdiffEnsembles "$(find $1 -printf '%P ')" "$(find $2 -printf '%P ')"
}

# DESCRIPTION
#
# Affiche la différence entre les deux ensembles spécifiés.
#
# USAGE
#
# CABdifference ENSEMBLE1 ENSEMBLE2
#
CABdiffEnsembles() {
    for element in $1; do
        if [[ ! $2 =~ ${element} ]]; then
            echo ${element}
        fi
    done
}

# DESCRIPTION
#
# Met à jour la note en fonction de l'action spécifiée puis l'affiche.
#
# USAGE
#
# CABnoter ACTION?
#
CABnoter() {

    local note

    if [[ -z "$1" ]]; then
        note=0
    elif [[ "$1" == "%" ]]; then # si '%' final
        note="$(cat "${NOTE}")"
        ((note < 0)) && note="0"
        ((note > 100)) && note="100"
        note="${note}%"
    elif grep -qe [a-Z] <<< "$1"; then # message d'erreur final
        note="$*"
    else
        note="$(cat "${NOTE}")"
        ((note += $1))
    fi

    echo "${note}" >"${NOTE}"
    echo "${note}"

}

# DESCRIPTION
#
# Ecrit ses paramètres dans le fichier journal, précédés d'un horodatage.
#
CABjournaliser() {
    echo "$(date "+%H:%M.%S")" "$@" >>"${JOURNAL}"
}

# DESCRIPTION
#
# Initialise l'environnement de test, en créant un sous-répertoire propre, en
# y copiant les fichiers spécifiés et en initialisant la note à 0.
#
# USAGE
#
# CABinitier FICHIER+
#
CABinitier() {

    local fichiers="$*"

    # détuire et recréer l'espace de test
    local repertoire=".${EXERCICE}"
    rm -fr "${repertoire}" &>/dev/null
    mkdir  "${repertoire}" &>/dev/null

    # y copier les fichiers de travail spécifiés
    cp -fp ${fichiers} "${repertoire}" &>/dev/null

    # descendre dans le repertoire pour toute la suite du test
    cd "${repertoire}"

    # initialiser la note et le fichier note
    CABnoter &>/dev/null

    # vérifier la présence de l'exercice
    if [[ ! -f "$1" ]]; then
        CABterminer "fichier absent" 5
    fi
    if cmp "../../Sujet/$1" "$1" &>/dev/null; then
        CABterminer "fichier sujet" 4
    fi

}

# DESCRIPTION
#
# Compile les fichiers sources spécifiés avec toutes les options requises, et
# génère un exécutable dont le nom est celui du premier source sans l'extension
# .c.
#
# USAGE
#
# CABcompiler SOURCE+
#
CABcompiler() {

    local sources="$*"

    local executable="$(basename $1 .c)"
    local options="-Wall -Wextra -Werror -pedantic -g" # -fsanitize=address
    gcc $options -o "$executable" $sources &>gcc.out

    if [ ! -x "$executable" ]; then
        CABterminer "compile pas" 2
    else
        rm -f gcc.out
    fi

}

# DESCRIPTION
#
# Effectue la vérification spécifiée, ajoute si besoin les points spécifiés
# à la note, et journalise l'opération, accompagnée du message spécifié.
#
# La vérification est spécifiée sous forme de chaine de caractères, exécutée
# via la fonction eval. Si la vérification n'est pas un test [[ ... ]] ou une
# une expression (( ... )), son exécution est limitée en durée via la commande
# timeout. Si la vérification réussit (statut d'exécution 0) :
# - les points sont ajoutés à la note s'ils sont positifs ou nuls
# - les points ne sont pas retirés de la note s'ils sont négatifs
# Si la vérification échoue (statut d'exécution non 0) :
# - les points ne sont pas ajoutés à la note s'ils sont positifs ou nuls
# - les points sont retirés de la note s'ils sont négatifs
#
# Le message journalisé a le format suivant :
# <horodatage> <statut> <variation> <description> <statut> [message] 
#
# statut : "OK" si la vérification réussit, "NOK" sinon
# variation : "+/-points" si la note est modifiée, "(+/-points)" sinon
# description : celle fournie en argument, ou la vérification effectuée si vide
# messageNOK : celui fourni en argument, ajouté si la vérification échoue
#
# USAGE
#
# CABverifier POINTS DESCRIPTION VERIFICATION MESSAGE
#
CABverifier() {

    local points="$1"
    local description="$2"
    local verification="$3"
    local messageNOK="$4"

    # executer le verification
    if echo "${verification}" | grep -qe '^\[\[\|^(('; then
        eval "${verification}"
    else
        eval "timeout -k 1s ${TIMEOUT:-1s} ${verification}" &>/dev/null
    fi
    local retour="$?"

    [[ -n "$TRACES" ]] && echo "CABverifier \$verification=${verification}, \$retour=${retour}"

    # établir le statut
    local statut
    ((retour == 0)) && statut="OK " || statut="NOK"

    # établir la variation
    local variation
    if (( (retour == 0) == (points >= 0) )) then
        CABnoter ${points} &>/dev/null
        variation=" $(printf '%+0.2d' ${points}) "
    else
        variation="($(printf '%+0.2d' ${points}))"
    fi

    # établir la description
    CABestVide "${description}" && description="${verification}"

    # établir la conclusion
    local conclusion=""
    if (( retour == 0 )) then
        conclusion="OK"
    else
        conclusion="NOK${messageNOK}"
    fi

    # journaliser le verification, sauf si 
    # verification à points négatifs réussie (pour ne pas compliquer le journal)
    if ! ((retour == 0 && points < 0)) then
        CABjournaliser "${statut}" "${variation}" "${description}" "${conclusion}"
    fi
}

# DESCRIPTION
#
# Exécute une commande de préparation des tests et journalise l'opération.
#
CABpreparer() {

    local commande="$1"
    shift
    local message="$@"

    if [[ "$commande" == "-" ]]; then
        commande=""
    fi
    if [[ "$i{commande}" != "-" ]]; then
        eval "${commande}" &>/dev/null
    fi

    CABjournaliser $commande $message

}

# DESCRIPTION
#
# Exécute la commande spécifiée, mémorise son statut d'exécution et les
# messages produits sur stdout et stderr respectivement dans les fichiers
# .stat, .out et .err.
#
CABexecuter() {

    local message="$1"
    shift
    ! CABestVide ${message} && CABjournaliser ${message}
    

    [[ -n "${TRACES}" ]] && echo "CABexecuter ($#) $@"

    timeout -k 1s ${TIMEOUT:-1s} "$@" >.out 2>.err
    echo $? >.stat

    [[ -n "${TRACES}" ]] && echo "CABexecuter \$?=$? out=$(cat .out) err=$(cat .err)"

}

# DESCRIPTION
#
# Execute une suite de jeux de tests.
#
# USAGE
#
# CABjouer PROGRAMME PARAMETRES JEU...
#
CABjouer() {
    
    local programme="$1"
    local verification="$2"
    local parametres="$3"
    shift
    shift
    shift
    local note=$((100 / $#))

    [[ -n "${TRACES}" ]] && echo CABjouer jeux="$@"

    # pour chaque jeu...
    for jeu in "$@"; do
        
        # extraire entrées et attendu
        # et remplacer les ~ par espace
        local entrees="$(cut -d= -f1 <<< ${jeu})"
        #entrees="${entrees//\~/ }" : plus besoin avec les tableaux : chaque element est entre " " et peut contenir des espaces 
        local attendu="$(cut -d= -f2 <<< ${jeu})"
        #attendu="${attendu//\~/ }"
        # remplacer les \n par ~
        #attendu="${attendu//\n/\~}" : pas utile, suffit de pas les interpréter

        [[ -n "${TRACES}" ]] && echo "CABjouer \$entrees=${entrees}, \$attendu=${attendu}\$" 

        # exécuter avec timeout le programme sur les entrées (\n interprétés)
        # et mettre à plat la sortie standard (\n convertis en espaces)
        local obtenu="$(timeout -k 1s ${TIMEOUT:-1s} bash -c "(echo -e \"${entrees}\" | ${programme})")"
        #local obtenu="$(timeout -k 1s ${TIMEOUT:-1s} bash -c "(echo -e \"${entrees}\" | ${programme} | tr '\n' ' ')")"
        # remplacer les \n par ~
        # obtenu="${obtenu//\n/\~}" : pas utile, suffit de pas les interpreter

        [[ -n "${TRACES}" ]] && echo "CABjouer \$obtenu=${obtenu}\$"

        # vérifier que ce qui est obtenu correspond aux attendu
        # attendues, incluant l'espace final, traduction du \n final
        CABverifier ${note} \
            "${parametres} = ${entrees} => ${attendu} ?" \
            "${verification} ${obtenu} ${attendu}" \
            ", obtenu : \"${obtenu}\")"
    done

            #"echo \"${obtenu}\" | grep -qie \"${attendu} $\"" \
}

# DESCRIPTION
#
# Termine le test en affichant note et en retournant le statut d'exécution
# optionnel s'il est spécifié ou 0 ou 1 selon que la note est 100 ou non.
#
# USAGE
#
# CABterminer [ERREUR STATUT]?
#
CABterminer() {

    local erreur="$1"
    local statut="$2"

    if [[ -n "${erreur}" ]]; then
        note="$(CABnoter "${erreur}")"
    else
        note="$(CABnoter %)"
        [[ "${note}" == "100%" ]] && statut=0 || statut=1
    fi

    echo "${EXERCICE} : ${note}"
    exit ${statut}

}

#
# Programme principal
#

# calcul de EXERCICE
if [[ -n "$1" ]]; then
    EXERCICE="$1"
else
    EXERCICE="$(basename $0 .sh)"
    if [[ "${EXERCICE}" == "test" ]]; then
        EXERCICE="$(basename $(dirname $0))"
    fi
    EXERCICE="$(echo ${EXERCICE} | cut -d '-' -f 2-)"
fi

