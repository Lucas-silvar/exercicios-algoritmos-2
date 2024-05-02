/*
Implemente uma função que percorra todos os caminhos possíveis (da raiz até cada nó folha) árvore binária de busca. 
A função deverá retornar o maior valor de somatório possível do nó raiz até um nó folha.

Para a implementação do exercício, utilize um TAD de árvores binárias, 
podendo ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format

Na primeira linha deve ser lido o número inteiro N, que é referente à quantidade de nós da árvore binária de busca. 
Em seguida, em cada linha deve ser lido um número inteiro para ser inserido como nó na árvore 
(fazer isso até que N números sejam lidos).

Constraints

.

Output Format

Imprimir o maior valor encontrado de somatório entre o nó raiz e um folha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

struct Node{
    int item;
    struct Node *left;
    struct Node *right;
};

Node* criar(int item){
    Node * tree = (Node *) malloc(sizeof(Node));
    
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
        
    return tree;
}

Node* pesquisar(int item, Node* tree){
    if (tree != NULL){
        if (item == tree->item)
            return tree;
        else if (item < tree->item)
            return pesquisar(item, tree->left);
        else
            return pesquisar(item, tree->right);
    }else
        return NULL;
}

int min(Node* tree){
    Node* aux = tree;
    
    if (aux != NULL){
        while (aux->left != NULL)
            aux = aux->left;
        
        return aux->item;
    }
    
    return INT_MIN;
}

int max(Node* tree){
    Node* aux = tree;
    
    if (aux != NULL){
        while (aux->right != NULL)
            aux = aux->right;
        
        return aux->item;
    }
    
    return INT_MAX;
}

Node* inserir(int item, Node* tree){
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);
        
    return tree;
}

Node* remover(int item, Node* tree){
    Node *aux, *auxP, *auxF;
    
    if (tree != NULL){
        if (item < tree->item)
            tree->left = remover(item, tree->left);
        else if (item > tree->item)
            tree->right = remover(item, tree->right);
        else{
            aux = tree;
            
            if (aux->left == NULL)
                tree = tree->right;
            else if (aux->right == NULL)
                tree = tree->left;
            else{
                auxP = aux->right;
                auxF = auxP;
                
                while (auxF->left != NULL){
                    auxP = auxF;
                    auxF = auxF->left;
                }
                
                if (auxP != auxF){
                    auxP->left = auxF->right;
                    auxF->left = aux->left;
                }
                
                auxF->right = aux->right;
                
                tree = auxF;
            }
            
            free(aux);
        }
    }
    
    return tree;
}

void imprimirInfix(Node* tree){
    if (tree != NULL){
        imprimirInfix(tree->left);
        printf("%d ", tree->item);
        imprimirInfix(tree->right);
    }
}

void imprimirPrefix(Node* tree){
    if (tree != NULL){
        printf("%d ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}

void imprimirPosfix(Node* tree){
    if (tree != NULL){
        imprimirPosfix(tree->left);
        imprimirPosfix(tree->right);
        printf("%d ", tree->item);
    }
}

void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int maior_somatorio_caminho(Node* tree, int somatorio_atual) 
{
    if (tree == NULL) {
        return 0;
    }

    somatorio_atual += tree->item;
    
    if (tree->left == NULL && tree->right == NULL) {
        return somatorio_atual;
    }

    int somatorio_esquerda = maior_somatorio_caminho(tree->left, somatorio_atual);
    int somatorio_direita = maior_somatorio_caminho(tree->right, somatorio_atual);

    return (somatorio_esquerda > somatorio_direita) ? somatorio_esquerda : somatorio_direita;
}

int maior_somatorio_raiz_folha(Node* raiz) {
    return maior_somatorio_caminho(raiz, 0);
}

int main() {
    int N, item;
    
    scanf("%d", &N);
    Node* raiz = NULL;

    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &item);
        raiz = inserir(item, raiz);
    }

    int maior_somatorio = maior_somatorio_raiz_folha(raiz);
    printf("%d\n", maior_somatorio);

    liberar_arvore(raiz);

    return 0;
}
