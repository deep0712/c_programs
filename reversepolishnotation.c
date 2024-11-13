#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int evalRPN(char *tokens[], int tokensSize) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            if (strcmp(tokens[i], "+") == 0) stack[++top] = a + b;
            else if (strcmp(tokens[i], "-") == 0) stack[++top] = a - b;
            else if (strcmp(tokens[i], "*") == 0) stack[++top] = a * b;
            else stack[++top] = a / b;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens, 5);
    printf("Result: %d\n", result);
    return 0;
}
