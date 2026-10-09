#include <stdio.h>
#include <stdlib.h>

int * createArray (int size );
int * doubleA (int * tab , int size );
int * append (int * tabP , int size , int value );
struct account createAccount (int id , char role );
int getID ( struct account myAccount );
void setID ( struct account * myAccountP , int newID );
struct student createDefault ();
void entrerNote ( struct student * myStudent );
char ** split ( char * mot);

int * createArray (int size ){
    int *tabs;
    tabs=(int *)malloc(size*sizeof(int));
    if (tabs==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tabs[i]=0;
    }
    return tabs;
}

int * doubleA (int * tab , int size ){
    int *tabs;
    tabs=malloc(size*sizeof(int));
    if (tabs==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tabs[i]=tab[i]*2;
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
    return tab;
}

struct account{
    int id;
    int role;
};
struct account createAccount (int id , char role ){
    struct account nv_compte;
    nv_compte.id=id;
    nv_compte.role=role;
    return nv_compte;
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
    struct student classic;
    classic.notesC=3;
    classic.nom=malloc(sizeof("John Doe"));
    classic.nom="John Doe\0";
    classic.notes=malloc(classic.notesC*sizeof(int));
    for (int i=0; i<classic.notesC; i++){
        classic.notes[i]=10;
    }
    return classic;
}
void entrerNote ( struct student * myStudent ){
    myStudent->notes=malloc(myStudent->notesC*sizeof(int));
    for (int i=0; i<myStudent->notesC; i++){
        int note;
        printf("entrer la note: ");
        scanf("%d",&note);
        myStudent->notes[i]=note;
    }
}

char ** split ( char * mot){
    int **tableau;
    tableau=malloc(100*sizeof(char));
    int i=0;
    int y=0;
    while (*mot!='\0'){
        if (*mot==' '){
            int j=0;
            while (mot[i]!=' ' && mot[i]!='\0'){
                tableau[y][j]=mot[i];
                i++;
                j++;
            }
            tableau[y][j]='\0';
            i++;
        }else{
            i++;
        }
    }
    tableau[y]=NULL;
    return tableau;
}

int main(){

}