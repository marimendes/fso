#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>



int m, n, p, q, c, d, k, sum = 0;
int first[2000][2000], second[2000][2000], multiply[2000][2000];
pid_t filho1, filho2, idPai;

int main(){

  printf("Qual o tamanho n da matriz?\n");
  scanf("%d", &n);
  m = n;
  printf("Digite a primeira matriz:\n");
  for (c = 0; c < m; c++){
    for (d = 0; d < n; d++){
        scanf("%d", &first[c][d]);
    }
  }
    
  p = n;
  q = n;
  printf("Digite a segunda matriz:\n");
  for (c = 0; c < p; c++){
    for (d = 0; d < q; d++){
        scanf("%d", &second[c][d]);
    }
  }

  idPai = getpid();
  filho1 = fork();

  if(filho1==0){ // filho 1 calcula da linha 0 ate a dimensao/2 -1
    for (int c = 0; c < n; c++){
      if(c > (n/2)-1 )
        break;
      for (int d = 0; d < n; d++){
        for (int k = 0; k < n; k++){
          multiply[c][d] += first[c][k] * second[k][d];
        }
      }
    }
    for (int i = 0; i < n; i++){
      if (i > (n / 2) - 1)
          break;
      for (int j = 0; j < n; j++){
          printf("%d ", multiply[i][j]);
      }
      puts("\n");
    }
    //avisar o pai que acabou e morrer
    exit(0);
  } 
  else {
    filho2 = fork();
    if(filho2==0){ //filho 2 calcula de dimensao/2 ate dimensao -1
      for (int c = (n/2); c < n; c++){
        for (int d = 0; d < n; d++){
          for (k = 0; k < n; k++){
              multiply[c][d] += first[c][k] * second[k][d];
          }
        }
      }
      for (int i = (n/2); i < n; i++){
        for (int j = 0; j < n; j++){
          printf("%d ", multiply[i][j]);
        }
        puts("\n");
      }
      exit(0);
    }

    else{//pai fica aqui
      int num;
      filho1 = wait(&num);
      filho2 = wait(&num);
      exit(0);
    }//end pai
  } //end geral

  return 0;
}