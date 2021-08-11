#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

int n[5];
pthread_mutex_t muit;

void* pogr(void *args){
  int s = 0;
  sleep(2);
  while (s<10000){
    for (int z = 0; z < 5 ; z++){
      pthread_mutex_lock(&muit);
      n[z]=n[z]+200;
      printf("Погрузчик докинул 200 товара в магазин под номером: %d\n",z+1);
      s++;
      pthread_mutex_unlock(&muit);
      sleep(2);
    }
  }
}

void* client_buy(void *args){
  int *numPthread = (int* )args;
  int sum,i;
  sum = 0;
  int max = (10000 + rand()%(300));
  printf("Для клиента с номером %d масимальное необходимое число товаров = %d.\n",*numPthread, max);
  sleep(1);
  while (sum < max){
    for(i = 0;i < 5; i++){
      if ((0 == pthread_mutex_trylock(&muit))) {
        if(n[i]!=0){
          sum = sum + n[i];
          printf("Клиент с номером %d забрали %d товара из магазина под номером: %d. Теперь у клиента %d товара.\n",*numPthread,n[i],i+1,sum);
          n[i] = 0;
          pthread_mutex_unlock(&muit);
          sleep(1);
        }
        else{
          pthread_mutex_unlock(&muit);
        }
      }
      if (sum >= max){
        break;
      }
    }
  }
  printf("Клиент с номером %d полностью удовлетворил свои потребности и ушел домой!\n",*numPthread);
  pthread_exit(&numPthread);
}

int main() {
  pthread_t tid[4];
  int g[4],rtd[4];
  for (int i = 0; i < 5; i++){
    n[i] = 1000 + rand()%(100);
  }
  pthread_create(&tid[0],NULL,pogr,0);
  for (int b = 1; b < 4; b++){
    g[b] = b;
    pthread_create(&tid[b],NULL,client_buy,&g[b]);
  }
  for (int b = 1; b < 4; b++){
    rtd[b] = pthread_join(tid[b], NULL);
  }
  if ((0 == rtd[1]) && (0 == rtd[2]) && (0 == rtd[3])){
    printf("Все клиенты удовлетворили свои потребности, погрузчик уходит в отпуск!\n");
    pthread_cancel(tid[0]);
  }
  printf("Спасибо что запускали магазин!\n");
  return 0;
}