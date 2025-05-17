#include <stdio.h>
#include <stdlib.h>
void wyswietlLabirynt(char *mapa,int n, int px, int py)
{
    int x = 0,y = 0;
    for(int d = 0; d<n; d++)
    {
        for(int i = 0; i<n; i++)
        {
            if(x==px && y == py)
            {
                printf("O");
            }
            else
            {
                printf("%c",mapa[i+d*n]);
            }
            x++;
        }
        printf("\n");
        y++;
        x=0;
    }
}
int sprawdzPole(char *mapa,int n, int x, int y)
{
    if(x<0 || x>n-1 || y<0 || y>n-1) return 0;
    for(int i = 0; i<n*n; i++)
    {
        if(mapa[y*n + x]==0x23)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void ruch(char *mapa,int rozmiar,int kx,int ky)
{
    char historia[100];
    int px=0,py=0;
    int i = 1;
//GÓRA
while(px != rozmiar-1 || py != rozmiar-1){
        usleep(250000);
    printf("%d\n",i);
    printf("%d,%d,%d,%d\n",px,py,kx,ky);
    wyswietlLabirynt(mapa,rozmiar,px,py);
    i++;
    printf("\n\n\n\n");
    if(kx == 0 && ky == -1)
    {
        //prawo
        if(sprawdzPole(mapa,rozmiar,px+1,py)==1)
        {
            kx = 1;
            ky = 0;
            px++;
        }
        //wprost
        else if(sprawdzPole(mapa,rozmiar,px,py-1)==1)
        {
            py--;
        }
        //lewo
        else if(sprawdzPole(mapa,rozmiar,px-1,py)==1)
        {
            kx = -1;
            ky = 0;
            px--;
        }
        //tył
        else if(sprawdzPole(mapa,rozmiar,px,py+1)==1)
        {
            kx = 0;
            ky = 1;
            py++;
        }
    }
//PRAWO
    else if(kx==1 && ky == 0)
    {
        if(sprawdzPole(mapa,rozmiar,px,py+1)==1)
        {
            kx = 0;
            ky = 1;
            py++;
        }
        else if(sprawdzPole(mapa,rozmiar,px+1,py)==1)
        {
            px++;
        }
        else if(sprawdzPole(mapa,rozmiar,px,py-1)==1)
        {
            kx = 0;
            ky = -1;
            py--;
        }
        else if(sprawdzPole(mapa,rozmiar,px-1,py)==1)
        {
            kx = -1;
            ky = 0;
            px--;
        }
    }
    //DÓŁ
    else if(kx==0 && ky == 1)
    {
        if(sprawdzPole(mapa,rozmiar,px-1,py)==1)
        {
            kx = -1;
            ky = 0;
            px--;
        }
        else if(sprawdzPole(mapa,rozmiar,px,py+1)==1)
        {
            py++;
        }
        else if(sprawdzPole(mapa,rozmiar,px+1,py)==1)
        {
            kx = 1;
            ky = 0;
            px++;
        }
        else if(sprawdzPole(mapa,rozmiar,px,py-1)==1)
        {
            kx = 0;
            ky = -1;
            py--;
        }
    }
    //LEWO
    else if(kx==-1 && ky == 0)
    {
        if(sprawdzPole(mapa,rozmiar,px,py-1)==1)
        {
            kx = 0;
            ky = -1;
            py--;
        }
        else if(sprawdzPole(mapa,rozmiar,px-1,py)==1)
        {
            px--;
        }
        else if(sprawdzPole(mapa,rozmiar,px,py+1)==1)
        {
            kx = 0;
            ky = 1;
            py++;;
        }
        else if(sprawdzPole(mapa,rozmiar,px+1,py)==1)
        {
            px++;
            kx = 1;
            ky = 0;
        }
    }
}
wyswietlLabirynt(mapa,rozmiar,px,py);

}


int main()
{
    int rozmiar;
    printf("Podaj dlugosc boku labiryntu: ");
    scanf("%d",&rozmiar);
    char *labirynt = malloc(rozmiar*rozmiar);
    int bytes;
    FILE *p = fopen("9x9_1.txt", "r");
    bytes = fread(labirynt, 1, rozmiar*rozmiar, p);
    fclose(p);
    ruch(labirynt,rozmiar,1,0);
    return 0;
}
