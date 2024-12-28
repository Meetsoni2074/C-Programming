#include <stdio.h>
#include <string.h>
#define MAX_ACC 100

typedef struct {
    char name[30];
    int password;
    int balance;
} User;

User users[MAX_ACC];
int curr = 0;
int lidx = -1;

int create_acc() {
    printf("Enter The Name Of Account Owner: ");
    scanf("%s", users[curr].name);
    printf("Enter Password: ");
    scanf("%d", &users[curr].password);
    users[curr].balance = 1000; 
    printf("\nAccount has been created successfully!\n");
    curr++;
    return 0;
}

int login() {
    char name[30];
    int pass;

    printf("Enter The Name Of The User: ");
    scanf("%s", name);
    printf("Enter The Password Of The User: ");
    scanf("%d", &pass);

    for (int i = 0; i < curr; i++) {
        if (strcmp(name, users[i].name) == 0 && pass == users[i].password) {
            lidx = i;
            printf("\nLogin successful! Welcome, %s\n", users[lidx].name);
            return 0;
        }
    }

    printf("\nThe Input Details Are Invalid!\n");
    return 1;
}

int check_balance() {
    if (lidx == -1) {
        printf("\nYou Need To Login First\n");
        return 1;
    }
    printf("\nThe Current Balance Is: %d\n", users[lidx].balance);
    return 0;
}

int deposit_money() {
    if (lidx == -1) {
        printf("\nYou Need To Login First\n");
        return 1;
    }

    int amt;
    printf("Enter The Amount You Want To Deposit: ");
    scanf("%d", &amt);
    users[lidx].balance += amt;
    printf("\nThe Amount Of %d Has Been Credited Successfully.\n", amt);
    return 0;
}

int withdraw_money() {
    if (lidx == -1) {
        printf("\nYou Need To Login First\n");
        return 1;
    }

    int amt;
    printf("Enter The Amount You Want To Withdraw: ");
    scanf("%d", &amt);

    if (amt > users[lidx].balance) {
        printf("\nYou Don't Have Sufficient Balance To Withdraw That Much Amount!\n");
        return -1;
    }

    users[lidx].balance -= amt;
    printf("\nYou Have Withdrawn The Amount %d Successfully.\n", amt);
    return 0;
}

int logout() {
    if (lidx != -1) {
        printf("\nYou Are Successfully Logged Out. Thank You, %s!\n", users[lidx].name);
        lidx = -1;
    } else {
        printf("\nNo User Is Currently Logged In.\n");
    }
    return 0;
}

int main() {
    int choice;

    while (1) {
        if (lidx == -1) {
            printf("\n*BANK MANAGEMENT SYSTEM*\n");
            printf("1. Create Account\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter Your Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    create_acc();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    printf("\nExiting the system. Goodbye!\n");
                    return 0;
                default:
                    printf("\nInvalid Choice! Please Try Again.\n");
                    break;
            }
        } else {
            printf("\n*WELCOME, %s*\n", users[lidx].name);
            printf("1. Check Balance\n");
            printf("2. Deposit Money\n");
            printf("3. Withdraw Money\n");
            printf("4. Logout\n");
            printf("Enter Your Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    check_balance();
                    break;
                case 2:
                    deposit_money();
                    break;
                case 3:
                    withdraw_money();
                    break;
                case 4:
                    logout();
                    break;
                default:
                    printf("\nInvalid Choice! Please Try Again.\n");
                    break;
            }
        }
    }

    return 0;
}
