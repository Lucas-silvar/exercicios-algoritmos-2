/*
Implemente, utilizando divis�o e conquista, uma fun��o para calcular a dist�ncia de Manhattan entre dois vetores de mesmo tamanho.
Equa��o da dist�ncia de Manhattan entre dois vetores:

Input Format
A primeira linha deve ser um n�mero inteiro n referente ao tamanho dos vetores. Na segunda linha, devem ser lidos os n elementos do primeiro vetor.
Por fim, na pr�xima linha deve ser lido os elementos do segundo vetor, que tamb�m possui tamanho n.

Constraints
Output Format
O valor da dist�ncia entre os vetores.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int distManhattan(int v1[], int v2[], int ini, int fim){
    if(ini >= fim)
        return (v1[ini] >= v2[ini]) ? (v1[ini] - v2[ini]) : (v2[ini] - v1[ini]);
    else{
        int m = (ini + fim)/2;
        return distManhattan(v1, v2, ini, m) + distManhattan(v1, v2, m+1, fim);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int  v1[n], v2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v1[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &v2[i]);

    printf("%d", distManhattan(v1, v2, 0, n-1));
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
