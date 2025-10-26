#include <math.h>
#include "fila.c"
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void swap (int *a, int *b) {

    int aux = *a;
    *a = *b;
    *b = aux;
}



//BubbleSort: Compara pares de elementos adjacentes e os troca se estiverem na ordem errada.
void bubbleSort(int vetor[], int tam) {

    ll comparacoes = 0, movimentos = 0;

    int troca;
    for (int i = 0; i < tam - 1; i++) {

        troca = 0;
        for (int j = 0; j < tam - i - 1; j++) {
            
            comparacoes++;
            if (vetor[j] > vetor[j+1]) {

                swap(&vetor[j], &vetor[j+1]);
                movimentos += 3; // São 3 movimentos na função swap
                troca = 1;
            }

        }

        //Sem não tem trocas, o vetor está ordenado
        if (!troca) break;
    }
    
    printf("Número de Comparações: %lld\n", comparacoes);
    printf("Número de Movimentos: %lld\n", movimentos);
}

/*
SelectionSort: Encontra o menor elemento e o coloca na primeira posição, repetindo para o restante do vetor.
*/
void selectionSort(int vetor[], int tam) {
    int comparacoes = 0, movimentos = 0;
    for (int i = 0; i < tam - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            comparacoes++;
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&vetor[i], &vetor[min_idx]);
            movimentos += 3;
        }
    }
    printf("Número de Comparações: %d\n", comparacoes);
    printf("Número de Trocas: %d\n", movimentos);
}


/*
Insertion: coloca o i-ésimo elemento na sua posição correta
*/
void insertionSort(int vetor[], int tam) {

    int j;
    int comparacoes = 0, movimentos = 0;
    for (int i = 1; i < tam; i++) {

        int atual = vetor[i];
        j = i;
        
        while (j && vetor[j-1] > atual) {
            
            vetor[j] = vetor[j-1];
            j--;

            comparacoes++;
            movimentos++;
        }
        if (j) comparacoes++;

        vetor[j] = atual;
        movimentos++;
    }

    printf("Número de Comparações: %d\n", comparacoes);
    printf("Número de Trocas: %d\n", movimentos);
}


void shellSort(int vetor[], int tamv) {

    int tamh = log2(2*tamv + 1)/log2(3); 
    int h[tamh];

    //Incrementos necessários para o shellSort (explicação detalhada no relatório)
    h[0] = 1;
    for (int i = 1; i < tamh; i++) {
        h[i] = 3*h[i-1] + 1;
    }
    
    //Algoritmo principal
    int comparacoes = 0;
    for (int i = tamh - 1; i >= 0; i--) {

        int inc = h[i];
        for (int j = inc; j < tamv; j += inc) {

            int atual = vetor[j];
            int k = j;
            
            comparacoes++;
            while (k && vetor[k-1] > atual) {

                vetor[k] = vetor[k-1];
                k -= inc;
            }

            vetor[k] = atual;
        }
    }
}


//=-=-=- Espaço QuickSort abaixo -=-=-=
int particiona(int vetor[], int inicio, int fim, int *comp, int *mov) {
    // Mediana de 3 para escolher o pivô
    int meio = (inicio + fim) / 2;
    if (vetor[inicio] > vetor[meio]) { (*comp)++; swap(&vetor[inicio], &vetor[meio]); (*mov)+=3; }
    if (vetor[inicio] > vetor[fim]) { (*comp)++; swap(&vetor[inicio], &vetor[fim]); (*mov)+=3; }
    if (vetor[meio] > vetor[fim]) { (*comp)++; swap(&vetor[meio], &vetor[fim]); (*mov)+=3; }
    
    int pivo = vetor[meio];
    swap(&vetor[meio], &vetor[fim - 1]); // Coloca o pivô em fim-1
    (*mov)+=3;

    int i = inicio;
    int j = fim - 1;
    
    while(1) {
        while(vetor[++i] < pivo) { (*comp)++; }
        (*comp)++;
        while(vetor[--j] > pivo) { (*comp)++; }
        (*comp)++;
        if (i < j) {
            swap(&vetor[i], &vetor[j]);
            (*mov)+=3;
        } else {
            break;
        }
    }
    
    swap(&vetor[i], &vetor[fim-1]); // Restaura o pivô
    (*mov)+=3;
    
    return i;
}

void quickSort_recursivo(int vetor[], int inicio, int fim, int *comparacoes, int *movimentos) {
    if (inicio < fim) {
        int pivo_idx = particiona(vetor, inicio, fim, comparacoes, movimentos);
        quickSort_recursivo(vetor, inicio, pivo_idx - 1, comparacoes, movimentos);
        quickSort_recursivo(vetor, pivo_idx + 1, fim, comparacoes, movimentos);
    }
}

void quickSort(int vetor[], int tam) {
    int comparacoes = 0, movimentos = 0;
    quickSort_recursivo(vetor, 0, tam - 1, &comparacoes, &movimentos);
    printf("Número de Comparações: %d\n", comparacoes);
    printf("Número de Trocas: %d\n", movimentos);
}
// =-=-=- Fim do Espaço QuickSort -=-=-=



//=-=-=- Espaço heapSort abaixo -=-=-=
void heapDown(int vetor[], int pai, int tam) {

    int esq = 2*pai + 1;
    int dir = 2*pai + 2;

    int maior = pai;

    if (esq < tam && vetor[esq] > vetor[maior]) maior = esq;
    if (dir < tam && vetor[dir] > vetor[maior]) maior = dir;

    if (maior != pai) {

        swap(&vetor[maior], &vetor[pai]);
        heapDown(vetor, maior, tam);
    }
}

void heapBuild(int vetor[], int tam) {

    for (int i = tam/2; i >= 0; i--) 
        heapDown(vetor, i, tam);

}

void heapSort(int vetor[], int tam) {

    heapBuild(vetor, tam);

    int aux = tam;
    for (int i = 1; i <= tam; i++) {

        swap(&vetor[0], &vetor[aux-1]);

        aux--;
        heapDown(vetor, 0, aux);
    }
}
// =-=-=- Fim do Espaço heapSort -=-=-=


// =-=-=- Espaço MergeSort abaixo -=-=-=
void merge(int vetor[], int l, int m, int r, int *comp, int *mov) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = vetor[l + i];
        (*mov)++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[m + 1 + j];
        (*mov)++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comp)++;
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        (*mov)++;
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        (*mov)++;
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        (*mov)++;
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort_recursivo(int vetor[], int l, int r, int *comparacoes, int *movimentos) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_recursivo(vetor, l, m, comparacoes, movimentos);
        mergeSort_recursivo(vetor, m + 1, r, comparacoes, movimentos);
        merge(vetor, l, m, r, comparacoes, movimentos);
    }
}

void mergeSort(int vetor[], int tam) {
    int comparacoes = 0, movimentos = 0;
    mergeSort_recursivo(vetor, 0, tam - 1, &comparacoes, &movimentos);
    printf("Número de Comparações: %d\n", comparacoes);
    printf("Número de Trocas: %d\n", movimentos);
}
// =-=-=- Fim do Espaço MergeSort -=-=-=


// =-=-=- Espaço Contagem dos Menores -=-=-=
void contagemDosMenores(int vetor[], int tam) {
    if (tam <= 0) return;
    int movimentos = 0, comparacoes = 0;

    int maior = vetor[0];
    for (int i = 1; i < tam; i++) {
        comparacoes++;
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    int* contagem = (int*) calloc(maior + 1, sizeof(int));

    for (int i = 0; i < tam; i++) {
        contagem[vetor[i]]++;
        movimentos++;
    }

    int index = 0;
    for (int i = 0; i <= maior; i++) {
        while (contagem[i] > 0) {
            vetor[index++] = i;
            contagem[i]--;
            movimentos++;
        }
    }
    free(contagem);
    printf("Número de Comparações: %d (para achar o maior)\n", comparacoes);
    printf("Número de Movimentos: %d (escrita no vetor de contagem e no original)\n", movimentos);
}
// =-=-=- Fim do Espaço Contagem dos Menores -=-=-=


// =-=-=- Espaço Radix Sort -=-=-=
int get_digit(int x, int exp) {

    int ans = (x / exp) % 10;
    return ans;
}

void radixSort(int vetor[], int tam) {

    FILA *filas[10];
    for (int i = 0; i < 10; i++) 
        filas[i] = fila_criar();

    //Achando o maior elemento
    int maior = -2e9;
    for (int i = 0; i < tam; i++) 
        maior = (vetor[i] > maior) ? vetor[i] : maior;


    int d;
    for (int exp = 1; exp <= maior; exp *= 10) {

        //Inserindo na fila com base no dígito
        for (int j = 0; j < tam; j++) {

            d = get_digit(vetor[j], exp);
            fila_inserir(filas[d], vetor[j]);
        }

        //Esvaziando a fila
        int id = 0;
        for (int j = 0; j < 10; j++) {

            while (!fila_vazia(filas[j])) {
                
                vetor[id] = fila_remover(filas[j]);
                id++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {

        while (!fila_vazia(filas[i])) fila_remover(filas[i]);
        free(filas[i]);
    }
}
    