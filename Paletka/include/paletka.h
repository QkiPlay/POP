#ifndef PALETKA_H
#define PALETKA_H

class paletka
{
    public:
        //Konstruktor przyjmuje szerokość paletki, jej pozycję początkową oraz szerokość planszy (maxwychylenie)
        paletka(int szerokosc, int pozycja, int maxwychylenie);
        virtual ~paletka();

        //Metoda zwraca pozycję środka paletki
        int pobierzPozycje();

        //Metoda zwraca szerokość paletki (tylko liczby nieparzyste)
        int pobierzSzerokosc();

        //Ustawianie szerokości paletki
        void ustawSzerokosc(int szerokosc);

        //Plansza przekazuje paletce informacje o pozycji spadającego obiektu,
        //dane zapisywane są do chronionych właściwości obiektX i obiektY
        void poinformujOobiekcie(int x, int y);

        //Wykonanie kroku. Paletka może przesuwać się tylko o jedną pozycję z każdym krokiem
        //Konieczność zaimplementowania "inteligencji"
        virtual bool krok();

    protected:
        int pozycja;
        int szerokosc;
        int maxwychylenie;

        int kierunek;

        int obiektX;
        int obiektY;

    private:
};

#endif // PALETKA_H
