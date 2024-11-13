#include <stdio.h>

int maxHistogramArea(int hist[], int n) {
    int stack[100], top = -1, maxArea = 0;
    for (int i = 0; i <= n; i++) {
        while (top != -1 && (i == n || hist[stack[top]] >= hist[i])) {
            int height = hist[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            maxArea = (height * width > maxArea) ? (height * width) : maxArea;
        }
        stack[++top] = i;
    }
    return maxArea;
}

int maximalRectangle(int matrix[][4], int rows, int cols) {
    int maxArea = 0, histogram[cols];
    for (int i = 0; i < cols; i++) histogram[i] = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) histogram[j] = matrix[i][j] ? histogram[j] + 1 : 0;
        int area = maxHistogramArea(histogram, cols);
        if (area > maxArea) maxArea = area;
    }
    return maxArea;
}

int main() {
    int matrix[4][4] = {
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 0}
    };
    printf("Max Rectangle Area: %d\n", maximalRectangle(matrix, 4, 4));
    return 0;
}
