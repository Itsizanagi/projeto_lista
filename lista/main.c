#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOCATION_SUCCESS printf("Memória alocada com sucesso!\n")

void error() {
    fprintf(stderr, "Erro de alocação");
    exit(1);
}

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// inserir no inicio da lista
void inserir_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        ALLOCATION_SUCCESS;
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        error();
    }
}

// inserir no fim da lista
void inserir_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        ALLOCATION_SUCCESS;
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL) {
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        error();
    }
}

// inserir no meio da lista
void inserir_meio(No **lista, int num, int anterior) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        ALLOCATION_SUCCESS;
        novo->valor = num;

        if (*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != anterior && aux->proximo) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        error();
    }
}

void imprimir(No *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main() {
    int opcao, valor, ant;
    No *lista = NULL;
    do {
        printf("\n\t0 - Sair\n\t1 - Inserir(inicio)\n\t2 - Inserir(fim)\n\t3 - Inserir(meio)\n\t4 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_inicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_fim(&lista, valor);
                break;
            case 3:
                printf("Digite um valor e o valor de ref: ");
                scanf("%d %d", &valor, &ant);
                inserir_meio(&lista, valor, ant);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if (opcao > 4)
                    printf("Erro: opção inválida\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
