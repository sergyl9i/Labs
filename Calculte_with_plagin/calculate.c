#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include "calculator_funks.h"

long int getNubmer(){
  bool enterValue=1;
  int number=0;
  while (enterValue == 1){
    scanf("%d",&number);
    if (number <= 0){
      printf("Некорректный ввод. Повторите ещё раз.\n");
      while ((getchar()) != '\n');
    }
    else{
      enterValue=0;
    }
  }
  return number;
}

void printResult(int a){
	printf("Полученный результат: %d\n", a);
}

int main() {
  char choice;
  void *calc_lib;
  calc_lib = dlopen("/home/sergey_oks/Рабочий стол/Developp_git/Labs/Calculte_with_plagin/libcalculator_funks.so",RTLD_NOW);
  printf("Адрес calc_lib = %p\n",calc_lib);
  int (*fsumm)(int a,int b) = dlsym(calc_lib, "summ");
  int (*fsubtrac)(int a,int b) = dlsym(calc_lib, "subtrac");
  int (*fmultiply)(int a,int b) = dlsym(calc_lib, "multiply");
  int (*fdel)(int a,int b) = dlsym(calc_lib, "del");
  do {
  	int first_nubmer=0;
  	int second_nubmer=0;
  	printf("Выберите математическую операцию над двумя числами: \n1 - Сложение.\n2 - Вычитание.\n3 - Умножение.\n4 - Деление.\n5 - Выход из программы.\n");
  	scanf(" %c",&choice);
  	while ((getchar()) != '\n');
  	switch(choice) {
  		case '1':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(fsumm(first_nubmer, second_nubmer));
  		break;
  		case '2':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(fsubtrac(first_nubmer, second_nubmer));
  		break;
  		case '3':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(fmultiply(first_nubmer, second_nubmer));
  		break;
  		case '4':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(fdel(first_nubmer, second_nubmer));
  		break;
  		case '5':
  			printf("Спасибо за использование программы!\n");
  		break;
  		default:
  			printf("Неверный ввод!\n"); 
  		break;
  	}
  }
  while (choice != '5');
  int dlclose(void *handle);
  return 0;
}