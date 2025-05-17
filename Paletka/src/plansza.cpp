#include "plansza.h"
#include "paletka.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "mojapaletka.h"
//Po utworzeniu nowej klasy należy dodać jej plik nagłówkowy

plansza::plansza(int szerokosc) {
    this->szerokosc = szerokosc;

    //Wybierz jedną z dwóch paletek
    //this->paletka = new ::paletka(3, szerokosc/2, szerokosc);
    this->paletka = new ::mojapaletka(3, szerokosc/2, szerokosc);

    this->obiekty = WYSOKOSCPLANSZY-1;
    srand(time(NULL));
    this->obiektx = rand()%this->szerokosc;
    this->punkty = 0;
    this->kroki = 0;
    this->specjalnyObiekt = false;
    this->czasPoszerzenia = 0;
    this->czasOczekiwania = 0;
}

void plansza::postepCzasowy() {
    if(this->specjalnyObiekt) {
        this->obiektx += (rand()%3)-1;
    }
    if(this->obiekty >= 0 ) {
        this->obiekty--;
        if(this->obiekty == -1) {
            this->obiektx = -1;
            this->czasOczekiwania = rand()%10;
        }
    }

    if (this->obiekty < 0 && this->czasOczekiwania == 0) {
        this->obiektx = rand()%this->szerokosc;
        this->obiekty = WYSOKOSCPLANSZY-1;
        if((rand()%100)>85) this->specjalnyObiekt = true;
        else this->specjalnyObiekt = false;
    }
    else if(this->czasOczekiwania > 0) this->czasOczekiwania--;

    this->kroki++;
    paletka->poinformujOobiekcie(this->obiektx, this->obiekty);
    paletka->krok();
}

void plansza::drukuj() {
    int wiersz, kolumna;
    int paletkaPozycja, paletkaSzerokosc;

    paletkaPozycja = this->paletka->pobierzPozycje();
    paletkaSzerokosc = this->paletka->pobierzSzerokosc();
    if(paletkaSzerokosc > 3) {
        this->czasPoszerzenia--;
        if(this->czasPoszerzenia == 0) {
            this->paletka->ustawSzerokosc(3);
            paletkaSzerokosc = 3;
        }
    }
    fprintf(stderr, "\n\n\n\n");

    for(wiersz = WYSOKOSCPLANSZY-1; wiersz >= 0; wiersz--) {
        for(kolumna = 0; kolumna < this->szerokosc; kolumna++) {
            if(wiersz == 0) {
                if(kolumna >= (paletkaPozycja - (paletkaSzerokosc-1)/2) && kolumna <= (paletkaPozycja + (paletkaSzerokosc-1)/2)) {
                    if(this->obiektx == kolumna && this->obiekty == 0) {
                        fprintf(stderr, "*");
                        this->punkty++;
                        if(this->specjalnyObiekt) {
                            this->paletka->ustawSzerokosc(7);
                            this->czasPoszerzenia = 50;
                        }
                    }
                    else fprintf(stderr, "=");
                }
                else {
                    if(this->obiektx == kolumna && this->obiekty == 0) fprintf(stderr, "x");
                    else fprintf(stderr, " ");
                }
            }
            else {
                if(wiersz == this->obiekty && kolumna == this->obiektx) {
                    if(this->specjalnyObiekt)
                        fprintf(stderr, "#");
                    else
                        fprintf(stderr, "x");
                }
                else
                    fprintf(stderr, " ");
            }
        }
        fprintf(stderr, "\n");
    }
    for(int i = 0; i < this->szerokosc; ++i) {
        fprintf(stderr, "-");
    }
    fprintf(stderr, "\n");
    fprintf(stderr, "Kroki: %6d\tPunkty: %6d\tp/k: %.4f\n", this->kroki, this->punkty, (float) this->punkty/this->kroki);
    fprintf(stderr, "Obiekt Y: %2d X:%2d\tczas oczekiwania: %2d\n", this->obiekty, this->obiektx, this->czasOczekiwania);

}

plansza::~plansza()
{
    //dtor
}

