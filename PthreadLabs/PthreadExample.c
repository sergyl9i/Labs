#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

long int a = 0;
pthread_mutex_t muit;

void* func(void *args){
  pthread_mutex_lock(&muit);
  for (int z=0; z < 10000; z++){
    a++;
  }
  pthread_mutex_unlock(&muit);
}
int main() {
  pthread_t tid[1000];
  for (int i = 0; i < 1000; i++){
    pthread_create(&tid[i],NULL,func,&i);
  }
  sleep(2);
  printf("%ld\n", a);
  return 0;
}