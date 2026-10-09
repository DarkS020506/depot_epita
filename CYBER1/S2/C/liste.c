#ifndef LISTE_H
#define LISTE_H
#include <stdlib.h>
#include <string.h>

liste* creer(int capacite){
    liste* nv_liste = malloc(sizeof(liste));
    if (nv_liste == NULL) return NULL;
    nv_liste->taille = 0;
    nv_liste->capacite = capacite;
#ifdef IMPL_CHAINE
    nv_liste->tete = NULL; 
#else
    if (capacite > 0) {
        nv_liste->tableau = malloc(capacite * sizeof(char*));
        if (nv_liste->tableau == NULL) {
            free(nv_liste);
            return NULL;
        }
    } else {
        nv_liste->tableau = NULL;
    }
#endif
    return nv_liste;    
}

void supprimer(liste* liste){
    if (liste==NULL){
        return;
    }
#ifdef IMPL_CHAINE
    struct maillon* actuel=liste->tete;
    while(actuel!=NULL){
        struct maillon* a_supprimer=actuel;
        actuel = actuel->next;
        free(a_supprimer);
    }
#else
    if (liste->tableau!=NULL){
        free(liste->tableau);
    }
#endif
    free(liste);

}

int taille(const liste* liste){
    if (liste == NULL){
        return 0;
    }
#ifdef IMPL_CHAINE
    int taille_liste=0;
    struct maillon* current= liste->tete;
    while (current!=NULL){
        taille_liste++;
        current=current->next;
    }
    return taille_liste;
#else
    return liste->taille;
#endif
}

int estVide(const liste* liste){
    if (liste==NULL){
        return 0;
    }
    if (liste->taille==0){
        return 1;
    }
    return 0;
}

char* lire(const liste* liste, int position){
    if (liste == NULL || position < 0 || position >= liste->taille){
        return NULL;
    }
#ifdef IMPL_CHAINE
    struct maillon* actuel = liste->tete;
    int i=0;
    while (i<position){
        actuel=actuel->next;
        i++;
    }
    return actuel->text;
#else
    return liste->tableau[position];
#endif
}

int position(const liste* liste, const char* element){
    if (liste==NULL || element == NULL){
        return -1;
    }
#ifdef IMPL_CHAINE
    struct maillon* actuel= liste->tete;
    int index=0;
    while (actuel!=NULL){
        if (strcmp(actuel->text,element)==0){
            return index;
        }else{
            actuel=actuel->next;
            index++;
        }
    }
#else
    for (int i=0; i<liste->taille; i++){
        if (liste->tableau[i] != NULL && strcmp(liste->tableau[i], element) == 0){
            return i;
        }
    }
#endif
    return -1;
}

int contient(const liste* liste, const char* element){
    if (position(liste, element) >= 0){
        return 1;
    }
    return 0;
}


int ecrire(liste* liste, int position, const char* element){
    if (element == NULL || liste == NULL || position < 0 || position >= liste->taille){
        return 0;
    }
#ifdef IMPL_CHAINE
    struct maillon * actuel = liste->tete;
    for (int i=0; i<position; i++){
        actuel=actuel->next;
    }
    actuel->text=(char*)element;
#else
    liste->tableau[position]=(char*)element;
#endif
    return 1;
}

int ajouter(liste* liste, int position, const char* element){
    if (liste==NULL || element == NULL){
        return 0;
    }
    if (liste -> capacite >= 0 && liste -> taille >= liste -> capacite){
        return 0;
    }
    if (position == -1 || position > liste->taille) {
        position = liste->taille;
    }
    if (position <0){
        return 0;
    }
#ifdef IMPL_CHAINE
    struct maillon *nouveau=malloc(sizeof(struct maillon));
    if (nouveau==NULL){
        return 0;
    }
    nouveau->text=(char*)element;
    if (position==0){
        nouveau->next=liste->tete;
        liste->tete=nouveau;
    }else{
        struct maillon *prec=liste->tete;
        for (int i=0; i<position -1 ; i++){
            prec=prec->next;
        }
        nouveau->next=prec->next;
        prec->next=nouveau;
    }
#else
    for (int i =liste->taille; i> position ; i--){
        liste->tableau[i]=liste->tableau[i-1];
    }
    liste->tableau[position] = (char*)element;
#endif
    liste->taille++;
    return 1;
}

char* retirer(liste* liste, int position){
    if (liste == NULL || position < 0 || position >= liste -> taille){
        return NULL;
    }
    char * element_retire=NULL;
#ifdef IMPL_CHAINE
    struct maillon * a_supprimer=NULL;
    if (position == 0){
        a_supprimer = liste->tete;
        element_retire=a_supprimer->text;
        liste->tete=a_supprimer->next;
    }else{
        struct maillon* prec= liste->tete;
        for (int i=0; i<position-1; i++){
            prec=prec->next;
        }
        a_supprimer=prec->next;
        element_retire=a_supprimer->text;
        prec->next = a_supprimer->next;
    }
    free(a_supprimer);
#else
    element_retire=liste->tableau[position];
    for (int i=position; i< liste->taille-1; i++){
        liste->tableau[i]=liste->tableau[i+1];
    }
    liste->tableau[liste->taille-1]=NULL;
#endif
    liste->taille--;
    return element_retire;
}

void vider(liste* liste){
    if (liste==NULL){
        return;
    }
#ifdef IMPL_CHAINE
    struct maillon* actuel = liste->tete;
    while (actuel!=NULL){
        struct maillon* a_supprimer=actuel;
        actuel=actuel->next;
        free(a_supprimer);
    }
    liste->tete=NULL;
#else
    for (int i=0; i<liste->taille; i++){
        liste->tableau[i]=NULL;
    }
#endif
    liste->taille=0;
}