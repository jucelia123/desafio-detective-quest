// ===========================================================
// Projeto: Detective Quest - Sistema de Inventário (Nível 2)
// Desenvolvido por: Jucélia Amorim
// Objetivo: Criar e gerenciar um inventário com até 10 itens,
// permitindo cadastrar, remover, listar e buscar itens.
// ===========================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10  // quantidade máxima de itens na mochila

// Estrutura que representa um item do inventário
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Funções do sistema
void inserirItem(struct Item mochila[], int *contador);
void removerItem(struct Item mochila[], int *contador);
void listarItens(struct Item mochila[], int contador);
void buscarItem(struct Item mochila[], int contador);

int main() {
    struct Item mochila[MAX_ITENS];
    int contador = 0; // número atual de itens cadastrados
    int opcao;

    printf("=== SISTEMA DE INVENTÁRIO ===\n");

    // menu principal
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch(opcao) {
            case 1:
                inserirItem(mochila, &contador);
                break;
            case 2:
                removerItem(mochila, &contador);
                break;
            case 3:
                listarItens(mochila, contador);
                break;
            case 4:
                buscarItem(mochila, contador);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

// Função para inserir um novo item na mochila
void inserirItem(struct Item mochila[], int *contador) {
    if (*contador >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n--- Inserir Novo Item ---\n");
    printf("Nome do item: ");
    scanf("%s", mochila[*contador].nome);
    printf("Tipo (arma, munição, cura, ferramenta...): ");
    scanf("%s", mochila[*contador].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[*contador].quantidade);

    (*contador)++;
    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item pelo nome
void removerItem(struct Item mochila[], int *contador) {
    if (*contador == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // move os itens seguintes para preencher o espaço vazio
            for (int j = i; j < *contador - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*contador)--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado)
        printf("Item não encontrado.\n");
}

// Função para listar todos os itens cadastrados
void listarItens(struct Item mochila[], int contador) {
    if (contador == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < contador; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItem(struct Item mochila[], int contador) {
    if (contador == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado.\n");
}
