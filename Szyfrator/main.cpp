#include <iostream>
using namespace std;
class Szyfrator {
public:
    Szyfrator(){}
    Szyfrator(string klucz) {
        ustawKlucz(klucz);
    }

    void ustawKlucz(string klucz){
        string k2;
        if(klucz.length() % 2 == 1) {
            throw(invalid_argument("Bledny klucz, nieparzysta liczba znakow."));
        }else if(klucz.empty()) {
            throw(invalid_argument("Pusty klucz."));
        }else{
            for(int i = 0; i < klucz.length();i+=2) {
                k2 += klucz[i];
                k2 += klucz[i+1];
                k2 += klucz[i+1];
                k2 += klucz[i];
            };
            this->klucz = k2;
        }
    }

    string pobierzKlucz(){
        return this->klucz;
    }

    string szyfruj(string tekst) {
        string zaszyfrowane;
        for(char i : tekst) {
            for(int j = 0; j < klucz.length(); j+=2) {
                if(i == klucz[j]) {
                    zaszyfrowane += klucz[j+1];
                    break;
                }
                else if(j == klucz.length()-2)
                    zaszyfrowane += i;
            }
        }
        return zaszyfrowane;
    }

    string deszyfruj(string zaszyfrowany) {
        string rozszyfrowany;
        for(char i : zaszyfrowany) {
            for(int j = 0; j < klucz.length(); j+=2) {
                if(i == klucz[j+1]) {
                    rozszyfrowany += klucz[j];
                    break;
                }
                else if(j == klucz.length()-2)
                    rozszyfrowany += i;
            }
        }
        return rozszyfrowany;
    }
private:
    string klucz;

};


int main() {
    //Klucze i ciąg testowy można ustawić dowolne
    string klucz1 = "qwertyuiop";
    string klucz2 = "abcdefghijkl";
    string testowy = "Jaka prosta praca domowa!";

    //Tu utwórz pierwszą instancję klasy:
    Szyfrator *szyfr1 = new Szyfrator();
    //I wpisz klucz
    szyfr1->ustawKlucz(klucz1);

    //Druga instancja klasy
    Szyfrator *szyfr2 = new Szyfrator(klucz2);

    //Weryfikacja czy operacje są odwracalne
    cout << szyfr1->deszyfruj(szyfr1->szyfruj(testowy)) << endl;
    cout << szyfr2->deszyfruj(szyfr2->szyfruj(testowy)) << endl;

    return 0;
}
