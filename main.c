#include <stdio.h>
#include <stdlib.h>

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
    printf("\nEstado Atual das Torres:\n\n");

    for (int i = numDiscos - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i <= torres[j].top) {
                for (int k = 0; k < torres[j].items[i]; k++) {
                    printf("*");
                }
              } else {
                          printf("");
                      }
                      printf("                    ");
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

    // Verificar se todos os discos estão na torre 3 e em ordem correta
    for (int i = 0; i < numDiscos; i++) {
        if (torre3->items[i] != i + 1) {
            return 0; // Nem todos os discos estão na torre 3 ou estão fora de ordem
        }
    }
    return 1; // Todos os discos estão na torre 3 e em ordem correta
}

//É a função main do código que executa todas as outras funções e faz o jogo Torre de Hanoi acontecer.
int main() {
    int torreOrigem, torreDestino;
    int escolha;
    int numJogadas = 0;
    int numDiscos;
    printf("Digite o número de discos (1 a 8): ");
   
    scanf("%d", &numDiscos);
    while (numDiscos > 8 || numDiscos < 1) {
    printf("\nO Máximo permitido é de 8 discos, digite um valor válido:" );
    scanf("%d", &numDiscos);
  }
  
    Pilha torre1, torre2, torre3;
    inicializar(&torre1);
    inicializar(&torre2);
    inicializar(&torre3);

    resetarTorres(&torre1, &torre2, &torre3, numDiscos);
    
    do {
        printf("\033c");
        imprimirTorres((Pilha[]){torre1, torre2, torre3}, numDiscos);
        printf("\nNúmero de jogadas: %d\n", numJogadas);
        printf("\n");
        printf("\n|Para sair do jogo digite 0 ao invés do número da torre|\n");
        printf("Digite o número da torre de origem (1, 2 ou 3): ");
        scanf("%d", &torreOrigem);
      
        if (torreOrigem == 0){
        printf("\nDeseja recomeçar o jogo? (1 - sim | 0 - Não)"); 
        scanf("%d", &escolha);
        if (escolha == 1){
          printf("\n");
          return main();
        }else{
          exit(0);
        }}
      
        printf("Digite o número da torre de destino (1, 2 ou 3):");
        scanf("%d", &torreDestino);
        printf("\n");

        if (torreDestino == 0){
        printf("\nDeseja recomeçar o jogo? (1 - sim | 0 - Não)"); 
        scanf("%d", &escolha);
        if (escolha == 1){
          printf("\n");
          return main();
        }else{
          exit(0);
        }}
      
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
                numJogadas = numJogadas + 1;
                break;
            case 2:
                pilhaDestino = &torre2;
                numJogadas = numJogadas + 1;
                break;
            case 3:
                pilhaDestino = &torre3;
                numJogadas = numJogadas + 1;
                break;
            default:
                printf("Torre de destino inválida.\n");
                continue;
        }

        moverDisco(pilhaOrigem, pilhaDestino, torreOrigem + 'A' - 1, torreDestino + 'A' - 1);

        
    } while (1);

    return 0;
}
