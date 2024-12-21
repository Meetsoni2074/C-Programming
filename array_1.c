#include <stdio.h>
#define rows 3
#define cols 3
#define size rows * cols

int stack[size];
int idx = 0;

int push(int val) {
    if(idx >= size) {
        printf("stack is overflowed");
        return -1;
    }else{
        stack[idx] = val;
        idx++;
    }
}

int pop() {
    if(idx <= 0) {
        printf("stack is underflowed");
        return -1;
    }else{
        idx--;
        return stack[idx];
    }
}

int sort(int arr[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            push(arr[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(stack[j] > stack[j + 1]) {
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d", stack[i]);
        printf("\n");
    }
}

int main() {
    int arr[rows][cols] = {{5, 2, 4}, {3, 6, 1}, {9, 7, 8}};
    sort(arr);
    return 0;
}