/*
Implemente uma função que receba uma lista duplamente encadeada. 
A função deverá remover todos os elementos repetidos.

Para a implementação do exercício, utilize um TAD de listas encadeadas, 
podendo ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format

Enquanto "-1" não for lido, ler números inteiros e inserí-los em uma lista duplamente encadeada.

Constraints

.

Output Format

Imprimir a lista resultante da remoção de elementos repetidos
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


int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, ListaE *l){
    Cell *aux;
    
    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}
/*
Implemente uma função que receba uma lista duplamente encadeada. 
A função deverá remover todos os elementos repetidos.
Para a implementação do exercício, utilize um TAD de listas encadeadas, 
podendo ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Enquanto "-1" não for lido, ler números inteiros e inserí-los em uma lista duplamente encadeada.

Output Format
Imprimir a lista resultante da remoção de elementos repetidos
*/


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

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
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
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}
void remover_repetidos(ListaE *l) {
    if (!listaE_vazia(l)) {
        Cell *atual = l->head;
        
        while (atual != NULL) {
            Cell *compare = atual->next;
            Cell *previous = atual; 
            
            while (compare != NULL) {
                if (atual->item == compare->item) {
                   
                    Cell *temp = compare;
                    previous->next = compare->next; 
                    compare = compare->next; 
                    free(temp);
                } else {
                    previous = compare; 
                    compare = compare->next; 
                }
            }
            atual = atual->next; 
        }
    }
}



int main() {
    ListaE *lista = criar_listaE();
    int num;
    
    scanf("%d", &num);
    while (num != -1) {
        inserir_ultimo(num, lista);
        scanf("%d", &num);
    }

    remover_repetidos(lista);
    imprimir(lista);
    liberar_LE(lista);


      
    return 0;
}
