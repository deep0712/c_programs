#include <stdio.h>

int validateStackSequences(int pushed[], int popped[], int n) {
    int stack[100], top = -1, j = 0;
    for (int i = 0; i < n; i++) {
        stack[++top] = pushed[i];
        while (top != -1 && stack[top] == popped[j]) {
            top--;
            j++;
        }
    }
    return j == n;
}

int main() {
    int pushed[] = {1, 2, 3, 4, 5};
    int popped[] = {4, 5, 3, 2, 1};
    int n = sizeof(pushed) / sizeof(pushed[0]);
    printf("Is valid sequence: %s\n", validateStackSequences(pushed, popped, n) ? "Yes" : "No");
    return 0;
}
