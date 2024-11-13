#include <stdio.h>
#include <string.h>

void removeDuplicates(char* str) {
    int stack[100], top = -1;

    for (int i = 0; str[i]; i++) {
        if (top == -1 || stack[top] != str[i]) stack[++top] = str[i];
        else top--;
    }
    stack[++top] = '\0';
    printf("After removing duplicates: %s\n", stack);
}

int main() {
    char str[] = "abbaca";
    removeDuplicates(str);
    return 0;
}
