#include <stdio.h>
#include <stdlib.h>
#include <sort.h>


void selectionSort(int* v, int tamanho){

    for(int i = 0; i < (tamanho - 1); i++)
    {
        int iMenor = i;
        for(int j = i+1; j < tamanho; j++)
        {
            if(v[j] < v[iMenor])
            {
                iMenor = j;
            }
        }
       troca(v,i,iMenor);
    }
}

void troca(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


void bubbleSort(int* v, int n){
    for(int varredura = 0; varredura < n-1; varredura++){
        bool trocou = false;
        for(int i = 0; i < n-varredura-1; i++){
            if(v[i]>v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = true;     
            }
        }
        if(trocou==false)
            return;

    printf("%d ",varredura);
    }

}

void insertionSort(int* v, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int valor = v[i];
        int j;
        for (j = i; j > 0 && v[j - 1] > valor; j--) {
            v[j] = v[j - 1];
        }
        v[j] = valor;
    }
}


void merge(int* v, int tamV, int* e, int tamE, int* d, int tamD){
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;
    while(indexE < tamE && indexD < tamD){
        if(e[indexE] <= d[indexD]){
            v[indexV] = e[indexE];
            indexE++;
        } else{
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    while(indexE < tamE){
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    while(indexD < tamD){
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int* v, int tamV){
    if(tamV>1){
        int meio = tamV/2;

        int tamV1 = meio;
        int* v1 = (int*)malloc(tamV1*sizeof(int));
        for(int i = 0; i < meio; i++){
            v1[i] = v[i];
        }

        int tamV2 = tamV-meio;
        int* v2 = (int*)malloc(tamV2*sizeof(int));
        for(int i = meio; i < tamV; i++){
            v2[i-meio] = v[i];
        }

        mergeSort(v1,tamV1);
        mergeSort(v2,tamV2);
        merge(v,tamV,v1,tamV1,v2,tamV2);

        free(v1);
        free(v2);
    }
}

void quickSort(int* v, int ini, int fim){
    if(fim>ini){
        int indexPivo = particiona(v,ini,fim);
        quickSort(v,ini,indexPivo-1);
        quickSort(v,indexPivo+1,fim);
    }
}

int particiona(int* v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            troca(v,i,pIndex);
            pIndex++;
        }
    }
    troca(v,pIndex,fim);
    return pIndex;
}

int particiona_random(int* v, int ini, int fim)
{
    int r = ini + rand() % (fim-ini+1);
    troca(v,r,fim);
    return particiona(v,ini,fim);
}

void quickSortRandomPivot(int* v, int ini, int fim){
    if(fim>ini){
        int indexPivo = particiona_random(v,ini,fim);
        quickSortRandomPivot(v,ini,indexPivo-1);
        quickSortRandomPivot(v,indexPivo+1,fim);
    }
}

/*
int particionaTest(int* v, int ini, int fim){
    int pIndex = ini - 1;
    int pivo = v[fim];
    for(int i = ini; i <= fim - 1; i++){
        if(v[i] < pivo){
            pIndex++;
            troca(v,i,pIndex);

        }
    }
    troca(v,pIndex + 1,fim);
    return pIndex + 1;
}

void quickSortTest(int* v, int ini, int fim){
    if(ini<fim){
        int indexPivo = particionaTest(v,ini,fim);
        quickSortTest(v,ini,indexPivo-1);
        quickSortTest(v,indexPivo+1,fim);
    }
}
*/
