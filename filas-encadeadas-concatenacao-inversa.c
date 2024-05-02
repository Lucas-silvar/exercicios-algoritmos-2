#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}

int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}

void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}

int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

//TAD Pilha
typedef struct PilhaE PilhaE;

struct PilhaE{
    Cell *topo;
};

PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(int key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}

int desempilhar(PilhaE *p){
    Cell *aux;
    int item = ' ';

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}


FilaE* concatenacao_inversa(FilaE *fila1, FilaE *fila2, FilaE *fila_concatenada){
    PilhaE* pilha1 = criar_pilhaE();
    PilhaE* pilha2 = criar_pilhaE();
    
    while(!filaE_vazia(fila1))
        empilhar(desenfileirar(fila1), pilha1);
    while (!filaE_vazia(fila2))
        empilhar(desenfileirar(fila2), pilha2);
    while (!pilhaE_vazia(pilha1))
       enfileirar(desempilhar(pilha1), fila_concatenada);
    while (!pilhaE_vazia(pilha2))
        enfileirar(desempilhar(pilha2), fila_concatenada);
    
    return fila_concatenada;
}

int main() 
{
    FilaE* fila1 = criar_filaE();
    FilaE* fila2 = criar_filaE();
    FilaE* fila_concatenada = criar_filaE();

    int key;
    while (1){
        scanf("%d", &key);
        if(key == -1)
            break;
        else
            enfileirar(key, fila1);
    }
    while (1){
        scanf("%d", &key);
        if(key == -1)
            break;
      else
            enfileirar(key, fila2);
    }

    imprimir_fila(concatenacao_inversa(fila1, fila2, fila_concatenada));
    liberar_filaE(fila1);
    liberar_filaE(fila2);
    liberar_filaE(fila_concatenada);  
    return 0;
}
