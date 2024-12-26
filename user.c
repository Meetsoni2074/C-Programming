#include <stdio.h>
#include <string.h>
#define MAX_USER 10

int curr = 0;

typedef struct {
    char name[30];
    char password[30];
} User;

User users[MAX_USER];

int register_user() {
    printf("\n*Register The User Info*\n");
    if(curr >= MAX_USER) {
        printf("The Number Of User Are Limited And List Is Full For Now!!!");
        return -1;
    }else{
        printf("Enter The Username Of The User : ");
        scanf("%29s", &users[curr].name);
        printf("Enter The Password Of The User : ");
        scanf("%29s", &users[curr].password);
        printf("\nUser Registered Successfully");
        curr++;
        return 0;
    }
}

int login_user() {
    char name[30];
    char pass[30];
    printf("Enter The Username Of The User : ");
    scanf("%29s", &name);
    printf("Enter The Password Of The User : ");
    scanf("%29s", &pass);

    for(int i = 0; i < curr; i++) {
        if(strcmp(name, users[i].name) == 0){
            if(strcmp(pass, users[i].password) == 0) {
                printf("\nLogin Successfull\n");
                return 0;
            }else{
                printf("\nThe Password Is Incorrect\n");
                return 1;
            }
        }
    }
    printf("\nUser Not Found..!!!\n");
    return 1;
}

int main() {
    int choice;

    while (1){
    printf("\n*User Management*\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter Your Choice : ");
    scanf("%d", &choice);
    switch (choice) {
            case 1:
                register_user();
                break;
    
            case 2:
                login_user();
                break;

            case 3:
                printf("\nExiting The Programme\n");
                return 0;
            
            default :
                printf("Invalid Choice Please Try Another Choice");
        }
    }
    
    return 0;
}