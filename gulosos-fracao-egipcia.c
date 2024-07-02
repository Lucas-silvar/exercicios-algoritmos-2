/*
Uma fração pode representada pela soma de um conjunto de frações unitárias, onde o numerador é igual a 1 (um). Exemplos:
8/11 é equivamente a 1/2 + 1/5 + 1/37 + 1/4070.
7/3 é equivamente a 2 + 1/3.
Essas frações unitárias podem ser geradas utilizando uma estratégia gulosa. Dado dois números inteiros: n (numerador) e d (demoninador).
Se d > n, o denominador da maior fração unitária é dada da seguinte forma: 1 / (d / n). Após, pode ser feita uma chamada recursiva,
cuja fração de entrada deve ser equivalente a (n / d) - (1 / (d / n + 1)), que é igual a uma outra fração: (n * (d / n + 1) - d) / (d * (d / n + 1)). Por exemplo, para o 8/11, a primeira fração unitária é 1 / (d / n + 1) = 1 / (11 / 8 + 1) = 1/2. Em seguida, pode ser feita uma chamada recursiva para 8/11 - 1/2 = 5/22, ou seja, (8 * (11/8 + 1) - 11) / ((11/8 + 1) * 11) = 5/22.

Se d < n, o resultado é um número inteiro mais uma fração resultante da chamada recursiva para seguinte fração: (n % d) / d.
Por exemplo, para 7/3, o numerador é maior, ou seja, primeiro deverá ser impresso a parte inteira da divisão (2). Em seguinda, fazer uma chamada recursiva para (n % d) / n = (7 % 3) / 3 = 1/3.

Os critérios de parada são:
d % n == 0
n % d == 0
Implemente uma função que receba, pelo menos, dois números inteiros que represente uma fração. A função deverá imprimir o somatório de frações unitárias e/ou números inteiros cujo resultado é a fração de entrada.
Input Format
Ler dois números inteiros: numerador seguido do denominador.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

void fracaoEgipcia(int numerador, int denominador) {
    while (numerador != 0) {
        int fracaoUnitariaDenominador = (denominador + numerador - 1) / numerador;

        printf("1/%d", fracaoUnitariaDenominador);

        numerador = numerador * fracaoUnitariaDenominador - denominador;
        denominador = denominador * fracaoUnitariaDenominador;

        if (numerador != 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int numerador, denominador;

    scanf("%d %d", &numerador, &denominador);

    fracaoEgipcia(numerador, denominador);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
