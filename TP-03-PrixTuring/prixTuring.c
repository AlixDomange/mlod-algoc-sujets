/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "prixTuring.h"

int numberOfWinners(FILE *fichier) {
    int count = 0;
    char caractere;

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            count++;
        }
    }

    return count;
}

void readWinner(FILE *fichier, struct TuringWinner *winner) {
    fscanf(fichier,"%i" ";", &winner->annee );
    winner->nom = redStringFromFileUntil (fichier, ';');
    winner->travaux=readStringFrilFileUntil(fichier, '\n');
}

TuringWinner *readWinners(FILE* fichier){
    int capacite=numberOfWinners(fichier);
    TuringWinner* listOfWinners = (TuringWinner*)malloc(capacite * sizeof(TuringWinner));
    while(fgets(ligne,sizeof(ligne),fichier) != NULL){
        readWinner(fichier,*listOfWinners);
    }
    return listOfWinners;
}
