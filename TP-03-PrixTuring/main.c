#include "prixTuring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>

//int main(int argc, char** argv)
//{
//	char filename[] = "turingWinners.csv";
//	char outputFilename[] = "out.csv";
//
//	FILE *inputFile = fopen(filename, "r");
//	FILE *outputFile = fopen(outputFilename, "w");
//
//	printf("%i", numberOfWinners(inputFile));
//
//}


int main(int argc, char** argv) {

	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *inputFile = fopen(filename, "r");
	FILE *outputFile = fopen(outputFilename, "w");

    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }

    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(inputFile); // Fermer le fichier d'entrée si le fichier de sortie ne peut pas être ouvert.
        return EXIT_FAILURE;
    }

    uint16_t nWinners = numberOfWinners(inputFile);
    TuringWinner *winners = (TuringWinner *)malloc(nWinners * sizeof(TuringWinner));

    if (winners == NULL) {
        perror("Erreur d'allocation de mémoire");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    readWinners(inputFile, nWinners);
    printWinners(winners, outputFile, nWinners);

    // Libération de la mémoire et fermeture des fichiers
    free(winners);
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}