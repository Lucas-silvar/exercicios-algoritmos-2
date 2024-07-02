/*
Seja um arranjo composto por n�meros inteiros, podendo ser positivos e/ou negativos. A subsequ�ncia m�xima � aquela que tem o maior valor de soma entre todos os os seus elementos.
Por exemplo, dada a sequ�ncia a seguir: .
A subsequ�ncia m�xima � , pois, de todas as subsequ�ncias poss�veis, essa foi a que registrou a maior soma entre os seus elementos (43).
Implemente, utilizando a estrat�gia programa��o din�mica, uma fun��o que retorne o somat�rio da subsequ�ncia m�xima.
Input Format
Na primeira linha deve ser lido um n�mero inteiro (n). Na segunda linha deve ser lida um vetor de n�meros inteiros de tamanho n.
Constraints
Output Format
Somat�rio da subsequ�ncia m�xima.
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int somaSubseqMax(int v[], int n) {
    int maxAtual = v[0];
    int maxGlobal = v[0];

    for (int i = 1; i < n; i++) {
        maxAtual = (maxAtual + v[i] > v[i]) ? maxAtual + v[i] : v[i];
        if (maxAtual > maxGlobal) {
            maxGlobal = maxAtual;
        }
    }

    return maxGlobal;
}

int main() {
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int somaMaxima = somaSubseqMax(v, n);
    printf("%d\n", somaMaxima);

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
