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
int verificarMovimentoValido(Pilha *origem, Pilha *destino) {
    // Verificar se a torre de destino está vazia ou se o topo da torre de destino é maior que o disco a ser movido
    return estaVazia(destino) || origem->items[origem->top] < destino->items[destino->top];
}

void moverDisco(Pilha *origem, Pilha *destino, char nomeOrigem, char nomeDestino) {
    if (verificarMovimentoValido(origem, destino)) {
        int disco = desempilhar(origem);
        if (disco != -1) {
            empilhar(destino, disco);
            printf("Mover disco %d da Torre %c para a Torre %c\n", disco, nomeOrigem, nomeDestino);
        }
    } else {
        printf("Movimento inválido. Impossível colocar um disco maior em cima de um disco menor.\n");
    }
}

void resetarTorres(Pilha *torre1, Pilha *torre2, Pilha *torre3, int numDiscos) {
    inicializar(torre1);
    inicializar(torre2);
    inicializar(torre3);

    // Empilhar os discos na torre 1
    for (int i = numDiscos; i >= 1; i--) {
        empilhar(torre1, i);
    }
}

int main() {
    int numDiscos;
    printf("Digite o número de discos: ");
    scanf("%d", &numDiscos);

    Pilha torre1, torre2, torre3;
    inicializar(&torre1);
    inicializar(&torre2);
    inicializar(&torre3);

    resetarTorres(&torre1, &torre2, &torre3, numDiscos);

    do {
        imprimirTorres((Pilha[]){torre1, torre2, torre3}, numDiscos);

        int torreOrigem, torreDestino;
        printf("Digite o número da torre de origem (1, 2 ou 3): ");
        scanf("%d", &torreOrigem);

        printf("Digite o número da torre de destino (1, 2 ou 3): ");
        scanf("%d", &torreDestino);

        Pilha *pilhaOrigem, *pilhaDestino;
        switch (torreOrigem) {
    case 1:
        pilhaOrigem = &torre1;
        break;
    case 2:
        pilhaOrigem = &torre2;
        break;
    case 3:
        pilhaOrigem = &torre3;
        break;
    default:
        printf("Torre de origem inválida.\n");
        continue;
}

switch (torreDestino) {
    case 1:
        pilhaDestino = &torre1;
        break;
    case 2:
        pilhaDestino = &torre2;
        break;
    case 3:
        pilhaDestino = &torre3;
        break;
    default:
        printf("Torre de destino inválida.\n");
        continue;
}


        moverDisco(pilhaOrigem, pilhaDestino, torreOrigem + 'A' - 1, torreDestino + 'A' - 1);

        int escolha;
        printf("Deseja continuar movendo discos? (1: Sim, 0: Não): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        }

    } while (1);

    int reiniciar;
    printf("Deseja reiniciar as torres? (1: Sim, 0: Não): ");
    scanf("%d", &reiniciar);

    if (reiniciar == 1) {
        resetarTorres(&torre1, &torre2, &torre3, numDiscos);
        imprimirTorres((Pilha[]){torre1, torre2, torre3}, numDiscos);
    }

    return 0;
}

