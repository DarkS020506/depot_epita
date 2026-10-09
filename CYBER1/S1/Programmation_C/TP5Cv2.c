#include <stdlib.h>
#include <stdio.h>


int * createArray(int size);
int * doubleA(int *tab, int size);
int * append (int * tabP , int size , int value );
struct account createAccount (int id , char role );
int getID ( struct account myAccount );
void setID ( struct account * myAccountP , int newID );
struct student createDefault ();


int * createArray(int size){
    int *tab;
    tab=(int *)malloc(size*sizeof(int));
    if (tab==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tab[i]=0;
    }
    return tab;
}

int * doubleA(int *tab, int size){
    int *tab2;
    tab2=(int *)malloc(size*sizeof(int));
    if (tab2==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tab2[i]=tab[i]*2;
    }
    return tab2;
}

int * append (int * tabP , int size , int value ){
    int *tab;
    tab=(int *)malloc((size+1)*sizeof(int));
    if (tab==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tab[i]=tabP[i];
    }
    tab[size]=value;
    return tab;
}

struct account{
    int id;
    char role;
};

struct account createAccount (int id, char role){
    struct account nv_account;
    nv_account.id=id;
    nv_account.role=role;
    return nv_account;    
}

int getID ( struct account myAccount ){
    return myAccount.id;
}

void setID ( struct account * myAccountP , int newID ){
    myAccountP -> id=newID;
}


struct student{
    char *nom;
    int *notes;
    int notesC;
};
struct student createDefault (){
    struct student defaut;
    defaut.nom=malloc(sizeof("John Doe")+1);
    defaut.nom="John Doe\0";
    defaut.notesC=3;
    defaut.notes=malloc(defaut.notesC*sizeof(int));
    for (int i=0;i<3;i++){
        defaut.notes[i]=10;
    }
}

void entrerNote(struct student *myStudent) {
    printf("Entrer le nombre de notes : ");
    scanf("%d", &myStudent->notesC);
    myStudent->notes = malloc(myStudent->notesC * sizeof(int));
    if (myStudent->notes == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    for (int i = 0; i < myStudent->notesC; i++) {
        printf("Entrer la %dème note : ", i + 1);
        scanf("%d", &myStudent->notes[i]);
    }
}

char ** split ( char * mot){
    int *tableau;
    int *tab;
    int y=0;
    for (int i=0;i<1000;i++){
        if (mot[i]==" "){
            tableau[y]=tab;
            y+=1;
        }
        else{
            tab=mot[i];
        }
    }
    return tableau;
}

int main(){
    return 0;
}