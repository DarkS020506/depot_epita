struct maillon{
    int entiers;
    struct maillon *next;
};

int isEmpty(struct maillon *tete){
    if (tete == NULL){
        return 1;
    }
    return 0;
}

int LengthList(struct maillon *tete){
    if (tete == NULL){
        return 0;
    }
    int taille=0;
    while (tete!=NULL){
        taille++;
        tete=tete->next;
    }
    return taille;
}

struct maillon *insert_list(struct maillon *tete, int elt, int pos) {
    if (elt < 0) {
        return NULL; 
    }
    struct maillon *nouveau = malloc(sizeof(struct maillon));
    if (nouveau == NULL) return tete;
    nouveau->entiers = elt;
    nouveau->next = NULL;
    if (tete == NULL || pos <= 1) {
        nouveau->next = tete;
        return nouveau;
    }
    struct maillon *current = tete;
    struct maillon *precedent = NULL;
    int index_actuel = 1;
    while (current != NULL && index_actuel < pos) {
        precedent = current;
        current = current->next;
        index_actuel++;
    }
    nouveau->next = current; 
    precedent->next = nouveau;

    return tete;
}

struct maillon *push(struct maillon *tete, int element){
    if (tete==NULL){
        return NULL;
    }
    tete = insert_list(tete, element, 1);
    return tete;
}

struct maillon *pop(struct maillon *tete, int element){
    if (tete==NULL){
        return NULL;
    }
    tete= remove_liste(tete, 1);
    return tete;
}



struct node{
    int key;
    struct node* fils_gauche;
    struct ndoe* fils_droit;
};

struct node* parc_prof_rec(struct node* tete){
    if (tete->fils_gauche!=NULL){
        parc_prof_rec(tete->fils_gauche);
    }
    if (tete->fils_droit!=NULL){
        parc_prof_rec(tete->fils_droit);
    }
    printf("%d",tete->key);
}

struct node* parc_larg_iter(struct node* tete){
    if (tete==NULL){
        return NULL;
    }
    queue_p file=create();
    enqueue(file, tete);
    while(isEmpty(file)!=1){   
        struct node *debut=dequeue(file);
        printf("%d", debut->key);
        
        if (debut->fils_gauche!=NULL){
            enqueue(file, debut->gauche);
        }
        if (debut->fils_droite!=NULL){
            enqueue(file, debut->droite);
        }
        free(debut);


    }
    Delete(file);
    return tete;

}

void TreeToArray(struct node* racine, int* tableau, int taille, int indice_actuel) {
    if (racine == NULL || indice_actuel > taille) {
        return;
    }
    tableau[indice_actuel - 1] = racine->key;
    if (racine->fils_gauche != NULL) {
        TreeToArray(racine->fils_gauche, tableau, taille, 2 * indice_actuel);
    }
    if (racine->fils_droit != NULL) {
        TreeToArray(racine->fils_droit, tableau, taille, 2 * indice_actuel + 1);
    }
}