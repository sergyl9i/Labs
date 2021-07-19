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
    struct PhoneDirectory *previous;
};

long int getNubmer(){
  bool enterValue=1;
  long int phoneNumber=0;
  while (enterValue == 1){
    printf("Ввведите номер телефона:\n");
    scanf("%ld",&phoneNumber);
    if (phoneNumber <= 0){
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
  printf("Ввведите имя:\n");
  //fgets(startName, N, stdin);
  scanf("%10s",startName);
}

void *getSureame(char *startSurename){
  printf("Ввведите фамилию:\n");
  //fgets(startSurename, S, stdin);
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
  first->previous = NULL;
  //printf("Возвращаемый указатель для коня root + после next: %p | %p\n",first,(*first).next);
  return (first);
}

struct PhoneDirectory *add(struct PhoneDirectory *act, long int number, char *namePolz, char *surenamePolz) {
  struct PhoneDirectory *new, *secondary;
  int i;
  new = (struct PhoneDirectory*)malloc(sizeof(struct PhoneDirectory));
  secondary = act->next; 
  act->next = new; 
  new->phoneNumber = number; 
  for (i = 0; i < N; i++){
    new->name[i] = namePolz[i];
  }
  for (i = 0; i < S; i++){
    new->surename[i] = surenamePolz[i];
  }
  new->next = secondary; 
  new->previous = act;
  if (secondary != NULL){
    secondary->previous = new;
  }
  //printf("Возвращаемый указатель после добавления нового элемента для last + после next: %p | %p\n",new,(*new).next);
  return(new);
}

void listprint(struct PhoneDirectory *first)
{
  struct PhoneDirectory *p;
  p = first;
  do {
    printf("%ld %s %s\n", p->phoneNumber, p->name, p->surename); 
    p = p->next;
  } while (p != NULL);
}

struct PhoneDirectory *deleteRecord(struct PhoneDirectory *delet)
{
  struct PhoneDirectory *step, *prev;
  prev = delet->previous;
  step = delet->next;
  if (prev != NULL)
    prev->next = delet->next;
  if (step != NULL)
    step->previous = delet->previous;
  printf("Удалили запись %ld %s %s\n", (*delet).phoneNumber, (*delet).name, (*delet).surename);
  free(delet); 
  //printf("Возвращаемый указатель после удаления + после next : %p | %p\n",isk,(*isk).next);
  return(prev);
}

struct PhoneDirectory *deletehead(struct PhoneDirectory *root)
{
  struct PhoneDirectory *temp;
  temp = root->next;
  printf("Удалили запись %ld %s %s\n", (*root).phoneNumber, (*root).name, (*root).surename);
  free(root); 
  return(temp);
}

struct PhoneDirectory *findRecord(struct PhoneDirectory *koren, long int nubmer)
{
  struct PhoneDirectory *isk;
  isk = koren;
  while (((*isk).phoneNumber != nubmer) && (isk->next != NULL)){
    isk = isk->next;
  }
  if ((*isk).phoneNumber == nubmer){
    return(isk);
  }
  else{
    return(NULL);
  }
}

void printfRecord(struct PhoneDirectory *record)
{
    printf("Нашли запись c номером %ld %s %s\n", (*record).phoneNumber, (*record).name, (*record).surename);
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
        while ((getchar()) != '\n');
        getName(name);
        while ((getchar()) != '\n');
        getSureame(surename);
        while ((getchar()) != '\n');
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
          present = findRecord(root, phoneNumber);
          if (present == root){
            root = deletehead(present);
            if (root == NULL){
              initDirectory = 0;
            }
          }
          else if (present == last){
            last = deleteRecord(present);
          }
          else if (present == NULL){
              printf("Записи с таким номером телефона нет!\n");
          }
          else{
            present = deleteRecord(present);
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
          if (findRecord(root,phoneNumber) != NULL){
            printfRecord(findRecord(root,phoneNumber));
          }
          else{
            printf("Записи с таким номером не существует!\n");
          }
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
          while (last != root){
            last = deleteRecord(last);
          }
          last = deletehead(last);
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