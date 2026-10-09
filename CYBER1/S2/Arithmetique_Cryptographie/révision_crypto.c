#include <stdbool.h>

int PGCD (int a, int b){
    int reste;
    while (b != 0){
        reste= a%b;
        a=b;
        b=reste;
    }
    return a;
}

bool estPremier(int a){
    for (int i =2; i<a; i++){
        if (a%i==0){
            return false;
        }
    }
    return true;
}