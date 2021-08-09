#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {	
  printf("You in CheapBashSecondProg.c and you have PID = %d\n", getpid());
  int sum = 25;
  sleep(2);
  printf("Exit code for CheapBashSecondProg = %d\n", sum);
  exit(sum);
}