#include <stdio.h>

int euclide(int a, int b){
    int reste=a%b;
    while (reste!=0){
        a=b;
        b=reste;
        reste=a%b;
    }  
    return b;
}

int euclide_recursif(int a, int b){
    if (a%b==0){
        return b;
    }
    else{
        euclide_recursif(b,a%b);
    }
}

int inverse (int a; int b){
    int mod = b;
    int r=a%b;
    int u_i2=1; int u_i1=0;
    int u_i=1;
    while (n!=1){
        u_i=u_i-(a/b)*u_i1;
        u_i2=u_i1;
        u_i1=u_i;
        r=a%b;
        a=b;
        b=r;
        if (u_i<0){
            u_i=(u_i%mod);
        }
        return u_i;
    }
}


int main(){
    int a=euclide(162,108);
    printf("resultat: %d",a);
    return 1;
}