


void initialiseDate(Date *d){

    printf("Entrer le numéro du jour : ");
    scanf("%hu", &(d->jour));
    printf("Entrer le numéro du mois : ");
    scanf("%d", (int *)&d->mois);
    printf("Entrer l'année' : ");
    scanf("%hu", &(d->annee));


}

void afficheDate(Date *d){
    printf("%i %i %i\n", &d->jour,(int) &d.mois, &d->annee)
}

Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}

int *Date newDate(){

}