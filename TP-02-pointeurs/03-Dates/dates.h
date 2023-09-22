#pragma once

typedef enum {
    janvier=1,
    février,
    mars,
    avril,
    mai,
    juin,
    juillet,
    août,
    septembre,
    octobre,
    novembre,
    décembre
}Mois;

typedef struct {
    unsigned short jour;
    Mois mois;
    unsigned short annee;
}Date;