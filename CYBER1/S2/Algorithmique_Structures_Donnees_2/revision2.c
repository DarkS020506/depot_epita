struct maillon{
    int entier;
    struct maillon * next;
};

int isEmpty(struct maillon * tete){
    if (tete==NULL){
        return 1;
    }
    return 0;
}

int LengthList (struct maillon * tete){
    int taille=0;
    while (tete!=NULL){
        taille ++;
        tete=tete->next;
    }
    return taille;
}

struct maillon insert_list(struct maillon * tete, int key, int pos){
    if (pos<0){
        return NULL;
    }
    struct maillon * nouveau=malloc(sizeof(struct maillon));
    if (nouveau==NULL){
        return NULL;
    }
    nouveau->entier=key;
    nouveau->next=NULL;
    if (pos==1 || tete==NULL){
        nouveau->next=tete;
        return nouveau;
    }
    struct maillon * current=tete;
    struct maillon * precedent=NULL;
    int position=1;
    while (current!=NULL && pos!=position){
        precedent=current;
        current=current->next;
        position++;
    }
    nouveau->next=current;
    precedent->next=current;
    return tete;

}

struct maillon *push(struct maillon *tete, int element){
    struct maillon *nouveau=malloc(sizeof(struct maillon));
    nouveau->entier=element;
    nouveau->next=NULL;
    if (tete==NULL){
        return nouveau;
    }
    tete = instert_list(tete, 1);
    return tete;
}

struct maillon *pop(struct maillon *tete, int element){
    if (tete==NULL){
        return NULL;
    } 
    struct maillon * p = remove_list(tete, 1);
    return tete
}



