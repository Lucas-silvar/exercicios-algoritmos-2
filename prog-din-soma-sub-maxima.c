/*
Seja um arranjo composto por números inteiros, podendo ser positivos e/ou negativos. A subsequência máxima é aquela que tem o maior valor de soma entre todos os os seus elementos.
Por exemplo, dada a sequência a seguir: .
A subsequência máxima é , pois, de todas as subsequências possíveis, essa foi a que registrou a maior soma entre os seus elementos (43).
Implemente, utilizando a estratégia programação dinâmica, uma função que retorne o somatório da subsequência máxima.
Input Format
Na primeira linha deve ser lido um número inteiro (n). Na segunda linha deve ser lida um vetor de números inteiros de tamanho n.
Constraints
Output Format
Somatório da subsequência máxima.
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
