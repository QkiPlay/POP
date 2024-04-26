#include <stdio.h>
#include <stdlib.h>

struct element
{
    int fib;
    int szereg;
    struct element *nastepny;
};//Stworzenie struktury z wartością szeregu, ciągu fibonnacciego i adresem następnej struktury na liście.
int main()
{
    struct element *pierwszy = NULL;
    struct element *aktualny = NULL;
    int i, ile;

    printf("Podaj liczbe elementow: ");
    if (!scanf("%d", &ile) || ile <= 0){
        printf("Zla wartosc");
        return(0);
    }//Sanityzacja wprowadzonej wartości.

    pierwszy = malloc(sizeof(struct element));//Alokacja pamięci dla pierwszego elementu
    if (pierwszy == NULL) return -1;//Sprawdzenie czy alokacja powiodła się
    aktualny = pierwszy;
    int fb1 = 0;
    int fb2 = 1;
    for (i = 0; i < ile; ++i)
    {
        if (i == 0)
            aktualny->fib = fb1;
        //Jeśli szukamy pierwszego elementu ciągu, to nie musimy dokonywać żadnych obliczeń, bo jest równy wstępnej wartości.
        else
        {
            int temp = fb1;
            fb1 += fb2;
            fb2 = temp;
            aktualny->fib = fb1;
        }
        aktualny->szereg = i % 2 == 0 ? 1 : -1;//Podany szereg zawsze przyjmuje wartość 1 albo -1 w zależności od tego który element liczymy (parzysty 1, nieparzysty -1)
        aktualny->nastepny = NULL;//tworzy nastepny element listy

        if (i < ile - 1)
        {
            aktualny->nastepny = malloc(sizeof(struct element));//przypisujemy pamiec nastepnemu elementowi
            if (aktualny->nastepny == NULL) exit(1);//sprawdzamy czy sie udalo
        }

        aktualny = aktualny->nastepny;//przechodzimy do nastepnego elementu
    }

    aktualny = pierwszy;//wracamy do poczatku listy

    printf("Kolejne elementy tablicy po utworzeniu: \n");
    for (i = 0; i < ile; i++)
    {
        printf("Indeks=%d: fib=%d, szereg=%d\n", i, aktualny->fib, aktualny->szereg);
        aktualny = aktualny->nastepny;
    }

    aktualny = pierwszy;

    struct element *poprzedni = NULL;
    i = 0;

    //Usuwanie elementów nieparzystych
    while (aktualny != NULL)
    {
        if (i % 2 != 0)
        {
            aktualny = aktualny->nastepny;
            if (poprzedni == NULL) 
                pierwszy = aktualny;
            else {
                free(poprzedni->nastepny);
                poprzedni->nastepny = aktualny;
            }
        }
        else
        {
            poprzedni = aktualny;
            aktualny = aktualny->nastepny;
        }
        i++;
    }

    printf("\n\nKolejne elementy tablicy po usunieciu elementow nieparzystych: \n");
    aktualny = pierwszy;
    i = 0;
    while (aktualny != NULL)
    {
        printf("Indeks=%d: fib=%d, szereg=%d\n", i, aktualny->fib, aktualny->szereg);
        aktualny = aktualny->nastepny;
        i+=2;
    }

    //Calkowite wyczyszczenie listy
    aktualny = pierwszy;
    while (aktualny != NULL)
    {
        struct element *temp = aktualny;
        aktualny = aktualny->nastepny;
        free(temp);
    }
    pierwszy = NULL;
    free(pierwszy);
    return 0;
}
