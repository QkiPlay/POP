#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input,i,p;
    p=1;
    while(p=1){
        printf("Podaj nieujemna liczbe elementow tablicy: ");
        scanf("%d",&input);
        if(input>0)
            break;
        printf("Bledna wartosc.\n");
    }
    int *tab1 = malloc(input*sizeof(int));
    int *tab2 = malloc(input*sizeof(int));
    for (i = 0;i < input;i++){
        *(tab1+i) = rand();
        printf("\n%d element tablicy 'tab1' to: %d",i, tab1[i]);
    }
    printf("\n");
    for (int j = input-1;j>=0;j--){
        *(tab2+j) = tab1[input-j-1];
        printf("\n%d element tablicy 'tab2' to: %d",j, tab2[j]);
    }
    return 0;
}
