/*## 2. Gerenciador de Contatos

### Objetivo

Desenvolver uma agenda digital simples.

### Funcionalidades

* adicionar contatos;
* buscar contatos;
* editar contatos;
* remover contatos;
* listar contatos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximo de contatos.

#define MAX_CONTATOS 100

//Estrutura para armazenar os dados dos contatos.

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

// Variável global para armazenar os contatos.
Contato agenda[MAX_CONTATOS];
int num_contatos = 0;

// Função para adicionar um contato.
void adicionar_contato() {
}

// Função para buscar um contato.
void buscar_contato() {
}

// Função para editar um contato.
void editar_contato() {
}

// Função para remover um contato.
void remover_contato() {
}

// Função para listar os contatos.
void listar_contatos() {
}

// Função principal.
int main() {
    int opcao;

    do {
        printf("Gerenciador de Contatos\n");
        printf("1. Adicionar Contato\n");
        printf("2. Buscar Contato\n");
        printf("3. Editar Contato\n");
        printf("4. Remover Contato\n");
        printf("5. Listar Contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                adicionar_contato();
                break;
            case 2:
                buscar_contato();
                break;
            case 3:
                editar_contato();
                break;
            case 4:
                remover_contato();
                break;
            case 5:
                listar_contatos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}




