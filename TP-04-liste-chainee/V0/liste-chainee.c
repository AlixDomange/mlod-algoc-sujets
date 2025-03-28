#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l = (Liste)malloc(sizeof(Cellule));
	l->val= v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Cellule *cell;
	cell=creer(v);
	cell->suiv=l;
	return cell;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Cellule *c=l;
	while(c!=NULL){
		afficheElement(c->val);
		c=c->suiv;
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if(l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, courant = l;
	while(courant!=NULL){
		suivant=courant->suiv;
		detruireElement(courant->val);
		free(courant);
		courant = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l!=NULL){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste elem = creer(v);
	if(l==NULL){
		return elem;
	}
	while(l->suiv!=NULL){
		l=l->suiv;
	}
	l->suiv=elem;
	elem->suiv=NULL;
	return elem;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	return TODO;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p =l;
	while(p!=NULL && !equalsElement(p->val,v)){
		p=p->suiv;
	}
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	Liste p=l;
	if (p!=NULL && !equalsElement(v, p->val)){
		cherche_r(v, p->suiv);
	}
	return p;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste p=l;
	while(equalsElement(v,p->val)==false){
		p=p->suiv;
	}
	
	detruireElement(p->val);

	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}