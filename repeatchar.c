/*this programm show how many times repeat string like aabbccd out put is 3 beacause aa two time show means repeat 1 time then 1 and bb 1 cc 1...*/
#include <stdio.h>
#include <string.h>

int find(char s[]) {
    char str[10] = "";
    for(int i = 0; i < strlen(s); i++) {
        for(int j = i+1; j <strlen(s); j++) {
            if(s[i] == s[j]) {
                str[strlen(str)] = s[i];
                str[strlen(str) + 1] = '\0';
                break;
            }
        }
    }

    printf("There are %d characters are repeting and %d are non repeting", strlen(str), strlen(s) - strlen(str));
    return 0;
}

int main() {
    char str[100];
    printf("Enter any string:");
    scanf("%s",str);
    find(str);
    return 0;
}