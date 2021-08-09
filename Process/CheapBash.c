#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int rv;
  pid = fork();
  switch(pid) {
  case -1:
    perror("fork"); /* произошла ошибка */
    exit(1); /*выход из родительского процесса*/
  case 0:
    printf("(child) Child PID = %d\n", getpid());
    printf("(child) Parent PID = %d\n", getppid());
    printf("(child) Enter a exit code for child process = ");
    execl("./CheapBashSecondProg", NULL);
  default:
    printf("You in CheapBash.c and you have PID = %d\n", getpid());
    printf("Parent PID = %d\n", getpid());
    printf("Child PID = %d\n",pid);
    wait(&rv);
    printf("You are back in CheapBash.c and you have PID = %d\n", getpid());
    printf("Exit code child pid = %d\n", WEXITSTATUS(rv));
  }	
  return 0;
}