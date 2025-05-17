#ifndef TESTY_H_INCLUDED
#define TESTY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "referencyjne.h"


#define TIMINGTESTS 10000

void testujFunkcjeKompresji(char *(fun)(char *, unsigned int, unsigned int *));
void testujFunkcjeDekompresji(char *(fun)(char *, unsigned int, unsigned int *));

//char *referencyjnaKompresjaRLE(char *daneWejsciowe, unsigned int dlugoscDanychWejsciowych, unsigned int *dlugoscDanychWyjsciowych);

void testujFunkcje(int wariant, char *(fun)(char *, unsigned int, unsigned int *));


#endif // TESTY_H_INCLUDED
