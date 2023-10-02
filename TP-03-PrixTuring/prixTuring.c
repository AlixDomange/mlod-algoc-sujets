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
#include <stdint.h>
#include <stdbool.h>
#include "prixTuring.h"


uint16_t numberOfWinners(FILE *fichier) {
    int count = 0;
    char caractere;

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            count++;
        }
    }

    return count;
}


TuringWinner *readWinners(FILE *file, uint16_t nWinners) {
    TuringWinner *winners = (TuringWinner *)malloc(nWinners * sizeof(TuringWinner));

    if (winners == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    char c;
    int fieldIndex = 0;
    int winnerIndex = 0;
    int bufferIndex = 0;
    char buffer[2048];

    while (((c = fgetc(file)) != EOF) && (winnerIndex < nWinners)) {
        if (c == ';') {
            buffer[bufferIndex] = '\0';
            switch (fieldIndex) {
                case 0:
                    winners[winnerIndex].annee = atoi(buffer);
                    break;

                case 1:
                    if (bufferIndex > 0 && buffer[bufferIndex - 1] == '\n') {
                        bufferIndex--;
                    }
                    strncpy(winners[winnerIndex].nom, buffer, bufferIndex);
                    winners[winnerIndex].nom[bufferIndex] = '\0';
                    break;

                case 2:
                    if (bufferIndex > 0 && buffer[bufferIndex - 1] == '\n') {
                        bufferIndex--;
                    }
                    strncpy(winners[winnerIndex].travaux, buffer, bufferIndex);
                    winners[winnerIndex].travaux[bufferIndex] = '\0';
                    break;
            }
            bufferIndex = 0;
            memset(buffer, 0, sizeof(buffer));
            fieldIndex++;

            if (c == '\n') {
                winners[winnerIndex].travaux[bufferIndex - 1] = '\0';
                bufferIndex = 0;
                fieldIndex = 0;
                winnerIndex++;
            }
        } else {
            buffer[bufferIndex++] = c;
        }
    }

    return winners;
}


void printWinners(TuringWinner *winners, FILE *file, uint16_t nWinners) {
    for (uint16_t i = 0; i < nWinners; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].travaux);
        free(winners[i].annee);
        free(winners[i].nom);
        free(winners[i].travaux);
    }
    free(winners);
}