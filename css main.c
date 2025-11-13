#include <stdio.h>
#include <string.h>

/*
  Estrutura que representa um território no jogo War.
  Cada território tem um nome, uma cor de exército e uma quantidade de tropas.
*/
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio territorios[5]; // Vetor que armazena os 5 territórios
    int i;

    printf("=== Cadastro de Territórios ===\n");

    // Loop para cadastrar os 5 territórios
    for (i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", territorios[i].nome); // Lê o nome do território

        printf("Cor do exército: ");
        scanf("%s", territorios[i].cor); // Lê a cor do exército

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas); // Lê o número de tropas
    }

    // Exibe todos os territórios cadastrados
    printf("\n=== Territórios Cadastrados ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
