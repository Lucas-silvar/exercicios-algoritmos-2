/*
Implemente um TAD para hashing estático aberto, onde as colisões devem ser resolvidas por meio de árvores rubro-negras.
A função hash deve ser o da multiplicação.
Input Format
Na primeira linha devem ser lidos a constante c considerada na alocação de chaves (tipo float), sendo que 0 < c < 1 e o tamanho n da tabela hash (tipo int).
Na segunda linha deve ser lida a quantidade de chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.
Constraints
Output Format
Imprimir as posições onde as chaves foram colocadas na tabela. Em seguida, se a i-ésima posição da tabela for nula, ou seja, sem chave alocada, deve ser impresso "-".
Caso contrário imprimir a árvore de forma pré-fixa.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    char color;
    struct No *left, *right, *father;
} No;

typedef struct
{
    No **tabela;
    int tamanho;
} TabelaHash;

No *novoNo(int dado)
{
    No *no = (No *)malloc(sizeof(No));
    no->dado = dado;
    no->color = 'R';
    no->left = no->right = no->father = NULL;
    return no;
}

void rotacioar_esq(No **raiz, No *x)
{
    No *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->father = x;
    y->father = x->father;
    if (x->father == NULL)
        *raiz = y;
    else if (x == x->father->left)
        x->father->left = y;
    else
        x->father->right = y;
    y->left = x;
    x->father = y;
}

void rotacionar_dir(No **raiz, No *y)
{
    No *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->father = y;
    x->father = y->father;
    if (y->father == NULL)
        *raiz = x;
    else if (y == y->father->left)
        y->father->left = x;
    else
        y->father->right = x;
    x->right = y;
    y->father = x;
}

void inserirBalanceado(No **raiz, No *z)
{
    while (z != *raiz && z->father->color == 'R')
    {
        if (z->father == z->father->father->left)
        {
            No *y = z->father->father->right;
            if (y != NULL && y->color == 'R')
            {
                z->father->color = 'B';
                y->color = 'B';
                z->father->father->color = 'R';
                z = z->father->father;
            }
            else
            {
                if (z == z->father->right)
                {
                    z = z->father;
                    rotacioar_esq(raiz, z);
                }
                z->father->color = 'B';
                z->father->father->color = 'R';
                rotacionar_dir(raiz, z->father->father);
            }
        }
        else
        {
            No *y = z->father->father->left;
            if (y != NULL && y->color == 'R')
            {
                z->father->color = 'B';
                y->color = 'B';
                z->father->father->color = 'R';
                z = z->father->father;
            }
            else
            {
                if (z == z->father->left)
                {
                    z = z->father;
                    rotacionar_dir(raiz, z);
                }
                z->father->color = 'B';
                z->father->father->color = 'R';
                rotacioar_esq(raiz, z->father->father);
            }
        }
    }
    (*raiz)->color = 'B';
}

void inserir(No **raiz, int dado)
{
    No *z = novoNo(dado);
    No *y = NULL;
    No *x = *raiz;
    while (x != NULL)
    {
        y = x;
        if (z->dado < x->dado)
            x = x->left;
        else
            x = x->right;
    }
    z->father = y;
    if (y == NULL)
        *raiz = z;
    else if (z->dado < y->dado)
        y->left = z;
    else
        y->right = z;
    inserirBalanceado(raiz, z);
}

int hashingF(float c, int key, int B){
    return (int)(B * (key * c - (int)(key * c))) % B;
}

TabelaHash *criarTabelaHash(int tamanho)
{
    TabelaHash *tabelaHash = (TabelaHash *)malloc(sizeof(TabelaHash));
    tabelaHash->tamanho = tamanho;
    tabelaHash->tabela = (No **)malloc(tamanho * sizeof(No *));
    for (int i = 0; i < tamanho; i++)
        tabelaHash->tabela[i] = NULL;
    return tabelaHash;
}

void inserirNaTabelaHash(TabelaHash *tabelaHash, float c, int key)
{
    int indice = hashingF(c, key, tabelaHash->tamanho);
    inserir(&(tabelaHash->tabela[indice]), key);
}

void imprimirPreOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado);
        imprimirPreOrdem(raiz->left);
        imprimirPreOrdem(raiz->right);
    }
}

void imprimirTabelaHash(TabelaHash *tabelaHash)
{
    for (int i = 0; i < tabelaHash->tamanho; i++)
    {
        printf("%d: ", i);
        if (tabelaHash->tabela[i] == NULL)
        {
            printf("-\n");
        }
        else
        {
            imprimirPreOrdem(tabelaHash->tabela[i]);
            printf("\n");
        }
    }
}

int main()
{
    float c;
    int n, numKey;

    scanf("%f %d", &c, &n);

    TabelaHash *tabelaHash = criarTabelaHash(n);

    scanf("%d", &numKey);

    for (int i = 0; i < numKey; i++)
    {
        int key;
        scanf("%d", &key);
        inserirNaTabelaHash(tabelaHash, c, key);
    }
    imprimirTabelaHash(tabelaHash);


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
