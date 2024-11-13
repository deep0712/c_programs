#include <stdio.h>

int largestRectangleArea(int heights[], int n) {
    int maxArea = 0, stack[n], top = -1;

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (top != -1 && heights[stack[top]] >= h) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = (maxArea > height * width) ? maxArea : height * width;
        }
        stack[++top] = i;
    }
    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights, 6);
    printf("Largest Rectangle Area: %d\n", result);
    return 0;
}
