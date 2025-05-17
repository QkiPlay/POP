#ifndef REFERENCYJNE_H_INCLUDED
#define REFERENCYJNE_H_INCLUDED

#include <stdlib.h>

char *referencyjnaKompresjaRLE(char *daneWejsciowe, unsigned int dlugoscDanychWejsciowych, unsigned int *dlugoscDanychWyjsciowych);
char *referencyjnaDekompresjaRLE(char *daneWejsciowe, unsigned int dlugoscDanychWejsciowych, unsigned int *dlugoscDanychWyjsciowych);

#endif // REFERENCYJNE_H_INCLUDED
