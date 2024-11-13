#include <stdio.h>
#define MAX 100

int* asteroidCollision(int asteroids[], int n, int* returnSize) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) {
        int alive = 1;
        while (alive && asteroids[i] < 0 && top != -1 && stack[top] > 0) {
            alive = (stack[top] < -asteroids[i]);
            if (stack[top] <= -asteroids[i]) top--;
        }
        if (alive) stack[++top] = asteroids[i];
    }

    *returnSize = top + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) result[i] = stack[i];
    return result;
}

int main() {
    int asteroids[] = {5, 10, -5};
    int n = sizeof(asteroids) / sizeof(asteroids[0]);
    int returnSize;
    int* result = asteroidCollision(asteroids, n, &returnSize);

    for (int i = 0; i < returnSize; i++) printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}
