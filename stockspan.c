#include <stdio.h>

void calculateSpan(int prices[], int n, int span[]) {
    int stack[n], top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && prices[stack[top]] <= prices[i]) top--;
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}

int main() {
    int prices[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];
    calculateSpan(prices, n, span);
    for (int i = 0; i < n; i++) printf("%d ", span[i]);
    printf("\n");
    return 0;
}
