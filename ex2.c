#include <stdlib.h>
#include <stdio.h>
#define MAX 40

int main()
{

    FILE *arq0;

    if((arq0 = fopen("notas.txt", "w")) == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }

    int i;
    for(i = 1; i <= MAX; i++)
    {
        int a = rand() % 10;
        fprintf(arq0, "%d\n", a);
    }

    fclose(arq0);


    FILE *arq;
    int soma = 0;


    if((arq = fopen("notas.txt", "r")) == NULL)
    {
        printf("ERRO\n");
        exit(0);
    }


    for(i = 1; i <= MAX; i++)
    {
        int a;
        fscanf(arq, "%d", &a);
        soma += a;
    }


    float media = soma / (i - 1);
    printf("MEDIA %.2f", media);


    fclose(arq);



    return 0;
}