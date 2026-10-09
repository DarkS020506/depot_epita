#include <stdio.h>
#include <stdlib.h>

int * createArray(int size);
int * doubleA(int * tab, int size);
int * append(int * tabP, int size, int value);

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

int * doubleA(int * tab, int size){
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

int * append(int * tabP, int size, int value){
    int *tab2;
    tab2=(int *)malloc((size+1)*sizeof(int));
    if (tab2==NULL){
        return NULL;
    }
    for (int i=0; i<size; i++){
        tab2[i]=tabP[i];
    }
    tab2[size]=value;
    return tab2;
}


int main(){
    
    return 0;
}