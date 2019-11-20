#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *MatrixMult (void* vargp) {
  int *elem = (int *)vargp;
  int result = 0;
  int i = 0;

  int j = elem[0];
  for (i = 1; i <= j; i++) {
    result += elem[i]*elem[i+j];
  }
  
  int *pass = (int *)malloc(sizeof(int));
  *pass = result;

  pthread_exit(pass);
}

int main() {
  int matrixA[5][5];
  int matrixB[5][5];
  
  int i, j, k;
  
  for (i = 0; i < 5; i++) { //Generating random matrices
    for (j = 0; j < 5; j++) {
      matrixA[i][j] = rand() % 51;
    }
  }
  
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      matrixB[i][j] = rand() % 51;
    }
  }

  for (i = 0; i < 5; i++) { //Printing matrices
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

  pthread_t *threads;
  threads = (pthread_t*)malloc(25*sizeof(pthread_t));

  int cnt = 0;
  int* array = NULL;
  for (i = 0; i < 5; i++) { //Creating and running threads
    for (j = 0; j < 5; j++) {
       array = (int *)malloc((20)*sizeof(int));
       array[0] = 5;

       for (k = 0; k < 5; k++) {
         array[k+1] = matrixA[i][k];
       }
       for (k = 0; k < 5; k++) {
         array[k+6] = matrixB[k][j];
       }

       pthread_create(&threads[cnt++], NULL, MatrixMult, (void*)array);
    }
  }
  
  printf("\nEquals\n\n");
  for (i = 0; i < 25; i++) { //Joining all threads
    void *product;
    pthread_join(threads[i], &product);
    int *final = (int *)product;
    printf("%d ", *final);
    if (!((i + 1) % 5)) {
      printf("\n");
    }
  }
  return 0; 
}
