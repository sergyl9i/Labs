#include <stdio.h>
#include <stdbool.h>
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
  			printResult(summ(first_nubmer, second_nubmer));
  		break;
  		case '2':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(subtrac(first_nubmer, second_nubmer));
  		break;
  		case '3':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(multiply(first_nubmer, second_nubmer));
  		break;
  		case '4':
  			printf("Введите первое число:\n");
  			first_nubmer=getNubmer();
  			while ((getchar()) != '\n');
  			printf("Введите второе число:\n");
  			second_nubmer=getNubmer();
  			printResult(del(first_nubmer, second_nubmer));
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
  return 0;
}