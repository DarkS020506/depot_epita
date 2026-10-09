#!/usr/bin/env bash

# NOM
# 
# CAButilitaires.sh - bibliothèque de fonctions facilitant l'écriture des scripts de test
#
# SYNOPSIS
#
# source un/chemin/utilitaires.sh 2>/dev/null || source utilitaires.sh
#

# CONSTANTES
#
readonly FICHIER_NOTE="note.txt"
readonly FICHIER_JOURNAL="journal.txt"

# VARIABLES GLOBALES
#
# TIMEOUT
# TRACE

# NOM
#
# CABestVide - Teste si une valeur est vide ou non spécifiée
#
# SYNOPSIS
#
# CABestVide VALEUR
#
CABestVide() {
    [[ -z "$@" ]] || [[ "$@" == "-" ]]
}

# NOM
#
# CABdiffArbos - Affiche la différence entre les deux répertoires spécifiés.
#
# SYNOPSIS
#
# CABdifference REPERTOIRE1 REPERTOIRE2
#
CABdiffArbos() {
    CABdiffEnsembles "$(find $1 -printf '%P ')" "$(find $2 -printf '%P ')"
}

# NOM
#
# CABdifference - Affiche la différence entre les deux ensembles spécifiés.
#
# SYNOPSIS
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

# NOM
#
# CABexercice - Affiche le nom de l'exercice en cours de test
#
# SYNOPSIS
#
# CABexercice
#
CABexercice() {
    echo "${EXERCICE}"
    return

    #local nom="$(basename $0 .sh)"
    #if [[ "${nom}" == "test" ]]; then
        #nom="$(basename $(dirname $0))"
    #fi
    #nom="$(echo ${nom} | cut -d '-' -f 2-)"
    #echo ${nom}
}

# NOM
#
# CABnoter - Met à jour la note et l'affiche
#
# SYNOPSIS
#
# CABnoter DELTA [ACTION]
#
# DESCRIPTIF
#
# Si le fichier note n'existe pas déjà, le crée et initialise la note à O. Applique à
# la note le DELTA spécifié s'il n'est pas 0. 
# Si ACTION est l'une des valeurs suivantes :
# - % : ajuste la note courante dans l'intervalle [0, 100] et ajoute un % final,
# - une chaine autre : remplace la note par la chaine dans le fichier.
# Affiche le contenu du fichier note. 
#
CABnoter() {

    local delta="$1"
    local action="$2"
    local note
    

    # lit la note du fichier s'il existe, le crée avec 0 sinon
    if [ -e "${FICHIER_NOTE}" ]; then
        note="$(cat "${FICHIER_NOTE}")"
    else
        echo "0" > "${FICHIER_NOTE}"
        note=0
    fi

    # si l'action est % final
    if [[ "${action}" == "%" ]]; then
        # ajuster la note et conclure
        ((note < 0)) && note="0"
        ((note > 100)) && note="100"
        note="${note}%"
    # si l'action est un message
    elif [[ -n "${action}" ]]; then
        # le mettre en guise de note
        note="${action}"
    # sinon ajouter le delta
    else
        ((note += delta))
    fi

    # mettre à jour le fichier note et afficher la note
    echo "${note}" > "${FICHIER_NOTE}"
    echo "${note}"

}

# NOM
#
# CABjournaliser - Ecrit un message dans le journal, précédé de l'heure
#
# SYNOPSIS
# 
# CABjournaliser [MOT]...
#
CABjournaliser() {
    echo "$(date "+%H:%M.%S")" "$@" >> "${FICHIER_JOURNAL}"
}

# NOM
#
# CABinitier - Initialise l'environnement de test
#
# SYNOPSIS
#
# CABinitier [FICHIER]...
#
# DESCRTIPTION
#
# Initialise l'environnement de test, en créant un sous-répertoire propre, en
# y copiant les fichiers spécifiés.
#
CABinitier() {

    local fichiers="$*"

    # détuire et recréer le répertoire de test
    local repertoire=".$(CABexercice)"
    rm -fr "${repertoire}" &>/dev/null
    mkdir  "${repertoire}" &>/dev/null

    # y copier les fichiers de travail spécifiés
    cp -fp ${fichiers} "${repertoire}" &>/dev/null

    # descendre dans le repertoire pour toute la suite du test
    cd "${repertoire}"

    # vérifier la présence de l'exercice
    if [[ ! -f "$1" ]]; then
        CABterminer "fichier absent" 5
    fi
    if cmp "../../Sujet/$1" "$1" &>/dev/null; then
        CABterminer "fichier sujet" 4
    fi

}

# NOM
#
# CABcompiler - Compile des fichiers .c en un exécutable
#
# SYNOPSIS
#
# CABcompiler SOURCE...
#
# DESCRIPTION
#
# Compile les fichiers sources spécifiés avec les options requises :
# -Wall -Wextra -Werror -pedantic -g
# et génère un exécutable dont le nom est celui du premier source 
# sans l'extension .c.
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

# NOM
#
# CABverifier - Effectue une vérification, la consigne dans le journal et ajuste la note
#
# SYNOPSIS
#
# CABverifier POINTS DESCRIPTION VERIFICATION [MESSAGENOK]
#
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
# <horodatage> <statut> <variation> <description> <statut>[messageiNOK] 
#
# statut : "OK" si la vérification réussit, "NOK" sinon
# variation : "+/-points" si la note est modifiée, "(+/-points)" sinon
# description : celle fournie en argument, ou la vérification effectuée si vide
# messageNOK : celui fourni en argument, ajouté si la vérification échoue
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
    # verification à points négatifs réussie (pour ne pas surcharger le journal)
    if ! ((retour == 0 && points < 0)) then
        CABjournaliser "${statut}" "${variation}" "${description}" "${conclusion}"
    fi
}

# NOM
#
# CABpreparer - Exécute une commande de préparation des tests et journalise l'opération.
#
# SYNOPSIS
#
# CABpreparer COMMANDE [MESSAGE]...
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

# NOM
#
# CABexecuter - Exécute une commandei, recueille ses stdout, stderr et statut d'exécution et journalise l'opération.
#
# SYNOPSIS
#
# CABexecuter MESSAGE COMMANDE [ARGUMENT]...
#
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

# NOM
#
# CABjouer - Execute une suite de jeux de tests.
#
# SYNOPSIS
#
# CABjouer PROGRAMME PARAMETRES JEU...
#
# !DEPRECATED!
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

# NOM
#
# CABterminer - Termine l'exécution du test en cours
#
# SYNOPSIS
#
# CABterminer [ERREUR STATUT]
#
# DESCRIPTION 
#
# Sans argument, termine le test en affichant note. Le statut d'exécution est 0 si
# la note est 100% et 1 sinon. 
# Avec arguments, termine le test en consignant l'erreur dans le fichier note et 
# en l'affichant. Le statut d'exécution est celui spécifié.
#
CABterminer() {

    local erreur="$1"
    local statut="$2"

    if [[ -z "${erreur}" ]]; then
        note="$(CABnoter - %)"
        [[ "${note}" == "100%" ]] && statut=0 || statut=1
    else
        note="$(CABnoter - "${erreur}")"
    fi

    echo "$(CABexercice) : ${note}"
    exit ${statut}

}

#
# PROGRAMME PRINCIPAL
#

# calcul de EXERCICE
if [[ -z "$1" ]]; then
    echo "nom exercice non spécifié" 1>&2
    exit 1
fi
EXERCICE="$1"

