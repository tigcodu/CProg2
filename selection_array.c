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
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            int left_row = minIndex / columns;
            int left_col = minIndex % columns;
            int right_row = j / columns;
            int right_col = j % columns;
            if (value[right_row][right_col] < value[left_row][left_col]) {
                minIndex = j;
            }
        }
        int left_row = i / columns;
        int left_col = i % columns;
        int right_row = minIndex / columns;
        int right_col = minIndex % columns;
        
        int temp = value[right_row][right_col];
        value[right_row][right_col] = value[left_row][left_col];
        value[left_row][left_col] = temp;
    }

    printf("\nSelection Sorted 2D Array: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", value[i][j]);
        }
        printf("\n");
    }

    return 0;
}