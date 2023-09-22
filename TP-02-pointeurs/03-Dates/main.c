
void main(){
    Date d;

    printf("version 1 : Initialisation d'une date allouée statistiquement \n")
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    printf("\n version 2 : recopie d'une date allouée statistiquement \n")
    d= creerDateParCopie();
    afficheDate(&d);

    printf("\n version 3 : allocation dynamique de date \n")
    date=newDate();
    afficheDate(date);
    free(date);
}