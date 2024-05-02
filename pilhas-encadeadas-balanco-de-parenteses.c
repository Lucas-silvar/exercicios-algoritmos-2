/*
Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, 
sem levar em conta o restante da expressão. Por exemplo:

a+(b*c)-2-a está correto (a+b*(2-c)-2+a)*2 está correto

enquanto

(a*b-(2+c) está incorreto 2*(3-a)) está incorreto )3+b*(2-c)( está incorreto

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que 
fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

Para a solução desse exercício, utilize um TAD de pilha encadeada de caracteres. 
Dica: adapte o TAD de pilha encadeada (de números) apresentado em aula para a resolução do exercício.

Input Format

Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada uma das N linhas a seguir é uma string representando uma expressão.

Constraints

As pilhas devem ser manipuladas apenas por funções. Por exemplo, o acesso a elementos deve ser feito apenas através da função desempilhar.

Output Format

O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, 
cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct PilhaE PilhaE;

struct Cell{
    char item;
    Cell *next;
};

struct PilhaE{
    Cell *topo;
};

Cell* criar_celula(char key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}

PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));
    p->topo = NULL;
    return p;
}

void empilhar(char key, PilhaE *p){
    Cell *aux = criar_celula(key);
    aux->next = p->topo;
    p->topo = aux;
}

char desempilhar(PilhaE *p){
    if (p == NULL || p->topo == NULL) {
        return '\0'; 
    }
    Cell *aux = p->topo;
    char item = aux->item;
    p->topo = aux->next;
    free(aux);
    return item;
}

int verificar_parenteses(char *expressao) {
    PilhaE *pilha = criar_pilhaE();
    int i=0;
    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            empilhar('(', pilha);
        } else if (expressao[i] == ')') {
            if (desempilhar(pilha) == '\0') {
                return 0;
            }
        }
        i++;
    }
    int balanceado = pilha->topo == NULL;
    free(pilha);
    return balanceado;
}

int main() {
    int n;
    scanf("%d", & n); 
    getchar();
    for (int i = 0; i < n; i++) {
        char expressao[100];
        fgets(expressao, sizeof(expressao), stdin);
        if (verificar_parenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}
