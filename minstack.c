#include <stdio.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;
int minTop = -1;

void push(int value) {
    stack[++top] = value;
    if (minTop == -1 || value <= minStack[minTop]) {
        minStack[++minTop] = value;
    }
}

void pop() {
    if (top == -1) return;
    if (stack[top] == minStack[minTop]) {
        minTop--;
    }
    top--;
}

int getMin() {
    return minTop == -1 ? INT_MAX : minStack[minTop];
}

int main() {
    push(3);
    push(5);
    printf("Min: %d\n", getMin());
    push(2);
    push(1);
    printf("Min: %d\n", getMin());
    pop();
    printf("Min: %d\n", getMin());
    return 0;
}
