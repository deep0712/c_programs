#include <stdio.h>

#define MAX 100

int stack[MAX];
int increments[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
        increments[top] = 0;
    }
}

int pop() {
    if (top == -1) return -1;
    int result = stack[top] + increments[top];
    if (top != 0) increments[top - 1] += increments[top];
    top--;
    return result;
}

void increment(int k, int val) {
    if (top >= 0) increments[(k > top + 1) ? top : k - 1] += val;
}

int main() {
    push(1);
    push(2);
    increment(2, 100);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    return 0;
}
