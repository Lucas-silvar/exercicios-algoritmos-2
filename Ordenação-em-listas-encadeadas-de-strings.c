/*Implemente um algoritmo de ordenação simples para ordenar uma lista encadeada de strings.

Input Format

Na primeira linha deve ser lida a quantidade de elementos que serão inseridos na lista encadeada. 
A partir da segunda linha, ler as strings e colicá-las na lista encadeada.

Para a implementação do exercício, utilize um TAD de listas encadeadas simples, podendo ser o código que foi apresentado em aula 
(disponível no repositório da disciplina no GitHub).
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell {
    char item[TAM];
    Cell *next;
};

struct ListaE {
    Cell *head;
};

ListaE* criar_listaE() {
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

int listaE_vazia(ListaE *l) {
    return (l == NULL) || (l->head == NULL);
}

Cell* criar_celula_char(const char *key) {
    Cell *c = (Cell*)malloc(sizeof(Cell));
    strcpy(c->item, key);
    c->next = NULL;
    return c;
}

void inserir_primeiro_char(const char *key, ListaE **l) {
    Cell *aux;
    if (*l == NULL)
        *l = criar_listaE();
    aux = criar_celula_char(key);
    aux->next = (*l)->head;
    (*l)->head = aux;
}

void inserir_ultimo_char(const char *key, ListaE **l) {
    Cell *aux, *novo = criar_celula_char(key);
    if (*l == NULL)
        *l = criar_listaE();
    if (listaE_vazia(*l))
        inserir_primeiro_char(key, l);
    else {
        aux = (*l)->head;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = novo;
    }
}

void ordenaListaE_bubbleSort(ListaE *l) {
    int troca;
    char aux[TAM];
    Cell *celulaAtual;

    if (l == NULL || l->head == NULL)
        return;

    do {
        troca = 0;
        celulaAtual = l->head;

        while (celulaAtual->next != NULL) {
            if (strcmp(celulaAtual->item, celulaAtual->next->item) > 0) {
                strcpy(aux, celulaAtual->item);
                strcpy(celulaAtual->item, celulaAtual->next->item);
                strcpy(celulaAtual->next->item, aux);
                troca = 1;
            }
            celulaAtual = celulaAtual->next;
        }
    } while (troca);
}

void imprimir(ListaE *l) {
    Cell *aux;
    if (!listaE_vazia(l)) {
        aux = l->head;
        while (aux != NULL) {
            printf("%s\n", aux->item);
            aux = aux->next;
        }
    }
}

void liberar_LE(ListaE *l) {
    Cell *aux = NULL;
    if (l != NULL) {
        while (l->head != NULL) {
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);
    }
}

int main(void) {
    int tam;
    scanf("%d", &tam);
    getchar();

    ListaE* listaNomes = criar_listaE();

    for (int i = 0; i < tam; i++) {
        char nome[100];
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; 
        inserir_ultimo_char(nome, &listaNomes);
    }

    ordenaListaE_bubbleSort(listaNomes);

    imprimir(listaNomes);

    liberar_LE(listaNomes);

    return 0;
}
