/*implemente uma função que receba duas listas encadeadas (l1 e l2). 
Na função, a lista l1 deve ser procurada na l2. Caso l1 seja encontrada, 
a função deverá retornar a posição da lista na l2. 
Caso contrário, a função deverá retornar -1.

Exemplo:
l1 = {8, 7, 6, 8}
l2 = {1, 2, 3, 4, 5, 6, 7,** 8, 7, 6, 8**, 9, 10}

No exemplo acima, l1 está (inicia) na posição 7 da lista l2.

Para a implementação do exercício, utilize um TAD de listas encadeadas simples, podendo ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Na primeira linha, enquanto -1 não for lido, ler números inteiros e colocá-los na lista l1.
Na segunda linha, enquanto -1 não for lido, ler números inteiros e colocá-los na lista l2.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell{
    int item;
    Cell *next;
};

struct ListaE{
    Cell *head;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

void inserir_primeiro(int key, ListaE *l){
    Cell *aux;
    if (l == NULL)
        l = criar_listaE();
    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;
    if (l == NULL)
        l = criar_listaE();
    if (l->head == NULL)
        inserir_primeiro(key, l);
    else {
        aux = l->head;
        while (aux->next != NULL)
            aux = aux->next;
        novo = criar_celula(key);
        aux->next = novo;
    }
}

void imprimir(ListaE *l){
    Cell *aux;
    if (l != NULL && l->head != NULL){
        aux = l->head;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    if (l != NULL){
        while (l->head != NULL){
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);
        return 1;
    }
    return 0;
}

int procurar_lista(ListaE* l1, ListaE* l2) {
    Cell* atual1 = l1->head;
    Cell* atual2 = l2->head;
    int posicao = 0;

    while (atual2 != NULL) 
    {
        Cell* pontl1 = atual1;
        Cell* pontl2 = atual2;
        while (pontl1 != NULL && pontl2 != NULL && pontl1->item == pontl2->item) {
            pontl1 = pontl1->next;
            pontl2 = pontl2->next;
        }
        if (pontl1 == NULL){
            return posicao;
        }
        atual2 = atual2->next;
        posicao++;
    }

    return -1;
}


int main(){
    int valor;
    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();

    scanf("%d", &valor);
    while (valor != -1){
        inserir_ultimo(valor, l1);
        scanf("%d", &valor);
    }

    scanf("%d", &valor);
    while (valor != -1) {
        inserir_ultimo(valor, l2);
        scanf("%d", &valor);
    }

    int posicao = procurar_lista(l1, l2);
    printf("%d\n", posicao);

    liberar_LE(l1);
    liberar_LE(l2);

    return 0;
}
