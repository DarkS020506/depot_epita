#!/bin/bash

# Script de réorganisation du dépôt git pour un portfolio étudiant en cyber
# Ce script crée une structure claire et professionnelle

set -e

cd /c/Users/sylva/Documents/depot_epita

echo "Début de la réorganisation du dépôt..."

# Étape 1: Créer la structure cible
mkdir -p CYBER1/S1/{Programmation_C,Systemes_Linux,Programmation_Python,Algorithmes,Projet}
mkdir -p CYBER1/S2/{Algorithmique,Arithmetique_Cryptographie,Bases_de_donnees,Developpement_Web,Administration_Linux,Securite,Projet}
mkdir -p PROJETS/{C,Python,Web,Systeme}

# Étape 2: Déplacer les fichiers de Epita/S1/C/ vers CYBER1/S1/Programmation_C/
echo "Déplacement des fichiers C de S1..."
if [ -d "Epita/S1/C" ]; then
    # Déplacer les dossiers TD et TP
    for dir in Epita/S1/C/TD*; do
        dirname=$(basename "$dir")
        cp -r "$dir" CYBER1/S1/Programmation_C/
    done
    for dir in Epita/S1/C/TP*; do
        dirname=$(basename "$dir")
        cp -r "$dir" CYBER1/S1/Programmation_C/
    done
    # Déplacer les fichiers PDF
    cp Epita/S1/C/*.pdf CYBER1/S1/Programmation_C/ 2>/dev/null || true
fi

# Étape 3: Déplacer les fichiers de Epita/S1/Linux/ vers CYBER1/S1/Systemes_Linux/
echo "Déplacement des fichiers Linux de S1..."
if [ -d "Epita/S1/Linux" ]; then
    for dir in Epita/S1/Linux/TD* Epita/S1/Linux/TP*; do
        dirname=$(basename "$dir")
        cp -r "$dir" CYBER1/S1/Systemes_Linux/
    done
fi

# Étape 4: Déplacer les fichiers de Epita/S1/Python/ vers CYBER1/S1/Programmation_Python/
echo "Déplacement des fichiers Python de S1..."
if [ -d "Epita/S1/Python" ]; then
    for dir in Epita/S1/Python/TP*; do
        dirname=$(basename "$dir")
        cp -r "$dir" CYBER1/S1/Programmation_Python/
    done
fi

# Étape 5: Déplacer les fichiers de Epita/S2/ vers CYBER1/S2/
echo "Déplacement des fichiers de S2..."
if [ -d "Epita/S2" ]; then
    # C
    if [ -d "Epita/S2/C" ]; then
        cp -r Epita/S2/C/* CYBER1/S2/Algorithmique/ 2>/dev/null || true
    fi
    
    # Administration Linux
    if [ -d "Epita/S2/Administration_linux" ]; then
        cp -r Epita/S2/Administration_linux/* CYBER1/S2/Administration_Linux/ 2>/dev/null || true
    fi
    
    # Sécurité Python
    if [ -d "Epita/S2/securite_python" ]; then
        # Copier mais exclure venv
        cp -r Epita/S2/securite_python/*.py CYBER1/S2/Securite/ 2>/dev/null || true
        cp -r Epita/S2/securite_python/my-scanner/*.py CYBER1/S2/Securite/my-scanner/ 2>/dev/null || true
    fi
fi

# Étape 6: Intégrer les fichiers pertinents de Desktop/
echo "Intégration des fichiers de Desktop..."
if [ -d "Desktop" ]; then
    # Scripts shell
    cp Desktop/*.sh CYBER1/S1/Systemes_Linux/ 2>/dev/null || true
    cp Desktop/*.c CYBER1/S1/Programmation_C/ 2>/dev/null || true
    
    # Fichiers finals
    if [ -d "Desktop/finals" ]; then
        cp -r Desktop/finals/* CYBER1/S1/Systemes_Linux/Finals/ 2>/dev/null || true
    fi
    if [ -d "Desktop/finals_C" ]; then
        cp -r Desktop/finals_C/* CYBER1/S1/Programmation_C/Finals/ 2>/dev/null || true
    fi
    if [ -d "Desktop/finals_linux" ]; then
        cp -r Desktop/finals_linux/* CYBER1/S1/Systemes_Linux/Finals/ 2>/dev/null || true
    fi
fi

# Étape 7: Intégrer S1-Python
echo "Intégration de S1-Python..."
if [ -d "S1-Python" ]; then
    for dir in S1-Python/TP*; do
        cp -r "$dir" CYBER1/S1/Programmation_Python/ 2>/dev/null || true
    done
fi

# Étape 8: Intégrer TP2
echo "Intégration de TP2..."
if [ -d "TP2" ]; then
    cp -r TP2/* CYBER1/S1/Programmation_Python/TP2_Extra/ 2>/dev/null || true
fi

echo "Copie des fichiers terminée. Vérifiez avant de supprimer l'ancien."
