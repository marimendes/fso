#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];

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

    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
 
    printf("Product of the matrices:\n");
 
    for (c = 0; c < m; c++) {
        for (d = 0; d < q; d++) {
            printf("%d\t", multiply[c][d]);
        }
 
      printf("\n");
    }

    return 0;
}