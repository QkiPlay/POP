#include "moja.h"
#include <stdio.h>
#include <stdlib.h>

char *mojaFunkcja(char* daneWejsciowe,unsigned int dlugoscDanychWejsciowych,unsigned int* dlugoscDanychWyjsciowych) {
    char* skompresowane_dane_wyjsciowe=malloc(dlugoscDanychWejsciowych);
    if(skompresowane_dane_wyjsciowe==NULL) exit(1);
    int i,pozycja_w_skompresowanych=0;
    char biezacy_znak=daneWejsciowe[0];
    char ile_razy_biezacy_znak=0;
    skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych] = ile_razy_biezacy_znak;
    skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych+1] = biezacy_znak;
    pozycja_w_skompresowanych += 2;
    biezacy_znak = daneWejsciowe[0];
    ile_razy_biezacy_znak = 1;
    for (i = 1;i < dlugoscDanychWejsciowych;i++){
        if (daneWejsciowe[i] == biezacy_znak) {
            ile_razy_biezacy_znak++;
        } else {
            skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych] = ile_razy_biezacy_znak;
            skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych+1] = biezacy_znak;
            pozycja_w_skompresowanych += 2;
            biezacy_znak = daneWejsciowe[i];
            ile_razy_biezacy_znak = 1;
        }
    }
    skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych++] = ile_razy_biezacy_znak;
    skompresowane_dane_wyjsciowe[pozycja_w_skompresowanych++] = biezacy_znak;
    *dlugoscDanychWyjsciowych = pozycja_w_skompresowanych;
    return skompresowane_dane_wyjsciowe;
}
