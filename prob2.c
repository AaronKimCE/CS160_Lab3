#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread (void *vargp) {
  sleep(1);
  printf("Hello, world\n");
  return NULL;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, thread, NULL);
  pthread_join(tid, NULL); // Added line
  sleep(0.5);
  exit(0);
}
