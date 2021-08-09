#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {  
  pid_t pid2,pid3,pid4,pid5,pid6;
  int rw2,rw3,rw4,rw5,rw6;
  rw2 = 20;
  rw3 = 21;
  rw4 = 22;
  rw5 = 23;
  rw6 = 24;
  pid2 = fork();
  if (0 == pid2){
    printf("I'm Child with PID = %d and my Parent have PID = %d\n", getpid(), getppid());
    sleep(5);
    pid4 = fork();
    if (0 == pid4){
      printf("I'm Child with PID = %d and my Parent have PID = %d\n", getpid(), getppid());
      sleep(5);
      exit(rw4);
    }
    if (pid4 > 0){
      pid5 = fork();
      if (0 == pid5){
        printf("I'm Child with PID = %d and my Parent have PID = %d\n", getpid(), getppid());
        sleep(5);
        exit(rw5);
      }
      if (pid5 > 0){
        wait(&rw5);
        printf("Close child with PID = %d. Exit code child pid = %d\n", pid5, WEXITSTATUS(rw5));
      }
      wait(&rw4);
      printf("Close child with PID = %d. Exit code child pid = %d\n", pid4, WEXITSTATUS(rw4));
    }
    exit(rw2);
  }
  if (pid2 > 0){
    pid3 = fork();
    if (0 == pid3){
      printf("I'm Child with PID = %d and my Parent have PID = %d\n", getpid(), getppid());
      sleep(5);
      pid6 = fork();
      if (0 == pid6){
        printf("I'm Child with PID = %d and my Parent have PID = %d\n", getpid(), getppid());
        sleep(5);
        exit(rw6);
      }
      if (pid6 > 0){
        wait(&rw6);
        printf("Close child with PID = %d. Exit code child pid = %d\n", pid6, WEXITSTATUS(rw6));
      }
      exit(rw3);
    }
    if (pid3 > 0){
      wait(&rw3);
      printf("Close child with PID = %d. Exit code child pid = %d\n", pid3, WEXITSTATUS(rw3));
    }
    wait(&rw2);
    printf("Close child with PID = %d. Exit code child pid = %d\n", pid2, WEXITSTATUS(rw2));
  }
  return 0;
}