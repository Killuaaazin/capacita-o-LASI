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

// Função para limpar o terminal
void limpar_terminal() {
#ifdef _WIN32
    system("cls");
#endif
}

// Função para adicionar um contato.
void adicionar_contato() {
    limpar_terminal();
    if (num_contatos < MAX_CONTATOS) {
        printf("Digite o nome do contato: ");
        fgets(agenda[num_contatos].nome, sizeof(agenda[num_contatos].nome), stdin);
        agenda[num_contatos].nome[strcspn(agenda[num_contatos].nome, "\n")] = '\0'; // Remover a nova linha

        printf("Digite o telefone do contato: ");
        fgets(agenda[num_contatos].telefone, sizeof(agenda[num_contatos].telefone), stdin);
        agenda[num_contatos].telefone[strcspn(agenda[num_contatos].telefone, "\n")] = '\0'; // Remover a nova linha

        num_contatos++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
    }
}

// Função para buscar um contato.
void buscar_contato() {
    limpar_terminal();
    char nome[50];
    printf("Digite o nome do contato a ser buscado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover a nova linha
    int i;
    for (i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

// Função para editar um contato.
void editar_contato() {
    limpar_terminal();
    char nome[50];
    printf("Digite o nome do contato a ser editado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover a nova linha
    int i;
    for (i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Digite o novo nome do contato: ");
            fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
            agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0'; // Remover a nova linha

            printf("Digite o novo telefone do contato: ");
            fgets(agenda[i].telefone, sizeof(agenda[i].telefone), stdin);
            agenda[i].telefone[strcspn(agenda[i].telefone, "\n")] = '\0'; // Remover a nova linha

            printf("Contato editado com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

// Função para remover um contato.
void remover_contato() {
    limpar_terminal();
    char nome[50];
    printf("Digite o nome do contato a ser removido: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remover a nova linha
    int i;
    for (i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            // Shift dos contatos para remover o contato encontrado
            int j;
            for (j = i; j < num_contatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            num_contatos--;
            printf("Contato removido com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

// Função para listar os contatos.
void listar_contatos() {
    limpar_terminal();
    if (num_contatos == 0) {
        printf("Nenhum contato na agenda.\n");
    } else {
        printf("Lista de Contatos:\n");
        int i;
        for (i = 0; i < num_contatos; i++) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("--------------------\n");
        }
    }
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
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida, Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}




