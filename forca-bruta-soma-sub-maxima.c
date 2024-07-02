/*
Seja um arranjo composto por números inteiros, podendo ser positivos e/ou negativos. A subsequência máxima é aquela que tem o maior valor de soma entre todos os os seus elementos.
Por exemplo, dada a sequência a seguir: .
A subsequência máxima é , pois, de todas as subsequências possíveis, essa foi a que registrou a maior soma entre os seus elementos (43).
Implemente, utilizando a estratégia força-bruta, uma função que retorne o somatório da subsequência máxima.
Input Format
Na primeira linha deve ser lido um número inteiro (n). Na segunda linha deve ser lida um vetor de números inteiros de tamanho n.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int somaSubseqMax(int arr[], int n) {
    int somaMax = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int somaAtual = 0;

            for (int k = i; k <= j; k++) {
                somaAtual += arr[k];
            }

            if (somaAtual > somaMax) {
                somaMax = somaAtual;
            }
        }
    }

    return somaMax;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int resultado = somaSubseqMax(arr, n);
    printf("%d\n", resultado);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
