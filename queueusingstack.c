#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int x) {
    stack1[++top1] = x;
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) stack2[++top2] = stack1[top1--];
    }
    return (top2 == -1) ? -1 : stack2[top2--];
}

int main() {
    enqueue(1);
    enqueue(2);
    printf("%d ", dequeue());
    enqueue(3);
    printf("%d ", dequeue());
    printf("%d\n", dequeue());
    return 0;
}
