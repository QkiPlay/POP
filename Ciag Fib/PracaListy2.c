#include <stdio.h>
#include <stdlib.h>
struct ciag
{
    int fb;
    int szereg;
    struct ciag *nastepny;
};

int main()
{
    int n;
    printf("podaj liczbe elementow ciagow\n");
    scanf("%d", &n);
    printf("podana liczba elementow: %d\n", n);

    struct ciag *lista = NULL;
    struct ciag *aktualna = NULL;
    struct ciag *tmp = NULL;
    int i, j = 0, index, p1, p2;

    lista = malloc(sizeof(struct ciag));
    if(lista == NULL)
    {
        printf("nie udalo sie zaalokowac pamieci\n");
        return -1;
    }

    aktualna = lista;

    for(i = 0; i < n; ++i)
    {
        if(i%2==0)
        {
            aktualna->szereg = i * -1;
        }
        else
        {
            aktualna->szereg = i;
        }
        if(i < 2)
        {
            aktualna->fb = i;
            p1 = 0;
            p2 = 1;
        }
        else
        {
            aktualna->fb = p1 + p2;
            if(p2 > p1)
            {
                p1 = aktualna->fb;
            }
            else
            {
                p2 = aktualna->fb;
            }
        }
        aktualna->nastepny = malloc(sizeof(struct ciag));
        if(aktualna->nastepny == NULL)
        {
            break;
        }
        aktualna->nastepny->nastepny = NULL;
        printf("Elemen %d ma wartosc %d w szeregu i %d w ciagu fb\n", i, aktualna->szereg, aktualna->fb);
        aktualna = aktualna->nastepny;
    }

    aktualna = lista;
    index = 0;
    while(aktualna)
    {
        if(index % 2 !=0)
        {
            tmp->nastepny = aktualna->nastepny;
            free(aktualna);
            aktualna = tmp->nastepny;
        }
        else
        {
            tmp = aktualna;
            aktualna = aktualna->nastepny;
        }
        ++index;
    }

    aktualna = lista;
    while(aktualna && j < n)
    {
        printf("Element %d szeregu ma wartosc %d a ciagu fibonacciego %d \n", j * 2, aktualna->szereg, aktualna->fb);
        aktualna = aktualna->nastepny;
        ++j;
    }
    aktualna = lista;
    while(aktualna)
    {
        lista->nastepny = aktualna->nastepny;
        free(aktualna);
        aktualna = lista->nastepny;
        printf("test1\n");
    }
    return 0;
}
