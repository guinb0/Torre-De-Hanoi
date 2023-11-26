#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Define um "macro".
#define MAX_DISKS 8

//Criando pilha
typedef struct {
    int items[MAX_DISKS];
    int top;
} Pilha;

//Configura o estado inicial de uma pilha, definindo o topo (top) como -1, indicando uma pilha vazia.
void inicializar(Pilha *pilha) {
    pilha->top = -1;
}

//A função verifica se o topo (top) da pilha é igual a -1, indicando que não há elementos na pilha.
int estaVazia(Pilha *pilha) {
    return pilha->top == -1;
}

//A função verifica se o topo (top) da pilha é igual a MAX_DISKS - 1, se o topo estiver nesse valor, a pilha está cheia.
int estaCheia(Pilha *pilha) {
    return pilha->top == MAX_DISKS - 1;
}

//A função adiciona um elemento à pilha. Ela recebe um ponteiro para uma estrutura do tipo Pilha e um inteiro disco que representa o disco a ser empilhado.
void empilhar(Pilha *pilha, int disco) {
    if (!estaCheia(pilha)) {
        pilha->items[++pilha->top] = disco;
    }
}

//A função remove e retorna o elemento do topo da pilha, a menos que a pilha esteja vazia, caso em que retorna -1.
int desempilhar(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        return pilha->items[pilha->top--];
    }
    return -1; // Indica que a pilha está vazia
}

//A função exibe visualmente o estado atual de três torres, representadas por uma estrutura Pilha, no console. Ela imprime asteriscos para representar os discos empilhados em cada torre.
void imprimirTorres(Pilha *torres, int numDiscos) {
    system("clear");  // Use "cls" no Windows / clear no resto
    printf("\nEstado Atual das Torres:\n\n");

    // Largura fixa de cada disco
    int larguraDisco = 5;
    // Espaçamento entre torres
    int espacamentoEntreTorres = 20;

    for (int i = numDiscos - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i <= torres[j].top) {
                // Calcular espaçamento para centralizar o disco
                int espacosAntes = (larguraDisco - torres[j].items[i]) / 2;
                int espacosDepois = larguraDisco - torres[j].items[i] - espacosAntes;

                // Imprimir espaços antes do disco
                for (int k = 0; k < espacosAntes; k++) {
                    printf(" ");
                }

                // Imprimir o disco
                for (int k = 0; k < torres[j].items[i]; k++) {
                    printf("*");
                }

                // Imprimir espaços depois do disco
                for (int k = 0; k < espacosDepois; k++) {
                    printf(" ");
                }
            } else {
                // Imprimir espaços para manter o alinhamento
                for (int k = 0; k < larguraDisco; k++) {
                    printf(" ");
                }
            }

            // Adicionar espaçamento entre as torres
            for (int k = 0; k < espacamentoEntreTorres; k++) {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("Torre %d               ", i + 1);
    }
    printf("\n\n");
}





int verificarMovimentoValido(Pilha *origem, Pilha *destino) {
    // Verificar se a torre de destino está vazia ou se o topo da torre de destino         é maior que o disco a ser movido
    return estaVazia(destino) || origem->items[origem->top] < destino->items[destino->top];
}

//A função move um disco de uma torre para outra, validando o movimento. Se válido, realiza a movimentação e exibe uma mensagem; caso contrário, imprime uma mensagem de erro.
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

//A função reinicializa as torres. Ela chama a função inicializar para cada torre, configurando o topo como -1, indicando que estão vazias. Em seguida, empilha os discos na primeira torre, de acordo com o número especificado (numDiscos), criando assim uma configuração inicial.
void resetarTorres(Pilha *torre1, Pilha *torre2, Pilha *torre3, int numDiscos) {
    inicializar(torre1);
    inicializar(torre2);
    inicializar(torre3);

    // Empilhar os discos na torre 1
    for (int i = numDiscos; i >= 1; i--) {
        empilhar(torre1, i);
    }
}

int verificarVitoria(Pilha *torres[], int numDiscos) {
    Pilha *torre3 = torres[2];

    // Verificar se a torre 3 está cheia
    if (torre3->top != numDiscos - 1) {
        return 0; // A torre 3 não está cheia
    }

    // Verificar se os discos estão em ordem correta
    for (int i = 0; i < numDiscos; i++) {
        if (torre3->items[i] != numDiscos - i) {
            return 0; //Os discos ou estão em falta
        }
    }

    return 1; // Todos os discos estão ordem correta
}

int exibirMenuInicio() {
    int escolha;
    printf("\033c");
    printf("Bem-vindo ao Jogo da Torre de Hanoi!\n");
    printf("1. Iniciar o jogo\n");
    printf("0. Sair\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}
