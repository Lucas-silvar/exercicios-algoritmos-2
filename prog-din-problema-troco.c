/*
Dado um conjunto de moedas e um valor de troco que deve ser dado utilizando essas moedas.
Em vez de tentarmos obter a quantidade mínima de moedas, dessa vez, o nosso interesse poderia ser definir a quantidade de formas possíveis para devolvermos o troco.
Por exemplo, para o troco de valor 5 e o conjunto de moedas {1,2,3,4} existem 6 formas diferentes para retornarmos o troco: {1,1,1,1,1}, {1,1,1,2}, {1,1,3}, {1,4}, {1,2,2}, {2,3}.

Em uma estratégia parecida com a da mochila binária, podemos utilizar a programação dinâmica para encontrarmos a quantidade possíveis de formas para devolvermos o troco a partir de um conjunto de moedas.
Implemente uma função, utilizando programação dinâmica, que retorne a quantidade de possibilidades para retornar um valor de troco utilizando um conjunto de moedas.
Input Format
A primeira linha deve conter o valor do troco (T).
A segunda linha deve conter a quantidade de moedas (N).
Na terceira linha, ler o conjunto de N moedas.
Constraints
Output Format
Imprimir a quantidade de formas possíveis que o valor do troco T pode ser devolvido a partir do conjunto de moedas.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int contador_possibilidades(int *moedas, int n, int troco){
    int i,j,a,b;
    int mat[troco + 1][n];

    for ( i = 0; i < n; i++)
    {
        mat[0][i] = 1;

    }

    for ( i = 1; i <= troco; i++)
    {
        for ( j = 0; j < n; j++)
        {

            if (i - moedas[j] >= 0 )
            {
                a = mat[i- moedas[j]][j];

            }

            else
            {
                a = 0;
            }

            if (j >= 1)
            {
                b = mat[i][j-1];

            }

            else{
                b = 0;
            }

            mat[i][j] = a + b;

        }

    }

    return mat[troco][n - 1];

}


int main(void) {

    int *v,n,troco,i;

    scanf("%d",&troco);

    scanf("%d",&n);

    v = malloc(sizeof(int) * n);

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
    }

    printf("%d",contador_possibilidades(v, n, troco));


    free(v);

    return 0;
}
