#ifndef SORT_H
#define SORT_H

void troca(int* v, int i, int j);

void selectionSort(int* v, int tamanho);

void bubbleSort(int* v, int n);

void insertionSort(int* v, int tamanho);

void merge(int* v, int tamV, int* e, int tamE, int* d, int tamD);

void mergeSort(int* v, int tamV);

int particiona(int* v, int ini, int fim);

void quickSort(int* v, int ini, int fim);

int particiona_random(int* v, int ini, int fim);

void quickSortRandomPivot(int* v, int ini, int fim);

int particionaTest(int* v, int ini, int fim);

void quickSortTest(int* v, int ini, int fim);


#endif // SORT_H
