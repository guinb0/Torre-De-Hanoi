#include <stdio.h>
#include <stdlib.h>

// ... (o restante do código permanece inalterado)

// Função para exibir o menu de início
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

int main() {
    int escolhaInicio;

    // Loop principal
    do {
        escolhaInicio = exibirMenuInicio();

        switch (escolhaInicio) {
            case 1:
                // Código do jogo
                // ... (o restante do código permanece inalterado)
                break;
            case 0:
                printf("Obrigado por jogar. Até a próxima!\n");
                break;
            default:
                printf("Escolha inválida. Por favor, escolha uma opção válida.\n");
        }

    } while (escolhaInicio != 0);

    return 0;
}
