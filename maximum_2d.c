#include <stdio.h>

int maximumValue(int rows, int columns, int value[rows][columns], int *a, int *b, int *max) {
    *max = value[0][0];
    *a = 0;
    *b = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (*max < value[i][j]) {
                *max = value[i][j];
                *a = i;
                *b = j;
            }
        }
    }
}

int main() {
    
    int rows, columns, try;

    do {

        do {
            printf("Please enter your desired no. of rows: ");
            if (scanf("%d", &rows) != 1 || rows <= 0) {
                printf("Invalid Input! Please enter a positive number.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);

        do {
            printf("Please enter your desired no. of columns: ");
            if (scanf("%d", &columns) != 1 || columns <= 0) {
                printf("Invalid Input! Please enter a positive number.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);

        int value[rows][columns];
        int size = sizeof(value) / sizeof(value[0][0]);

        printf("\nPlease enter %d integers:\n", size);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                do {
                    printf("[%d][%d]: ", i, j);
                    if (scanf("%d", &(value[i][j])) != 1) {
                        printf("Invalid Input! Please enter a number.\n");
                        while (getchar() != '\n');
                    }
                    else {
                        break;
                    }
                } while (1);
            }
        }
        
        int a, b, max;
        maximumValue(rows, columns, value, &a, &b, &max);
        printf("\nThe maximum value is %d, which is located at row %d and column %d.\n", max, a, b);

        do {
            printf("\nDo you want to try again? (1 if yes, 0 if no): ");
            if (scanf("%d", &try) != 1 || try > 1 || try < 0) {
                printf("Invalid Input! Please only enter 1 or 0.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);

        printf("\n");

        if (try == 0) {
            printf("Thank you for using our program!");
        }

    } while (try != 0);  

    return 0;
}