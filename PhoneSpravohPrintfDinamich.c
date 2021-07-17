#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define N 11
#define S 21

struct PhoneDirectory
{
    long int phoneNumber;
    char name[N];
    char surename[S];
    struct PhoneDirectory *next;
};

long int getNubmer(){
  bool enterValue=1;
  long int phoneNumber=0;
  while (enterValue == 1){
    printf("Ввведите номер телефона:\n");
    scanf("%ld",&phoneNumber);
    if (phoneNumber == 0){
      printf("Некорректный ввод. Повторите ещё раз.\n");
      while ((getchar()) != '\n');
    }
    else{
      enterValue=0;
    }
  }
  return phoneNumber;
}

void *getName(char *startName){
    while ((getchar()) != '\n');
    printf("Ввведите имя:\n");
    scanf("%10s",startName);
}

void *getSureame(char *startSurename){
  while ((getchar()) != '\n');
  printf("Ввведите фамилию:\n");
  scanf("%20s",startSurename);
}

struct PhoneDirectory *init(long int zd, char *namePolz, char *surenamePolz){
  struct PhoneDirectory *first;
  int i;
  first = (struct PhoneDirectory*)malloc(sizeof(struct PhoneDirectory));
  first->phoneNumber = zd;
  for (i = 0; i < N; i++){
    first->name[i] = namePolz[i];
  }
  for (i = 0; i < S; i++){
    first->surename[i] = surenamePolz[i];
  }
  first->next = NULL;
  //printf("Возвращаемый указатель для коня root + после next: %p | %p\n",first,(*first).next);
  return (first);
}

struct PhoneDirectory *add(struct PhoneDirectory *act, long int number, char *namePolz, char *surenamePolz) {
  struct PhoneDirectory *actually, *p;
  int i;
  actually = (struct PhoneDirectory*)malloc(sizeof(struct PhoneDirectory));
  p = act->next; // сохранение указателя на следующий узел
  act->next = actually; // предыдущий узел указывает на создаваемый
  actually->phoneNumber = number; // сохранение поля данных добавляемого узла
  for (i = 0; i < N; i++){
    actually->name[i] = namePolz[i];
  }
  for (i = 0; i < S; i++){
    actually->surename[i] = surenamePolz[i];
  }
  actually->next = p; // созданный узел указывает на следующий элемент
  //printf("Возвращаемый указатель после добавления нового элемента для last + после next: %p | %p\n",actually,(*actually).next);
  return(actually);
}

void listprint(struct PhoneDirectory *first)
{
  struct PhoneDirectory *p;
  p = first;
  do {
    printf("%ld %s %s\n", p->phoneNumber, p->name, p->surename); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL);
}

struct PhoneDirectory *deletePhoneDirecorory(struct PhoneDirectory *isk, struct PhoneDirectory *koren)
{
  struct PhoneDirectory *temp;
  temp = koren;
  while (temp->next != isk){ // пока не найдем узел, предшествующий lst
    temp = temp->next;
  }
  temp->next = isk->next; // переставляем указатель
  free(isk); // освобождаем память удаляемого узла
  return(temp);
}

struct PhoneDirectory *deleteRecord(struct PhoneDirectory *end, struct PhoneDirectory *koren, long int nubmer)
{
  struct PhoneDirectory *temp, *isk;
  temp = koren;
  while (((*temp).phoneNumber != nubmer) && (temp != end)){ 
    isk = temp;
    temp = temp->next;
  }
  if ((*temp).phoneNumber == nubmer){
    isk->next = temp->next; // переставляем указатель
    printf("Удалили запись с номером %ld %s %s\n", (*temp).phoneNumber, (*temp).name, (*temp).surename);
    free(temp); // освобождаем память удаляемого узла
    //printf("Возвращаемый указатель после удаления + после next : %p | %p\n",isk,(*isk).next);
    return(isk);
  }
  else{
    printf("Записи c номером %ld нет!\n", (*temp).phoneNumber);
    return(end);
  }
}

struct PhoneDirectory *deletehead(struct PhoneDirectory *root)
{
  struct PhoneDirectory *temp;
  temp = root->next;
  free(root); // освобождение памяти текущего корня
  //printf("Удалили корень\n");
  return(temp); // новый корень списка
}

void findRecord(struct PhoneDirectory *end, struct PhoneDirectory *koren, long int nubmer)
{
  struct PhoneDirectory *temp, *isk;
  temp = koren;
  while (((*temp).phoneNumber != nubmer) && (temp != end)){
    temp = temp->next;
  }
  if ((*temp).phoneNumber == nubmer){
    printf("Нашли запись c номером %ld %s %s\n", (*temp).phoneNumber, (*temp).name, (*temp).surename);
  }
  else{
    printf("Записи c номером %ld нет!\n", (*temp).phoneNumber);
  }
}

int main() {	
  char choice;
  struct PhoneDirectory *root;
  struct PhoneDirectory *last;
  struct PhoneDirectory *present;
    bool initDirectory=0;
    do {
      printf("Выберите пункт меню: \n1 - Создать новую запись.\n2 - Удалить запись.\n3 - Найти запись.\n4 - Вывести весь телефонный справочник.\n5 - Закрыть программу.\n");
      scanf(" %c",&choice);
      while ((getchar()) != '\n');
      long int phoneNumber=0;
      char name[N];
      char surename[S];      
      switch(choice) {
      case '1':
        phoneNumber = getNubmer();
        getName(name);
        getSureame(surename);
        if (0 == initDirectory){
          root = init(phoneNumber,name,surename);
          last = root;
          present = last;
          initDirectory = 1;
        }
        else {
            last = add(last,phoneNumber,name,surename);
            present = last;
        }
      break;
      case '2':
        if (0 == initDirectory){
          printf("Телефонный справочник пуст!\n");
        }
        else{
          printf("Удаление элетемента по номеру телефона\n");
          phoneNumber = getNubmer();
          if (present == root){
            present = deletehead(root);
            initDirectory = 0;
          }
          else{
            present = deleteRecord(last,root,phoneNumber);
            if (present->next != NULL){
              present = last;
            }
          }
        }
      break;
      case '3':
        if (0 == initDirectory){
          printf("Телефонный справочник пуст!\n");
        }
        else{
        printf("Поиск элетемента по номеру телефона\n");
        phoneNumber = getNubmer();
        findRecord(last,root,phoneNumber);
        }
      break;
      case '4':
        if (0 == initDirectory){
          printf("Телефонный справочник пуст!\n");
        }
        else{
          printf("Полный телефонный справочник:\n");
          listprint(root);
        }
      break;
      case '5':
        printf("Спасибо что запускали наш справочник!\n");
        if (1 == initDirectory){
          while (present != root){
            present = deletePhoneDirecorory(last,root);
          }
          root = deletehead(root);
        }
        break;
      default:
        printf("Вы не выбрали пункт меню!\n");
      break;
    }
  }
    while (choice != '5');
  	return 0;
}