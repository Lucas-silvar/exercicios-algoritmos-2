/*
Implemente uma função que receba uma árvore rubro-negra. A função deverá retornar a quantidade de nós pretos que contém valor ímpar.

Input Format

Na primeira linha deve ser lido o número inteiro N, que é referente à quantidade de nós da árvore. Em seguida, em cada linha deve ser lido um número inteiro para ser inserido como nó na árvore (fazer isso até que N números sejam lidos).

Constraints

.

Output Format

Quantidade de nós pretos ímpares
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct NodeVP NodeVP;

struct NodeVP{
    int key;
    int color;
    NodeVP *father;
    NodeVP *left;
    NodeVP *right;
};


NodeVP* criar_AVP(int key){
    NodeVP* tree = (NodeVP*) malloc(sizeof(NodeVP));
    tree->key = key;
    tree->color = 0;
    tree->left = NULL;
    tree->right = NULL;
    tree->father = NULL;

    return tree;
}


NodeVP* pesquisar(NodeVP *tree, int key){
    if (tree != NULL){
        if (key == tree->key)
            return tree;
        else if (key < tree->key)
            return pesquisar(tree->left, key);
        else
            return pesquisar(tree->right, key);
    }

    return NULL;
}



static NodeVP* obter_avo(NodeVP *no){
    if ((no != NULL) && (no->father != NULL)){
        return no->father->father;
    }

    return NULL;
}


static NodeVP* obter_tio(NodeVP *no){
    NodeVP* avo = obter_avo(no);
    NodeVP* aux = NULL;
    

    if (avo != NULL){
        if (avo->left == no->father){
            aux = avo->right;
        }else
            aux = avo->left;
    }

    return aux;
}


static NodeVP* rotacionar_dir(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP *a = p->father;
    
    p->father = a->father;
    
    if (a->father != NULL){
        if (a->father->left == a)
            a->father->left = p;
        else
            a->father->right = p;
    }
    
    a->father = p;
    a->left = p->right;
    p->right = a;
    
    x = p;
    
    return x;
}


static NodeVP* rotacionar_esq(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP * a = p->father;
    
    p->father = a->father;
    
    if (a->father != NULL){
        if (a->father->right == a)
            a->father->right = p;
        else
            a->father->left = p;
    }
    
    a->father = p;
    a->right = p->left;
    p->left = a;

    x = p;
    
    return x;
}


static NodeVP* rotacionar_dir_esq(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP *a = p->father;
    
    x->father = a;
    a->left = x;
    p->left = x->right;
    x->right = p;
    p->father = x;
    
    x = rotacionar_esq(p);

    return x;
}


static NodeVP* rotacionar_esq_dir(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP * a = p->father;
    
    x->father = a;
    a->left = x;
    p->father = x;
    p->right = x->left;
    x->left = p;
    
    x = rotacionar_dir(p);

    return x;
}


static NodeVP* balancear(NodeVP *x){
    NodeVP *pai, *tio;

    if (x->father == NULL){
        x->color = 1;
    }else{
        pai = x->father;

        if (pai->color == 0){
            tio = obter_tio(x);

            if ((tio != NULL) && (tio->color == 0)){
                pai->color = tio->color = 1;
                x = obter_avo(x);
        
            if (x->father != NULL)
                x->color = 0;
            }else{
                if (pai->left == x){
                    if (pai->father->left == pai)
                        x = rotacionar_dir(x);
                    else
                        x = rotacionar_dir_esq(x);
                }else{
                    if (pai->father->right == pai)
                        x = rotacionar_esq(x);
                    else
                        x = rotacionar_esq_dir(x);
                }

                x->color = 1;
                
                if (x->left != NULL)
                    x->left->color = 0;
                
                if (x->right != NULL)
                    x->right->color = 0;
            }
        }
    }
    
    return x;
}


NodeVP* inserirVP(NodeVP *tree, int key){
    NodeVP *auxP, *auxF;

    if (tree == NULL){
        tree = criar_AVP(key);
        tree->color = 1;
    }else{
        auxP = auxF = tree;

        while (auxF != NULL){
            auxP = auxF;

            if (key < auxF->key)
                auxF = auxF->left;
            else
                auxF = auxF->right;
        }

        auxF = criar_AVP(key);
        auxF->father = auxP;

        if (auxF->key < auxP->key)
            auxP->left = auxF;
        else
            auxP->right = auxF;

        while ((auxF->father != NULL) && (auxF->color == 0) && (auxF->father->color == 0))
            auxF = balancear(auxF);
        
        while (auxF->father != NULL)
            auxF = auxF->father;

        tree = auxF;
    }
    
    return tree;
}

int contar_nos_pretos_impares(NodeVP* tree) {
    if (tree == NULL) {
        return 0;
    }

    int nos_pretos_esquerda = contar_nos_pretos_impares(tree->left);
    int nos_pretos_direita = contar_nos_pretos_impares(tree->right);

    if (tree->color == 1 && tree->key % 2 != 0) {
        return nos_pretos_esquerda + nos_pretos_direita + 1;
    }

    return nos_pretos_esquerda + nos_pretos_direita;
}

int contar_nos_pretos_impares_arvore(NodeVP* raiz) {
    return contar_nos_pretos_impares(raiz);
}

int main() {
    int N, valor;
    scanf("%d", &N);

    NodeVP* raiz = NULL;

    for (int i = 0; i < N; i++) {
        scanf("%d", &valor);
        raiz = inserirVP(raiz, valor);
    }

    int nos_pretos_impares = contar_nos_pretos_impares_arvore(raiz);
    printf("%d\n", nos_pretos_impares);

    return 0;
}
