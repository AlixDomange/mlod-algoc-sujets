#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5



void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]){
    for(int j=0; j<SIZE; j++){
        for(int i=0; i<SIZE; i++){
            int64_t somme = 0;
            for(int k=0; k<SIZE;k++){
                somme+=matrice1[i][k]*matrice2[k][j];
            }
            matriceResultat[i][j]=somme; //matriceResultat est un variable du main
        }
    } 
}


void matrix_print( int64_t matrice[][SIZE]){
    for(int j=0; j<SIZE; j++){
        for(int i=0; i<SIZE; i++){
            printf( "%"PRId64" ", matrice[i][j]); //printf spécifie le format de la donnée pour l'afficher
        }
        printf("\n");
    }
}

int main(void) {
//matrices en ligne * colonne
int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[SIZE][SIZE]; //on précise les 2 tailles car la matrice n'est pas initialisée
matrix_mult(matriceResultat,matrice1,matrice2); // matriceResultat = adresse de la première case
matrix_print(matriceResultat);
return EXIT_SUCCESS;
}