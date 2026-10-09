#include <stdio.h>

void affichageP(int *p){
    printf("Valeur : %d \n Adresse : %p\n", p,*p);
}

int sommeP(int *pA, int *pB){
    return *pA+*pB;
}

void swapP(int *pA, int *pB){
    int *temp=pB;
    printf("pa : %p\npb : %p",pA,pB);
    pB=pA;
    pA=temp;
    printf("\npa : %p\npb: %p",pA,pB); 
}

int *maxP(int *pA, int *pB, int *pC){
    if (*pA>*pB && *pA>*pC){
        return pA;
    }else if (*pB>*pA && *pB>*pA){
        return pB;
    }else{
        return pC;
    }
    
}

int searchValueP(int *pI, int n, int value){
    for (int i=0; i<n; i++){
        if (*pI==value){
            return 1;
        }
        pI++;
    }
    return 0;
}

int searchCarP(char* pS, char car){
    while (*pS!="\0"){
        if (*pS==car){
            return 0;
        }
        pS++;
    }
    return 0;
}

char *deleteHalf(char *mot){
    static char nv_mot[100];
    int i=0;
    int j=0;
    while (*mot != '\0'){
        if (i%2==0){
            nv_mot[j]=*mot;
            j++;
            mot++;
            i++;
        }else{
            nv_mot[j]='_';
            j++;
            mot++;
            i++;
        } 
    }
    nv_mot[j]='\0';
    return nv_mot;
}
int main(){
    int valeur=5;
    int *adresse=&valeur;
    affichageP(adresse);

    int a= 2;
    int b=5;
    int somme=sommeP(&a,&b);
    printf("\n%d\n",somme);

    swapP(&a,&b);

    a=2;
    b=9;
    int c=5;
    int *max=maxP(&a,&b,&c);
    printf("\n%d\n",max);

    int tab[] = {1,2,3};
    int existe=searchValueP(tab,3,9);
    printf("\n%d\n",existe);

    char s[] = "bonjour";
    printf("%d\n", searchCarP(s, 'j'));
    printf("%d\n", searchCarP(s, 'z'));

    char mot[] = "bonjour";
    char *result = deleteHalf(mot);
    printf("%s\n", result); // affiche "bnoo"
    return 0;
}