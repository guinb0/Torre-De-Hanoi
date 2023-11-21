#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int items[MAX_DISKS];
    int top;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->top = -1;
}

int estaVazia(Pilha *pilha) {
    return pilha->top == -1;
}

int estaCheia(Pilha *pilha) {
    return pilha->top == MAX_DISKS - 1;
}

void empilhar(Pilha *pilha, int disco) {
    if (!estaCheia(pilha)) {
        pilha->items[++pilha->top] = disco;
    }
}
