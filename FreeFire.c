#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int tipo;
    int quantidade;
} Mochila;

int main() {

    Mochila itens[15];
    int opcao;
    int contador = 0;

    do {
        printf("\n===== MENU DA MOCHILA =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Mostrar itens\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (contador < 15) {
                    printf("\nDigite o nome do item: ");
                    scanf(" %[^\n]", itens[contador].nome);

                    printf("Digite o tipo do item (numero): ");
                    scanf("%d", &itens[contador].tipo);

                    printf("Digite a quantidade: ");
                    scanf("%d", &itens[contador].quantidade);

                    contador++;
                } else {
                    printf("Mochila cheia!\n");
                }
                break;

            case 2:
                printf("\n===== Itens na mochila =====\n");
                for (int i = 0; i < contador; i++) {
                    printf("%d - %s (Tipo %d) x%d\n",
                           i+1,
                           itens[i].nome,
                           itens[i].tipo,
                           itens[i].quantidade);
                }
                break;

            case 3:
                printf("Fechando mochila...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    return 0;
}
