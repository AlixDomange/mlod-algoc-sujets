#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t, ...

typedef short TypeEntier;

TypeEntier factorielle(TypeEntier N){
    if (N==0 || N==1){
        return 1;
    }
    else{
        return N * factorielle(N-1);
    }
}

int main(){
    int n;
    printf("Entrez un nombre positif");
    scanf("%d", &n);

    if (n < 0) {
        printf("La factorielle n'est pas définie pour les nombres négatifs.\n");
    } else {
        printf("La factorielle est : %i \n", factorielle(n));
    }

    printf ("Size : %d", sizeof(TypeEntier));

    return 0;
}