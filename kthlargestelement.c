#include <stdio.h>

void sortStack(int stack[], int* top) {
    int tempStack[100], tempTop = -1;
    while (*top != -1) {
        int temp = stack[(*top)--];
        while (tempTop != -1 && tempStack[tempTop] > temp) stack[++(*top)] = tempStack[tempTop--];
        tempStack[++tempTop] = temp;
    }
    while (tempTop != -1) stack[++(*top)] = tempStack[tempTop--];
}

int findKthLargest(int stack[], int top, int k) {
    sortStack(stack, &top);
    return stack[top - k + 1];
}

int main() {
    int stack[] = {10, 30, 20, 50, 40};
    int top = 4, k = 3;
    printf("%d-th Largest: %d\n", k, findKthLargest(stack, top, k));
    return 0;
}
