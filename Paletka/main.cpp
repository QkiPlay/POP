#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include "plansza.h"

#define KROKI   1000    // Liczba iteracji w grze
#define FPS     100     // Żądana liczba klatek na sekundę :-)

using namespace std;

/*
Zadanie polega na napisaniu klasy "mojapaletka", która dziedziczy po klasie paletka.

Klasa paletka zawsze wie gdzie znajduje się obiekt "do złapania". Informacje te są we właściwościach
obiektX oraz obiektY. Wartość obiektY mówi o tym ile wierszy wyżej nad paletką jest obiekt. Wartość
obiektX mówi o położeniu obiektu w odpowiedniej kolumnie. Jeśli którakolwiek z tych wartości jest ujemna,
oznacza to, że w danym momencie nie ma żadnego obiektu do łapania.

Warunki:
- Paletka ma analizować położenie obiektu do złapania i go złapać.
- Paletka nie może wykonywać przesunięcia większęgo niż o jedną pozycję na każdy krok.
- Paletka może w danym kroku nie wykonywać żadnego przesunięcia.
- Paletka może zmieniać rozmiar tylko jeśli logika gry tego zażąda.
- Dozwolone są modyfikacje dostarczonych plików w następującym zakresie:
  - dodawanie plików nagłówkowych do plików .cpp,
  - podmiana klasy paletki w konstruktorze planszy,
  - modyfikacja parametrów KROKI, FPS, SZEROKOSCPLANSZY, WYSOKOSCPLANSZY (do testów),
  - włączenie polimorfizmu.

Po stworzeniu klasy mojapaletka, należy odkomentować odpowiednią "paletkę" w konstruktorze planszy (plansza.cpp) pamiętając
też o pliku nagłówkowym.

Uzyskany wynik powinien być lepszy od paletki referencyjnej, która naiwną metodą uzyskuje około 0,005 punktu/krok.
Wyniki będą badane dla domyślnych parametrów szerokości planszy i wysokości planszy.

Do sprawdzenia należy przesłać cały katalog projektu. Przed przesłaniem projektu należy wykonać na nim Build->Clean, żeby usunąć pliki obiektowe i wynikowe.

TL;DR
Trzeba napisać nową, lepszą paletkę.

*/

int main() {

    plansza *p = new plansza(SZEROKOSCPLANSZY);

    for(int i = 0; i < KROKI; ++i) {
            system("CLS");
        p->postepCzasowy();
        p->drukuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/FPS));
    }

    return 0;
}
