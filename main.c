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
void empilhar(Pilha *pilha, int disco) {
    if (!estaCheia(pilha)) {
        pilha->items[++pilha->top] = disco;
    }
}
int desempilhar(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        return pilha->items[pilha->top--];
    }
    return -1; // Indica que a pilha está vazia
}

void imprimirTorres(Pilha *torres, int numDiscos) {
    printf("\nEstado Atual das Torres:\n\n");

    for (int i = numDiscos - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i <= torres[j].top) {
                for (int k = 0; k < torres[j].items[i]; k++) {
                    printf("* ");
                }
            } else {
                printf("| ");
            }
            printf("   ");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("  Torre %d  ", i + 1);
    }

    printf("\n\n");
}
