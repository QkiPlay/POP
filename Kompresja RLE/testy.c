#include "testy.h"
#include <time.h>

//Tym plikiem specjalnie się nie interesujcie, ale może zobaczycie w nim jakąś ciekawą konstrukcję ;-)

extern char daneSkompresowane[19862];
extern char daneNieskompresowane[29447];

void testujFunkcjeKompresji(char *(fun)(char *, unsigned int, unsigned int *)) {
    testujFunkcje(0, fun);
}

void testujFunkcjeDekompresji(char *(fun)(char *, unsigned int, unsigned int *)) {
    testujFunkcje(1, fun);
}

void testujFunkcje(int wariant, char *(fun)(char *, unsigned int, unsigned int *)) {

    char *zwrot1, *zwrot2;
    unsigned int rozmiar1, rozmiar2;
    struct timespec start, stop;
    char *data;
    unsigned int size, rm;
    double tdiffRef, tdiff;
    int i, n = 0;
    char *(*refFun)(char *, unsigned int, unsigned int *);

    if(wariant == 0) { //kompresja
        data = daneNieskompresowane;
        size = sizeof(daneNieskompresowane);
        refFun = referencyjnaKompresjaRLE;
    }
    else {  //dekompresja
        data = daneSkompresowane;
        size = sizeof(daneSkompresowane);
        refFun = referencyjnaDekompresjaRLE;
    }

    //Porównanie zwracanych informacji
    zwrot1 = (*fun)(data, size, &rozmiar1);
    printf("Funkcja zwróciła dane o rozmiarze %d\n", rozmiar1);

    zwrot2 = (*refFun)(data, size, &rozmiar2);
    printf("Funkcja referencyjna zwróciła dane o rozmiarze %d\n", rozmiar2);

    rm = (rozmiar1 < rozmiar2)?rozmiar1:rozmiar2;
    for(i = 0; i < rm; ++i) {
        if(zwrot1[i] != zwrot2[i]) ++n;
    }
    printf("Liczba znalezionych różnic pomiędzy zwrotami funkcji: %d\n", n);

    free(zwrot1);
    free(zwrot2);

    //Pomiary czasu
    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < TIMINGTESTS; ++i) {
        zwrot1 = (*fun)(data, size, &rozmiar1);
        free(zwrot1);
    }
    clock_gettime(CLOCK_REALTIME, &stop);

    tdiff = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double) 1000000000L;

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 0; i < TIMINGTESTS; ++i) {
        zwrot2 = (*refFun)(data, size, &rozmiar2);
        free(zwrot2);
    }
    clock_gettime(CLOCK_REALTIME, &stop);

    tdiffRef = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double) 1000000000L;

    printf("Czas wykonania %d powtórzeń funkcji wyniósł %lf sekund\n", TIMINGTESTS, tdiff);
    printf("Czas wykonania %d powtórzeń funkcji referencyjnej wyniósł %lf sekund\n", TIMINGTESTS, tdiffRef);
}
