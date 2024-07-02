/*
Dado um vetor de inteiros. Implemente uma fun��o, utilizando divis�o e conquista, que encontre a soma m�xima no vetor.
 Por exemplo: para o vetor v = {-1, 3, 0, -2, 1, 3, -4, 5}, a soma m�xima � 12 (3 + 0 + 1 + 3 + 5).
Input Format
A primeira linha deve ser um n�mero inteiro n referente ao tamanho do vetor. Em seguinda,
Para cada uma das pr�ximas n linhas devem ser lidos os elementos do vetor.
Constraints
Output Format
Soma m�xima dos elementos do vetor.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int somaMax(int v[], int ini, int fim) {
    if (ini > fim)
        return 0;

    if (ini == fim){
        if (v[ini] >= 0)
            return v[ini];
        else
            return 0;
    }

    int m = (ini + fim) / 2;

    return somaMax(v, ini, m) + somaMax(v, m + 1, fim);
}

int main(){
    int n, *v;

    scanf("%d", &n);

    v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printf("%d\n", somaMax(v, 0, n-1));

    free(v);
    return 0;
}
