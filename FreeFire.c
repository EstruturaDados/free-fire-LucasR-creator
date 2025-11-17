#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// ================================
//   STRUCT DA MOCHILA
// ================================
typedef struct {
    char nome[100];
    int tipo;
    int quantidade;
    int prioridade; // 1 a 5
} Mochila;

// ================================
//   ENUM PARA O TIPO DE ORDENAÇÃO
// ================================
typedef enum {
    ORDENAR_NOME = 1,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} CriterioOrdenacao;

// ================================
//   INSERTION SORT
// ================================
int insertionSort(Mochila itens[], int n, CriterioOrdenacao criterio) {
    int comparacoes = 0;

    for (int i = 1; i < n; i++) {
        Mochila atual = itens[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;

            int precisaTrocar = 0;

            if (criterio == ORDENAR_NOME)
                precisaTrocar = strcmp(itens[j].nome, atual.nome) > 0;

            else if (criterio == ORDENAR_TIPO)
                precisaTrocar = itens[j].tipo > atual.tipo;

            else if (criterio == ORDENAR_PRIORIDADE)
                precisaTrocar = itens[j].prioridade > atual.prioridade;

            if (!precisaTrocar) break;

            itens[j + 1] = itens[j];
            j--;
        }

        itens[j + 1] = atual;
    }

    return comparacoes;
}

// ================================
//   BUSCA BINÁRIA POR NOME
// ================================
int buscaBinariaPorNome(Mochila itens[], int n, char alvo[]) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(alvo, itens[meio].nome);

        if (cmp == 0) return meio;
        else if (cmp > 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// ================================
//   ORDENAÇÃO DA MOCHILA
// ================================
void ordenarMochila(Mochila itens[], int contador) {
    int opcao;

    printf("\n===== ORDENAR MOCHILA =====\n");
    printf("1 - Ordenar por nome\n");
    printf("2 - Ordenar por tipo\n");
    printf("3 - Ordenar por prioridade\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    CriterioOrdenacao criterio;

    switch (opcao) {
        case 1: criterio = ORDENAR_NOME; break;
        case 2: criterio = ORDENAR_TIPO; break;
        case 3: criterio = ORDENAR_PRIORIDADE; break;
        default:
            printf("Opcao invalida!\n");
            return;
    }

    int comp = insertionSort(itens, contador, criterio);

    printf("\nMochila ordenada com sucesso!\n");
    printf("Comparacoes realizadas: %d\n", comp);
}

// ================================
//   BUSCAR UM ITEM
// ================================
void buscarItem(Mochila itens[], int contador) {
    char nomeBusca[100];

    printf("\nDigite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    // Verificar se está ordenado por nome
    for (int i = 1; i < contador; i++) {
        if (strcmp(itens[i - 1].nome, itens[i].nome) > 0) {
            printf("\n❌ ERRO: A mochila precisa estar ordenada por nome para usar busca binaria!\n");
            return;
        }
    }

    int indice = buscaBinariaPorNome(itens, contador, nomeBusca);

    if (indice == -1) {
        printf("\nItem não encontrado!\n");
    } else {
        printf("\n=== ITEM ENCONTRADO ===\n");
        printf("Nome: %s\n", itens[indice].nome);
        printf("Tipo: %d\n", itens[indice].tipo);
        printf("Quantidade: %d\n", itens[indice].quantidade);
        printf("Prioridade: %d\n", itens[indice].prioridade);
    }
}

// ================================
//   LISTAR ITENS
// ================================
void listarMochila(Mochila itens[], int contador) {
    printf("\n====== ITENS DA MOCHILA ======\n");

    if (contador == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("%d. %s | Tipo: %d | Quantidade: %d | Prioridade: %d\n",
               i + 1, itens[i].nome, itens[i].tipo, itens[i].quantidade, itens[i].prioridade);
    }
}

// ================================
//   PROGRAMA PRINCIPAL
// ================================
int main() {

    Mochila itens[50];
    int contador = 0;
    int opcao;

    while (1) {
        printf("\n====== MENU ======\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar mochila\n");
        printf("3 - Ordenar mochila\n");
        printf("4 - Buscar item\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nNome do item: ");
            scanf(" %[^\n]", itens[contador].nome);

            printf("Tipo do item (número): ");
            scanf("%d", &itens[contador].tipo);

            printf("Quantidade: ");
            scanf("%d", &itens[contador].quantidade);

            printf("Prioridade (1 a 5): ");
            scanf("%d", &itens[contador].prioridade);

            contador++;
            printf("Item adicionado!\n");
        }
        else if (opcao == 2) {
            listarMochila(itens, contador);
        }
        else if (opcao == 3) {
            ordenarMochila(itens, contador);
        }
        else if (opcao == 4) {
            buscarItem(itens, contador);
        }
        else if (opcao == 5) {
            printf("Saindo...\n");
            break;
        }
        else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
