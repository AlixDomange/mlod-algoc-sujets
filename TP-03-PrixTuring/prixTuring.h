#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint16_t annee;
    char *nom;
    char *travaux;
}TuringWinner;

uint16_t numberOfWinners(FILE *fichier);
TuringWinner *readWinners(FILE *file, uint16_t nWinners);
void printWinners(TuringWinner *winners, FILE *file, uint16_t nWinners);