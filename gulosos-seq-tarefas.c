/*
Dada uma m�quina que execute uma sequ�ncia de n tarefas. Cada tarefa tem um tempo de execu��o  e um deadline . � desej�vel que todas as tarefas sejam finalizadas sem atrasos, mas nem sempre isso � poss�vel.
Uma alternativa para compensar poss�veis atrasos, seria a execu��o de tarefas que terminam antes do tempo e aproveitar esse saldo para executar as outras tarefas. No final da execu��o de todas as tarefas,
se o saldo de tempo (deadline - tempo de execu��o acumulado) for maior igual a zero, ent�o o atraso � igual a zero. Caso o saldo de tempo seja negativo, ent�o o atraso � equivalente ao m�dulo desse saldo
(nesse problema, basta multiplicar o saldo por -1). Desse, o objetivo seria encontrar uma sequ�ncia de atividades que minimize o atraso.
Implemente uma fun��o que receba um vetor de atividades de tamanho n. A fun��o dever� imprimir a sequ�ncia �tima de atividades que foram executados at� ou antes do deadline e retornar o valor do atraso.

Sugest�o de estrutura para a representa��o do problema:

typedef struct{
    int id; // identificador da tarefa, que ser� a i-�sima tarefa lida
    int e; // tempo de execu��o
    int d; // deadline
}
Input Format

Na primeira linha, dever lido o valor de n, que � a quantidade de tarefas.

Nas n seguintes linhas devem ser lidos, em sequ�ncia, o tempo de execu��o e o deadline da i-�sima tarefa.
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



