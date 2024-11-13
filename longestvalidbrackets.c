#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int maxLen = 0, lastInvalid = -1, stack[strlen(s)], top = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') stack[++top] = i;
        else {
            if (top == -1) lastInvalid = i;
            else {
                top--;
                maxLen = (top == -1) ? ((i - lastInvalid > maxLen) ? (i - lastInvalid) : maxLen) : ((i - stack[top] > maxLen) ? (i - stack[top]) : maxLen);
            }
        }
    }
    return maxLen;
}

int main() {
    char s[] = "(()))())(";
    printf("Longest Valid Parentheses: %d\n", longestValidParentheses(s));
    return 0;
}
