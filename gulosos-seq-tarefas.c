/*
Dada uma máquina que execute uma sequência de n tarefas. Cada tarefa tem um tempo de execução  e um deadline . É desejável que todas as tarefas sejam finalizadas sem atrasos, mas nem sempre isso é possível.
Uma alternativa para compensar possíveis atrasos, seria a execução de tarefas que terminam antes do tempo e aproveitar esse saldo para executar as outras tarefas. No final da execução de todas as tarefas,
se o saldo de tempo (deadline - tempo de execução acumulado) for maior igual a zero, então o atraso é igual a zero. Caso o saldo de tempo seja negativo, então o atraso é equivalente ao módulo desse saldo
(nesse problema, basta multiplicar o saldo por -1). Desse, o objetivo seria encontrar uma sequência de atividades que minimize o atraso.
Implemente uma função que receba um vetor de atividades de tamanho n. A função deverá imprimir a sequência ótima de atividades que foram executados até ou antes do deadline e retornar o valor do atraso.

Sugestão de estrutura para a representação do problema:

typedef struct{
    int id; // identificador da tarefa, que será a i-ésima tarefa lida
    int e; // tempo de execução
    int d; // deadline
}
Input Format

Na primeira linha, dever lido o valor de n, que é a quantidade de tarefas.

Nas n seguintes linhas devem ser lidos, em sequência, o tempo de execução e o deadline da i-ésima tarefa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
  int id;
  int e;// identificador da tarefa, que ser a i-esima tarefa lida
  int d; //tempo de execucao
} Tarefas; // deadline

int maiorValor(int *v, int n){
  int i;
  int aux = v[0];
  int ind = 0;


  for (i = 0; i < n; i++){
    if (aux < v[i]){
      aux = v[i];
      ind = i;
    }
  }
  return ind;
}

void sequenciaDeTarefas(Tarefas *a, int n){
  int dif[n];
  int pos[n];
  int i;

  for (i = 0; i < n; i++){
    dif[i] = a[i].d - a[i].e;
  }

  for (i = 0; i < n; i++){
    pos[i] = maiorValor(dif, n);
    dif[pos[i]] = INT_MIN;
  }

  for (i = 0; i < n; i++){
    printf("%d ", pos[i]);
  }
  printf("\n");
}

int atraso(Tarefas *a, int n){
  int c = 0;
  int b = 0;

  for (int i = 0; i < n; i++){
    b += a[i].d;
    c += a[i].e;
  }

  return (b - c > 0) ? 0 : (b - c) * -1;
}

int main(){
  int n;

  scanf("%d", &n);

  Tarefas tarefa[n];
  for (int i = 0; i < n; i++){
    tarefa[i].id = i;
    scanf("%d %d", &tarefa[i].e, &tarefa[i].d);
  }

  sequenciaDeTarefas(tarefa, n);

  int resultado = atraso(tarefa, n);
  printf("%d\n", resultado);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}



