#include <stdio.h>

#define MAX 100

void sortedInsert(int stack[], int *top, int value) {
    if (*top == -1 || stack[*top] <= value) {
        stack[++(*top)] = value;
    } else {
        int temp = stack[(*top)--];
        sortedInsert(stack, top, value);
        stack[++(*top)] = temp;
    }
}

void sortStack(int stack[], int *top) {
    if (*top != -1) {
        int temp = stack[(*top)--];
        sortStack(stack, top);
        sortedInsert(stack, top, temp);
    }
}

int main() {
    int stack[MAX] = {30, -5, 18, 14, -3};
    int top = 4;

    sortStack(stack, &top);

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}
