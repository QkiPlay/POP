#include "mojapaletka.h"
#include <cmath>
int jakiznak(int x){
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
mojapaletka::mojapaletka(int szerokosc, int pozycja, int maxwychylenie) : paletka(szerokosc, pozycja, maxwychylenie) {}
    bool mojapaletka::krok() {
        int pozycja = this->pozycja;
        int maxwychylenie = this->maxwychylenie;
        int kierunek;
        int dystans = abs(pozycja-obiektX)-(szerokosc+1)/2;
    //Jeśli nie ma celu - idź do środka
        if (obiektY < 0 && obiektX < 0){
            kierunek = jakiznak(maxwychylenie/2-pozycja);
    //Jeśli cel w zasięgu - idź do obiektu
        }else if(dystans <= obiektY){
            kierunek = jakiznak(obiektX-pozycja);
    //Jeśli cel poza zasięgiem - środek
        }else {
            kierunek = jakiznak(maxwychylenie/2-pozycja);
        }

        if((pozycja+=kierunek) >= maxwychylenie || (pozycja+=kierunek) < 0) {
            kierunek *= -1;
        }
        this->pozycja+=kierunek;
        return true;
    }
