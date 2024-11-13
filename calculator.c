#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[100], top = -1, result = 0, sign = 1;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < strlen(s) && isdigit(s[i])) num = num * 10 + (s[i++] - '0');
            result += sign * num;
            i--;
        } else if (s[i] == '+') sign = 1;
        else if (s[i] == '-') sign = -1;
        else if (s[i] == '(') {
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (s[i] == ')') {
            result = stack[top--] * result + stack[top--];
        }
    }
    return result;
}

int main() {
    char expression[] = "(1+(4+5+2)-3)+(6+8)";
    printf("Result: %d\n", calculate(expression));
    return 0;
}
