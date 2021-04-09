#include <stdio.h>
#include <stdlib.h>
#include <sort.h>
#include <string.h>
#include <time.h>

const int dez = 10;
const int mil = 1000;
const int cemk = 100000;

int main(){

    // Setando uma seed para manter os valores pseudo-aleatórios constantes entre as execuções:
    srand(0);

    int v[] = {3, 6, 2, 5, 4, 3, 7, 1};

    // Alocando o espaço necessário para cada array para as combinações de fatores:
    int *dez1 = (int *) malloc(dez * sizeof(int));
    int *dez2 = (int *) malloc(dez * sizeof(int));
    int *dez3 = (int *) malloc(dez * sizeof(int));

    int *mil1 = (int *) malloc(mil * sizeof(int));
    int *mil2 = (int *) malloc(mil * sizeof(int));
    int *mil3 = (int *) malloc(mil * sizeof(int));

    int *cemk1 = (int *) malloc(cemk * sizeof(int));
    int *cemk2 = (int *) malloc(cemk * sizeof(int));
    int *cemk3 = (int *) malloc(cemk * sizeof(int));

    for(int loop = 1; loop <= 30; loop++){
    // Preenchendo os arrays da forma que foi designada no enunciado:
    for(int i = 0; i < dez; i++)
    {
         dez1[i] = i;
         dez2[i] = dez - i;
         dez3[i] = rand() % dez;
    }

    for(int i = 0; i < mil; i++)
    {
         mil1[i] = i;
         mil2[i] = mil - i;
         mil3[i] = rand() % mil;
    }

    for(int i = 0; i < cemk; i++)
    {
         cemk1[i] = i;
         cemk2[i] = cemk - i;
         cemk3[i] = rand() % cemk;
    }


    // Calculando o tempo de cada execução:

    clock_t t; // Variável para armazenar o tempo;



    t = clock();//Armazena tempo antes da chamada da funcão


    // Inserir função aqui:

    bubbleSort(v,8);

    t= clock() - t;// Tempo final - Tempo inicial;

    printf("%d ", loop);
    printf(" execucao");
    printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    printf(" milissegundos.\n \n");

}

    // Imprimir array

    for(int k = 0; k < cemk; k++)
    {
        //printf("%d ", cemk1[k]);
    }


    return 0;
}
