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

    for (int i = 1; i < size; i++) {
        int key_row = i / columns;
        int key_col = i % columns;
        int key = value[key_row][key_col];
        int j = i - 1;
        while (j >= 0 && value[j / columns][j % columns] > key) {
            value[(j + 1) / columns][(j + 1) % columns] = value[j / columns][j % columns];
            j--;
        }
        value[(j + 1) / columns][(j + 1) % columns] = key;
    }

    printf("\nInsertion Sorted 2D Array: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", value[i][j]);
        }
        printf("\n");
    }

    return 0;
}