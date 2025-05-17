#ifndef PLANSZA_H
#define PLANSZA_H

/*Definicja parametrów planszy*/
/*Domyślne wartości to WYSOKOSCPLANSZY=10 i SZEROKOSCPLANSZY=30*/

#define WYSOKOSCPLANSZY     10
#define SZEROKOSCPLANSZY    30

#include "paletka.h"

class plansza
{
    public:
        plansza(int szerokosc);
        void postepCzasowy();
        virtual ~plansza();
        void drukuj();
        int pobierzXobiektu();
        int pobierzYobiekty();

    protected:
        int szerokosc;
        ::paletka *paletka;
        int obiekty;
        int obiektx;
        int punkty;
        int kroki;
        bool specjalnyObiekt;
        int czasPoszerzenia;
        int czasOczekiwania;

    private:
};

#endif // PLANSZA_H
