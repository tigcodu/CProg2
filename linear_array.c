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

    int a, b;
    int target;
    int result;

    printf("\nPlease enter your target: ");
    scanf("%d", &target);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (value[i][j] == target) {
                result = target;
                a = i;
                b = j;
            }
        }
    }

    if (target == result) {
        printf("The target is located at row[%d] and column[%d]", a, b);
    }
    else {
        printf("Target not found.");
    }

    return 0;
}