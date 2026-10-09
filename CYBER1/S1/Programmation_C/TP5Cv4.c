#include <stdio.h>
#include <stdlib.h>

int *createArray(int size){
    int *tabs;
    tabs=malloc(size*sizeof(int));
    if (tabs==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tabs[i]=0;
    }
    return tabs;
}

int * tripleA (int * tab , int size ){
    int *tabs;
    tabs=malloc(size*sizeof(int));
    if (tabs==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tabs[i]=tab[i]*3;
    }
    return tabs;
}

int * append (int * tabP , int size , int value ){
    int *tab;
    tab=malloc((size+1)*sizeof(int));
    if (tab==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tab[i]=tabP[i];
    }
    tab[size]=value;
    free(tabP);
    return tab;
}

struct account{
    int id;
    char role;
};

struct account createAccount(int id, char role){
    struct account nv_compte;
    nv_compte.id=id;
    nv_compte.role=role;
    return nv_compte;
}

char getRole ( struct account myAccount ){
    return myAccount.role;
}

void setRole ( struct account * myAccountP , char newRole ){
    myAccountP -> role=newRole;
}

struct student{
    int notesC;
    int *notes;
    char *nom;
};

struct student createDefault (){
    struct student basique;
    basique.notesC=3;
    basique.nom=malloc(sizeof("John Doe")+1);
    basique.nom="John Doe";
    basique.notes=(3*sizeof(int));
    for (int i=0; i<3;i++){
        basique.notes[i]=10;
    }
    return basique;
}
void entrerNote ( struct student * myStudent ){
    int nb_notes;
    printf("Entrer le nombre de note: ");
    scanf("%d", &nb_notes);
    if (myStudent->notesC!=NULL){
        free(myStudent->notesC);
    }
    myStudent->notesC=nb_notes;
    myStudent->notes=malloc(nb_notes*sizeof(int));
    for (int i=0; i<myStudent->notesC; i++){
        printf("Entrer la %d ème note: ",i+1);
        scanf("%d",&myStudent->notes[i]);
    }
}

