#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lettre_a_nombre(char lettre){
    char alphabet_min[] = "abcdefghijklmnopqrstuvwxyz";
    char alphabet_maj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        if (alphabet_min[i] == lettre) return i;
        if (alphabet_maj[i] == lettre) return i;
    }
    return -1; 
}

int nombre_a_lettre(int nombre){
    char liste_alphabet_min[]={"abcdefghijklmnopkrstuvwxyz"};
    return liste_alphabet_min[nombre];
}
int adapter_cle(char message_clair,char message_cle){
    if (strlen(message_clair)==strlen(message_cle)){
        return message_cle;
    }
    else if (strlen(message_cle)<=strlen(message_clair)){
        int taille=strlen(message_cle);
        for (int i=0;i<strlen(message_cle)-strlen(message_clair);i++){
            message_cle[taille++]=message_cle[i%strlen(message_clair)];
        return message_cle;
    }
    else{
        char *nv_message_cle[strlen(message_cle)<=strlen(message_clair)];
        int taille=0;
        for (int i=0;i<strlen(message_cle)-strlen(message_clair);i++){
            nv_message_cle[taille++]=message_cle[i%strlen(message_clair)];
        }
    }
}
}
int main(){
    return 0;
}