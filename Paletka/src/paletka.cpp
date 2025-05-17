#include "paletka.h"
#include <cstdio>

paletka::paletka(int szerokosc, int pozycja, int maxwychylenie) {
    this->szerokosc = szerokosc;
    this->maxwychylenie = maxwychylenie;
    this->pozycja = pozycja;

    this->kierunek = 1;
}

int paletka::pobierzPozycje() {
    return this->pozycja;
}

int paletka::pobierzSzerokosc() {
    return this->szerokosc;
}
void paletka::ustawSzerokosc(int szerokosc) {
    this->szerokosc = szerokosc;
}

bool paletka::krok() {
    if((this->pozycja + (this->szerokosc-1)/2) > this->maxwychylenie)
        this->kierunek = -1;
    else if((this->pozycja - (this->szerokosc-1)/2) <= 0)
        this->kierunek = 1;
    pozycja += this->kierunek;
    return true;
}

void paletka::poinformujOobiekcie(int x, int y) {
    this->obiektX = x;
    this->obiektY = y;
}

paletka::~paletka()
{
    //dtor
}
