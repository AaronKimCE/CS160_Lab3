#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matrixA[5][5];
  int matrixB[5][5];

  int i, j, k;
  
  for (i = 0; i < 5; i++) { // Generating random matrices
    for (j = 0; j < 5; j++) {
      matrixA[i][j] = rand() % 51;
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      matrixB[i][j] = rand() % 51;
    }
  }

  for (i = 0; i < 5; i++) { // Printing matrices
    for (j = 0; j < 5; j++) {
      printf("%d ", matrixA[i][j]);
    }
    printf("\n");
  }
  
  printf("\nMultiplied by\n\n");

  for (i = 0; i < 5; i++) { 
    for (j = 0; j < 5; j++) {
      printf("%d ", matrixB[i][j]);
    }
    printf("\n");
  }

  int matrixC[5][5];
  int sum = 0;
  
  clock_t start = clock();
  
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      sum = 0;
      for (k = 0; k < 5; k++) {
        sum = sum + matrixA[i][k] * matrixB[k][j];
      }
      matrixC[i][j] = sum;
    }
  }

  printf("\nEquals\n\n");  

  for (i = 0; i < 5; i++) { // Printing product matrix
    for (j = 0; j < 5; j++) {
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }
  
  clock_t stop = clock();
  double duration = 0;
  duration += (double)(stop - start);
  printf("Runtime: %d ticks \n", duration);
 
  return 0;
} 
