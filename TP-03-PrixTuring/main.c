#include "prixTuring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *inputFile = fopen(filename, "r");
	FILE *outputFile = fopen(outputFilename, "w");

	printf("%i", numberOfWinners(inputFile));

}