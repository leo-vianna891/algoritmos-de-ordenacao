#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "algoritmos.c"

const int max_int = 1e8;

void menu0() {

    printf("-=-=-= Escolha o tamanho do vetor (ou -1 para encerrar): -=-=-=\n");
    printf("[1] 100\n");
    printf("[2] 1.000\n");
    printf("[3] 10.000\n");
    printf("[4] 100.000\n");

}

void menu1() {

    printf("-=-=-= Agora, escolha o estado inicial do vetor -=-=-=\n");
    printf("[1] Ordenado\n");
    printf("[2] Reverso\n");
    printf("[3] Aleatório\n");

    printf("=-=-=-=-=-=-=\n");
}

void menu2() {
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

void init_vet(int tam, int vet[], int type) {
    
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
            for (int i = 0; i < tam; i++) vet[i] = (rand() % (max_int)) + 1; 
            break;
    }
}

int main() {

    srand(time(NULL));

    while (true) {

        //Vetor e seu tamanho
        menu0();
        int tam;
        scanf("%d", &tam);

        //Tratamento da entrada
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
        int *vet = (int*) malloc(sizeof(int) * tam); //Alocando na heap para evitar seg fault (principalmente no ContagemDosMenores)
        




        //Escolha do estado inicial do vetor
        menu1();
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
        menu2();
        int alg;
        scanf("%d", &alg);

        while (alg < 1 || alg > 9) {
            
            printf("Por favor, digite um valor válido.\n");
            scanf("%d", &alg);
        }






        //Variáveis para medir o tempo e fazer contagens
        clock_t start, end;
        double tempo = 0.0;
        ll mov = 0, comp = 0; //Movimentos e comparações

        bool correto = true; 
        for (int i = 1; i <= reps; i++) {

            //Em cada repetição, vamos repopular o vetor (relevante apenas para o caso de vetor aleatório)
            init_vet(tam, vet, estado);
            
            start = clock();
            switch (alg) {

                case 1: bubbleSort(vet, tam, &comp, &mov); break;
                case 2: selectionSort(vet, tam, &comp, &mov); break;
                case 3: insertionSort(vet, tam, &comp, &mov); break;
                case 4: shellSort(vet, tam, &comp, &mov); break;
                case 5: quickSort(vet, tam, &comp, &mov); break;
                case 6: heapSort(vet, tam, &comp, &mov); break;
                case 7: mergeSort(vet, tam, &comp, &mov); break;
                case 8: contagemDosMenores(vet, tam, &comp, &mov); break;
                case 9: radixSort(vet, tam, &comp, &mov); break;
            }
            end = clock();

            tempo += (double) (end - start) / CLOCKS_PER_SEC;
                        
        }

        //Resultados médios
        tempo /= reps;
        comp /= reps;
        mov /= reps;

        printf("=-=-=- RESULTADOS -=-=-=\n");
        //Verificação da ordenação (crescente)
        for (int i = 1; i < tam; i++) {

            //printf("%d ", vet[i]); //se preferir, descomente para imprimir tudo

            if (vet[i-1] > vet[i]) 
                correto = false;
        }
        printf("\n");
        free(vet);

        if (correto) printf("Ordenação realizada com sucesso.\n");
        else printf("Um erro de ordenação foi encontrado.\n");

        printf("O algoritmo foi executado %d vez(es).\n", reps);
        printf("Número de Comparações: %lld\n", comp);
        printf("Número de Movimentos: %lld\n", mov);
        printf("Tempo (médio) de execução: %.6lf segundo(s).\n", tempo);

    }
}