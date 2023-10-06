//Alix Domange

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct{
	int index;
	int distance;
}Difference;

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int longueurSequence(char* sequence){
	int longueur=0;
	while(*sequence!="\0"){
		longueur=longueur +1;
		sequence=sequence +1;
	}
	return longueur;
}

int* statistics(char* sequence){
	int* stat=(int*) calloc(4,sizeof(int));

	int tailleSequence= longueurSequence(sequence);

	while(sequence!=NULL){
		if(isNucleotide(*sequence)){
			switch(indexOf(*sequence)){
				case 0: stat[0]+=1;
				case 1: stat[1]+=1;
				case 2: stat[2]+=1;
				case 3: stat[3]+=1;
				default:
					return 0;
			}
		}
		sequence=sequence+1;
	}
	for(int i=0; i<4; i++){
		stat[i]=(stat[i]/tailleSequence)*100;
	}
	return stat;
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

Difference* computeDifferencesBetween(char* sequence1, char* sequence2){
	Difference* tabDifferences = (Difference*) malloc(sizeof(Difference));
	int indice=0;
	int indiceDif=0;
	if(longueurSequence(sequence1)==longueurSequence(sequence2)){
		while(sequence1!=NULL){
			if(*sequence1!=*sequence2){
				(tabDifferences[indiceDif]).index=indice;
				(tabDifferences[indiceDif]).distance=distanceBetweenNucleotides(*sequence1, *sequence2);
				indiceDif +=1;
			}
			sequence1 +=1;
			sequence2 +=1;
			indice +=1;
		}
	}
	return tabDifferences;

}


// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

	for(int i=0; i<4; i++){
		printf("%d \n", *(statistics(sequenceDeNucleotides) + i));
	}
    //printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

