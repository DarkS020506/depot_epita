#include <stdio.h>
#include <stdlib.h>

struct liste_p{
    int valeur;
    struct liste_p * next;
};

int size(struct liste_p *first){
    struct liste_p *current=first;
    int n=0;

    while (current != NULL){
        current=current->next;
        n++;
    }
    return n;
}

struct liste_p *getElement(struct liste_p * first, int pos){
    struct liste_p * current = first;
    int n=0;

    while (current != NULL && n < pos){
        current=current->next;
        n++;
    }

    return current;
}

struct liste_p *getElement_recursif(struct liste_p * current, int pos){
    if (current == NULL || pos==0){
        return current;
    }else{
        return getElement_recursif(current->next, pos-1);
    }
}

struct liste_p* searchElement(struct liste_p*first,int value){
    struct liste_p *current=first;
    while (current != NULL && current->valeur != value){
        current=current->next;
    }
    return current;
}

struct liste_p* searchElement_recurssif(struct liste_p*current,int value){
    if (current == NULL || current->valeur == value){
        return current;
    }else{
        return searchElement(current->next,value);
    }
}

struct liste_p* addElement(struct liste_p* first, int value, int pos){
    struct liste_p *nv_element=malloc(sizeof(struct liste_p));
    if (nv_element == NULL){
        return NULL;
    }
    nv_element->valeur=value;
    nv_element->next=NULL;

    if (pos==0){
        nv_element->next=first;
        return nv_element;

    }else if (pos >= size(first)){
        struct liste_p * current=first;
        while (current->next!=NULL){
            current=current->next;
        }
        current->next=nv_element;
        return first;

    }else{
        struct liste_p * current=first;
        for (int i=0; i<pos-1; i++){
            current=current->next;
        }
        nv_element->next=current->next;
        current->next=nv_element;
        return first;
    }
}

struct liste_p* delete_element(struct liste_p* first, int pos) {
    if (first==NULL || pos<0)
        return first;

    if (pos == 0) {
        struct liste_p* temp=first->next;
        free(first);
        return temp;
    }

    struct liste_p* current=first;

    for (int i=0; i<pos-1; i++){
        if (current->next == NULL)
            return first;
        current=current->next;
    }

    if (current->next==NULL)
        return first;

    struct liste_p* temp=current->next;
    current->next=temp->next;
    free(temp);

    return first;
}


int main(){
    struct liste_p first;
    first.valeur=13;
    first.next=NULL;

    struct liste_p second;
    second.valeur=7;
    second.next=NULL;
    first.next=&second;

    struct liste_p third;
    third.valeur=3;
    third.next=NULL;
    second.next=&third;

    int n=size(&first);
    printf("size: %d",n);

    printf("\n");
    struct liste_p *listeP=getElement_recursif(&first, 2);
    printf("valeur de l'element : %d", listeP->valeur);

    printf("\n");
    struct liste_p *listeP2=searchElement(&first, 7);
    printf("endroid de l'element : %d", listeP2->valeur);

    printf("\n");
    struct liste_p *listeP3=searchElement_recurssif(&first, 7);
    printf("endroid de l'element : %d", listeP3->valeur);

}