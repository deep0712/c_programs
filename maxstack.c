#include <stdio.h>
#include <limits.h>
#define MAX 100

int stack[MAX], maxStack[MAX], top = -1, maxTop = -1;

void push(int x) {
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop]) maxStack[++maxTop] = x;
}

int pop() {
    if (top == -1) return INT_MIN;
    if (stack[top] == maxStack[maxTop]) maxTop--;
    return stack[top--];
}

int getMax() {
    return (maxTop == -1) ? INT_MIN : maxStack[maxTop];
}

int main() {
    push(3);
    push(5);
    printf("Max: %d\n", getMax());
    push(2);
    push(7);
    printf("Max: %d\n", getMax());
    pop();
    printf("Max: %d\n", getMax());
    return 0;
}
