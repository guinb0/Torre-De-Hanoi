#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"


//É a função main do código que executa todas as outras funções e faz o jogo Torre de Hanoi acontecer.
int main() {
    int torreOrigem, torreDestino;
    int escolha;
    int numJogadas = 0;
    int numDiscos;
    printf("\033c");
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

      if (verificarVitoria((Pilha *[]){&torre1, &torre2, &torre3}, numDiscos)) {
          printf("\033c");
          imprimirTorres((Pilha[]){torre1, torre2, torre3}, numDiscos);
          printf("\nParabéns! Número de movimentos: %d\n", numJogadas);
          printf("\nDeseja recomeçar o jogo? (1 - sim | 0 - Não)");
          scanf("%d", &escolha);
          if (escolha == 1){
            printf("\n");
            return main();
          }else{
            exit(0);
          }
      }
    printf("\033c");
    } while (1);

    return 0;
}
