//Global Variables
int readcnt = 0;
sem_t mutex = 1, w = 1;

void reader(void) {
  while(1) {
    P(&mutex);
    readcnt++;
    if (readcnt == 1) {
      P(&w);
    }
    V(&mutex);

    //Reading

    P(&mutex);
    readcnt--;
    if (readcnt == 0) {
      V(&w);
    }
    V(&mutex);
  }
}

void writer(void) {
  while(1) {
    P(&w);

    //Writing

    V(&mutex);
  }
}
