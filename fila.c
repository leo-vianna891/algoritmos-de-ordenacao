#include <stdlib.h>
#include <stdbool.h>

typedef struct no_ NO;
typedef struct fila_ FILA;

struct no_ {

    int valor;
    NO* proximo;
};

struct fila_ {

    NO* inicio;
    NO* fim;
    int tamanho;
};

FILA* fila_criar() {

    FILA* fila = (FILA*) malloc(sizeof(FILA));

    if (fila != NULL) {

        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho = 0;
    }

    return fila;
}

bool fila_cheia(FILA* fila) {
    
    NO *n = (NO*) malloc(sizeof(NO));

    if (n) {

        free(n);
        return false;
    }

    return true;
}

bool fila_vazia(FILA* fila) {
    
    return (fila->tamanho == 0);
}

bool fila_inserir(FILA* fila, int valor) {

    if (fila != NULL && !fila_cheia(fila)) {

        NO* n = (NO*) malloc(sizeof(NO));
        
        n->valor = valor;
        n->proximo = NULL;

        if (fila->inicio == NULL) fila->inicio = n;
        else fila->fim->proximo = n;

        fila->fim = n;
        fila->tamanho++;

        return true;
    }

    return false;
}

int fila_remover(FILA* fila) {

    if (fila != NULL && !fila_vazia(fila)) {
        
        NO* n = fila->inicio;
        int valor = n->valor;

        fila->inicio = n->proximo;
        fila->tamanho--;

        free(n);
        if (fila_vazia(fila)) fila->fim = NULL;
        
        return valor;
    }

    return -1;
}