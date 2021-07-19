#include <stdio.h>
#include <stdbool.h>

#define N 10

struct PhoneDirectory
{
    long phoneNumber;
    char name[11];
    char surename[21];
};

int main()
{   
    struct PhoneDirectory phoneDirectory[N];
    for (int i=0;i < N;i++){
        phoneDirectory[i].phoneNumber = 0;
        phoneDirectory[i].name[0] ='\0';
        phoneDirectory[i].surename[0] ='\0';        
    }
    char choice;
            do {
            printf("Select what a you want to do: \n1 - Enter a new record.\n2 - Delete a record.\n3 - Find a record.\n4 - Output all Phone Directory.\n5 - Exit a programm.\n");
            bool checkLog=1;
            bool enterValue=1;
            long int phoneNumberDelete=0;
            long int phoneNumberFind=0;
            //scanf("%*1[\n]");
            scanf(" %c",&choice);
            switch(choice) {
                case '1':
                        for (int i=0;i < N;i++){
                            if (phoneDirectory[i].phoneNumber == 0){
                                while (enterValue == 1)
                                {
                                printf("Enter a phone number:\n");
                                scanf("%ld",&phoneDirectory[i].phoneNumber);
                                if (phoneDirectory[i].phoneNumber == 0){ 
                                        printf("Your input is invalid. Please try again.\n");
                                        while ((getchar()) != '\n');
                                    }
                                else                   
                                        enterValue=0;
                                }
                        while ((getchar()) != '\n');
                        printf("Enter a name:\n");
                        scanf("%10s",phoneDirectory[i].name);
                        //phoneDirectory[i].name[11]='\0';
                        while ((getchar()) != '\n');
                        printf("Enter a surename:\n");
                        scanf("%20s",phoneDirectory[i].surename);
                        //phoneDirectory[i].surename[21]='\0';
                        while ((getchar()) != '\n');
                        checkLog = 0;
                        break;
                        }
                    }
                    if (checkLog == 1)
                        printf("Error! Doesn't have a empty slots in phone directory!\n");
                    break;
                case '2':
                            while (enterValue == 1)
                                {
                                printf("Enter a phone number for delete a record:\n");
                                scanf("%ld",&phoneNumberDelete);
                                if (phoneNumberDelete == 0){
                                        printf("Your input is invalid. Please try again.\n");
                                        while ((getchar()) != '\n');
                                    }
                                else                   
                                        enterValue=0;
                                }
                    for (int i=0;i < N;i++){
                        if (phoneNumberDelete == phoneDirectory[i].phoneNumber){
                            printf("You delete a record: %ld %s %s\n",phoneDirectory[i].phoneNumber,phoneDirectory[i].name,phoneDirectory[i].surename);
                            phoneDirectory[i].phoneNumber = 0;        
                            phoneDirectory[i].name[0] ='\0';
                            phoneDirectory[i].surename[0] ='\0'; 
                            checkLog = 0;
                            break;                           
                            }
                        }
                        if (checkLog == 1)                            
                        printf("Error delete a record! You enter a wrong nubmer!\n");
                        break;
                case '3':
                            while (enterValue == 1)
                                {
                                printf("Enter a phone number for find a record:\n");
                                scanf("%ld",&phoneNumberFind);
                                if (phoneNumberFind == 0){ 
                                        printf("Your input is invalid. Please try again.\n");
                                        while ((getchar()) != '\n');
                                    }
                                else                   
                                        enterValue=0;
                                }                    
                    for (int i=0;i < N;i++){
                        if (phoneNumberFind == phoneDirectory[i].phoneNumber){
                            printf("You find a record: %d %ld %s %s\n",i+1,phoneDirectory[i].phoneNumber,phoneDirectory[i].name,phoneDirectory[i].surename);
                            checkLog = 0;                            
                            break;                           
                            }
                        }
                        if (checkLog == 1)                    
                        printf("Error find a record! You enter a wrong nubmer!\n");
                        break;
                case '4':
                        for (int i=0;i < N;i++){
                            if (phoneDirectory[i].phoneNumber != 0){
                            printf("%1d %ld %s %s\n",i+1,phoneDirectory[i].phoneNumber,phoneDirectory[i].name,phoneDirectory[i].surename);
                            checkLog = 0;
                            }
                        }
                        if (checkLog == 1)                           
                        printf("Error trace a phone directory! Phone Directory is empty!\n");
                        break;
                case '5':
                    printf("Thanks for open Phone Direcotry!\n");
                    break;                
                default:
                    printf("Error! Wrong input.\n");
                    break;
                    }  
        }
        while (choice != '5');
    return 0;
}