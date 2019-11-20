#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thread (void *vargp) {
  printf("Hello, world\n"); 
  pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int i = 0;
  pthread_t tid[n];
  for (i = 0; i < n; i++) {
    pthread_create(&tid[i], NULL, thread, NULL);
    pthread_join(tid[i], NULL);
  }
}
