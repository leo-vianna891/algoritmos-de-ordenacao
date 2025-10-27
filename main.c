#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.c"

const int max_int = 1e5;

void menu0() {

    printf("-=-=-= Escolha o tamanho do vetor (ou -1 para encerrar): -=-=-=\n");
    printf("[1] 100\n");
    printf("[2] 1.000\n");
    printf("[3] 10.000\n");
    printf("[4] 100.000\n");

}

void menu() {
    printf("-=-=-= Escolha qual algoritmo de ordenação será usado: =-=-=-\n");

    printf("[1] BubbleSort\n");
    printf("[2] Selection\n");
    printf("[3] Insertion\n");
    printf("[4] ShellSort\n");
    printf("[5] QuickSort\n");
    printf("[6] HeapSort\n");
    printf("[7] MergeSort\n");
    printf("[8] Contagem dos Menores\n");
    printf("[9] RadixSort\n");

    printf("Digite qualquer outro valor para sair.\n");
    printf("=-=-=-=-=-=-=\n");
}

void menu2() {

    printf("-=-=-= Agora, escolha o estado inicial do vetor -=-=-=\n");
    printf("[1] Ordenado\n");
    printf("[2] Reverso\n");
    printf("[3] Aleatório\n");

    printf("=-=-=-=-=-=-=\n");
}

void init_vet(int tam, int vet[], int type) {
    
    // Assegura que os números aleatórios sejam diferentes em cada execução
    srand(time(NULL)); 

    switch (type) {
        
        // 1: Ordenado (Crescente)
        case 1:
            for (int i = 0; i < tam; i++) vet[i] = i + 1; 
            break;

        // 2: Reverso (Decrescente)
        case 2:
            for (int i = 0; i < tam; i++) vet[i] = tam - i; 
            break;

        // 3: Aleatório
        case 3:
            for (int i = 0; i < tam; i++) {
                
                // Gera números aleatórios de 1 até 10^5 (mais que isso pode dar problema nos algoritmos contagem de menores e radix)
                vet[i] = (rand() % (max_int)) + 1; 
            }
            break;
    }
}

int main() {

    while (true) {

        //Vetor e seu tamanho
        menu0();
        int tam;
        scanf("%d", &tam);

        if (tam == -1) break;
        while (tam < 1 || tam > 4) {

            printf("Por favor, digite um valor válido.\n");
            scanf("%d", &tam);
        }

        switch (tam) {

            case 1: tam = 100; break;
            case 2: tam = 1000; break;
            case 3: tam = 10000; break;
            case 4: tam = 100000; break;
        }
        int vet[tam];


        //Escolha do estado inicial do vetor
        menu2();
        int estado;
        scanf("%d", &estado);

        while (estado < 1 || estado > 3) {

            printf("Por favor, digite um valor válido.\n");
            scanf("%d", &estado);
        }
        
        //Definindo quantas vezes vamos realizar a ordenação
        int reps = 1;
        if (estado == 3) reps = 5; //5 vezes para um vetor aleatório

        //Escolha do algoritmo de ordenação
        menu();
        int alg;
        scanf("%d", &alg);

        while (alg < 1 || alg > 9) {
            
            printf("Por favor, digite um valor válido.\n");
            scanf("%d", &alg);
        }

        for (int i = 1; i <= reps; i++) {

            //Em cada repetição, vamos repopular o vetor (relevante apenas para o caso de vetor aleatório)
            switch (estado) {
                case 1: init_vet(tam, vet, 1); break;
                case 2: init_vet(tam, vet, 2); break;
                case 3: init_vet(tam, vet, 3); break;
            }
            
            switch (alg) {

                case 1: bubbleSort(vet, tam); break;
                case 2: selectionSort(vet, tam); break;
                case 3: insertionSort(vet, tam); break;
                case 4: shellSort(vet, tam); break;
                case 5: quickSort(vet, tam); break;
                case 6: heapSort(vet, tam); break;
                case 7: mergeSort(vet, tam); break;
                case 8: contagemDosMenores(vet, tam); break;
                case 9: radixSort(vet, tam); break;
            }
                        
                //Verificação da ordenação (crescente)
                int correto = true;
                for (int i = 1; i < tam; i++) {

                    //printf("%d ", vet[i]); //se preferir, descomente para imprimir tudo

                    if (vet[i-1] > vet[i]) 
                        correto = false;
                }
                printf("\n");

                if (correto) printf("Ordenação CORRETA!\n\n");
                else printf("Ordenação ERRADA!\n\n");
        }
    }
}