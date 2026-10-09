#!/usr/bin/env bash

# DESCRIPTION
#
# Fonctions facilitant l'écriture des scripts de test.
#
# USAGE
#
# source ./utilitaires.sh 2>/dev/null || source un/chemin/utilitaires.sh 2>/dev/null || source utilitaires.sh
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
# CABnomTest
#
CABnomTest() {
    local nom="$(basename $0 .sh)"
    if [[ "${nom}" == "test" ]]; then
        nom="$(basename $(dirname $0))"
    fi
    nom="$(echo ${nom} | cut -d '-' -f 2-)"
    echo ${nom}
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
    local repertoire=".$(CABnomTest)"
    rm -fr "${repertoire}" >/dev/null 2>&1 # TODO erreur VBox à investiguer
    mkdir "${repertoire}" >/dev/null 2>&1  # TODO erreur VBox à investiguer

    # y copier les fichiers de travail spécifiés
    cp -fp ${fichiers} "${repertoire}" >/dev/null 2>&1

    # descendre dans le repertoire pour le reste du test
    cd "${repertoire}"

    # initialiser la note et le fichier note
    CABnoter >/dev/null 2>&1

    # vérifier la présence de l'exercice
    if [[ ! -f "$1" ]]; then
        CABterminer "fichier absent" 5
    fi
    if diff "../../Sujet/$1" "$1" >/dev/null 2>&1; then
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

    sources="$*"

    executable="$(basename $1 .c)"
    options="-Wall -Wextra -pedantic -g" # -fsanitize=address
    gcc $options -o "$executable" $sources >gcc.out 2>gcc.err

    if [ ! -x "$executable" ]; then
        CABterminer "compile pas" 2
    fi

    # cause problème mise à jour note : constaté
    # car passe en négatif ? : à vérifier
    # plus : ce n'est pas une bonne idée en cas de double compilation
    # CABverifier "[ -n \"$(cat gcc.err)\" ]" -25 "compile avec avertissements"

}

# DESCRIPTION
#
# Met à jour la note en fonction de l'action spécifiée puis l'affiche.
#
# USAGE
#
# note ACTION?
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
    elif grep -e [a-Z] <<< "$1" >/dev/null; then # message d'erreur final
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
# Exécute le test spécifié, ajoute si nécessaire les points spécifiés
# à la note, et journalise l'opération, accompagnée du message spécifié.
#
# La vérification consiste en une commande à exécuter, que la fonction exécute
# avec eval. La vérification est considérée comme réussie si le statut d'
# exécution de la commande est 0, et comme *échouée* sinon.
# Si la vérification est réussie :
# - les points sont ajoutés à la note s'ils sont positifs ou nuls
# - les points ne sont pas retirés de la note s'ils sont négatifs
# Si vérifcation est échouée :
# - les points ne sont pas ajoutés à la note s'ils sont positifs
# - les points sont retirés de la note s'ils sont négatifs
#
# Le message journalisé a le format suivant :
# <statut> <variation> <message> [conclusion]
#
# statut : "OK" si statut exécution commande est 0, "NOK" sinon
# variation : "+/-points" si note modifiée (en + ou en -), "(+/-points)" sinon
# message : message fourni en paramètre ou commande exécutée sinon
# conclusion : ": faux" si commande en échec
#
# USAGE
#
# CABverifier COMMANDE POINTS MESSAGE
#
CABverifier() {

    local points="$1"
    local descriptif="$2"
    local test="$3"
    local resultat="$4"

    # excuter le test
    eval "${test}" >/dev/null 2>&1
    local retour="$?"

    # établir le statut
    local statut
    ((retour == 0)) && statut="OK " || statut="NOK"

    # établir la variation
    local variation
    if (((retour == 0) == (points >= 0))); then
        CABnoter ${points} >/dev/null 2>&1
        variation=" $(printf '%+d' ${points}) "
    else
        variation="($(printf '%+d' ${points}))"
    fi

    # établir la descriptif
    CABestVide "${descriptif}" && descriptif="${test}"

    # établir la conclusion
    local conclusion=""
    if ((retour == 0)); then
        conclusion="OK"
    else
        CABestVide "${resultat}" && conclusion="NOK" || conclusion="NOK, obtenu : ${resultat}"
    fi

    # CABjournaliser, sauf si test négatif réussi
    if ! ((retour == 0 && points < 0)); then
        CABjournaliser "${statut}" "${variation}" "${descriptif}" "${conclusion}"
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
    if [[ "$commande" != "-" ]]; then
        eval "$commande" >/dev/null 2>&1
    fi

    CABjournaliser $commande $message

}

# DESCRIPTION
#
# Ecrit ses paramètres dans le fichier journal, précédés d'un horodatage.
#
CABjournaliser() {
    echo -e "$(date "+%H:%M.%S")" "$@" >>"${JOURNAL}"
}

# DESCRIPTION
#
# Exécute la commande spécifiée, mémorise son statut d'exécution et les
# messages produits sur stdout et stderr.
#
CABexecuter() {

    # positionner le timeout si pas déjà fait
    [[ -z "${TIMEOUT}" ]] && TIMEOUT="3s"

    timeout -k 1s ${TIMEOUT} "$1" >test.out 2>test.err
    retour="$?"

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

    erreur="$1"
    statut="$2"

    if [ -n "${erreur}" ]; then
        note="$(CABnoter "${erreur}")"
    else
        note="$(CABnoter %)"
        [[ "${note}" == "100%" ]] && statut=0 || statut=1
    fi

    echo "$(CABnomTest) : ${note}"
    exit ${statut}

}

CABestVide() {
    [[ -z "$@" ]] || [[ "$@" == "-" ]]
}

CABnoteJeu() {
    echo $((100/$#)) 
}
