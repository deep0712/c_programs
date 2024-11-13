#include <stdio.h>
#define N 4

int knows(int M[N][N], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[N][N]) {
    int stack[N], top = -1;

    for (int i = 0; i < N; i++) stack[++top] = i;

    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];
        stack[++top] = knows(M, a, b) ? b : a;
    }

    int candidate = stack[top];
    for (int i = 0; i < N; i++) {
        if ((i != candidate) && (knows(M, candidate, i) || !knows(M, i, candidate))) return -1;
    }
    return candidate;
}

int main() {
    int M[N][N] = {{0, 1, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 1, 0}};
    int result = findCelebrity(M);
    if (result == -1) printf("No Celebrity\n");
    else printf("Celebrity is: %d\n", result);
    return 0;
}
