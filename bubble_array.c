#include <stdio.h>

int main() {

    int rows, columns;

    printf("Please enter your desired no. of rows: ");
    scanf("%d", &rows);
    printf("Please enter your desired no. of columns: ");
    scanf("%d", &columns);

    int value[rows][columns];
    int size = sizeof(value) / sizeof(value[0][0]);

    printf("\nPlease enter %d integers:\n", size);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &(value[i][j]));
        }
    }

    printf("\nOriginal 2D Array: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", value[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int left_row = j / columns;
            int left_col = j % columns;
            int right_row = (j + 1) / columns;
            int right_col = (j + 1) % columns;
            if (value[right_row][right_col] < value[left_row][left_col]) {
                int temp = value[left_row][left_col];
                value[left_row][left_col] = value[right_row][right_col];
                value[right_row][right_col] = temp;
            }
        }
    }

    printf("\nBubble Sorted 2D Array: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", value[i][j]);
        }
        printf("\n");
    }

    return 0;
}