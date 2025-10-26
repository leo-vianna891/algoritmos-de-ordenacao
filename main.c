#include <stdio.h>
#include "algoritmos.c"

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

}

int main() {

    int vet[] = {3, 2, 1, 0, 0, 2, 0, 10, 7, 2};
    int tam = sizeof(vet) / sizeof(int);

    // Se a ideia for permitir o teste de múltiplos algoritmos em uma execução,
    // será preciso criar uma cópia do vetor para cada chamada,
    // pois os algoritmos ordenam o vetor original.
    // Nesse caso, também será necessário um menu em loop while,
    // com uma opção para sair do programa.

    menu();

    int op;
    scanf("%d", &op);
    switch (op) {

        case 1: bubbleSort(vet, tam); break;
        case 2: selectionSort(vet, tam); break;
        case 3: insertionSort(vet, tam); break;
        case 4: shellSort(vet, tam); break;
        case 5: quickSort(vet, tam); break;
        case 6: heapSort(vet, tam); break;
        case 7: mergeSort(vet, tam); break;
        case 8: contagemDosMenores(vet, tam); break;
        case 9: radixSort(vet, tam); break;

        default: printf("Opção inválida.\n");
    }

    int correto = 1;
    for (int i = 1; i < tam; i++) {

        printf("%d ", vet[i]);

        if (vet[i-1] > vet[i]) {
            correto = 0;
        }
    }
    printf("\n");

    if (correto) printf("Ordenação CORRETA!\n");
    else printf("Ordenação ERRADA!\n");
}