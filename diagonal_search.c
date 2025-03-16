// Grp1 and 5 Write a function that searches for a specific value along the diagonal of a square 2D array (where the number of rows equals the number of columns). If the element is found, return its position; otherwise, return "Element not found on the diagonal."

#include <stdio.h>

int diagonalSearch(int index, int value[index][index], int target) {
    for (int i = 0; i < index; i++) {
        if (value[i][i] == target) {
            return i;
        }
    }
    return -1;
}

int antiDiagonal(int index, int *rows, int *columns, int value[index][index], int target) {
    for (int i = 0; i < index; i++) {
        if (target == value[i][index - i - 1]) {
            *rows = i;
            *columns = index - i - 1;
            return 1;
        }
    }
    return 0;
}

int main() {
   
    int index, try;

    do {

        do {
            printf("Please enter your desired no. of rows & columns: ");
            if (scanf("%d", &index) != 1 || index <= 0) {
                printf("Invalid Input! Please enter a positive number.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);

        int value[index][index];
        int size = sizeof(value) / sizeof(value[0][0]);

        printf("\nPlease enter %d integers:\n", size);
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                do {
                    printf("[%d][%d]: ", i, j);
                    if (scanf("%d", &value[i][j]) != 1) {
                        printf("Invalid Input! Please enter a number.\n");
                    while (getchar() != '\n');
                    }
                    else {
                        break;
                    }
                } while (1);
            }
        }

        int target;

        do{
            printf("\nPlease enter your target: ");
            if (scanf("%d", &target) != 1) {
                printf("Invalid Input! Please enter a number.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        
        int result = diagonalSearch(index, value, target);

        if (result != -1) {
            printf("\nDiagonal: The target %d is located at row[%d] and column[%d].", target, result, result);
        }
        else {
            printf("\nDiagonal: Element not found.");
        }
        
        int rows, columns;
        
        if (antiDiagonal(index, &rows, &columns, value, target)) {
            printf("\nAnti-Diagonal: The target %d is located at row[%d] and column[%d].", target, rows, columns);
        }
        else {
            printf("\nAnti-Diagonal: Element not found.");
        }

        do {
            printf("\n\nDo you want to try again? (1 if yes, 0 if no): ");
            if (scanf("%d", &try) != 1 || try > 1 || try < 0) {
                printf("Invalid Input! Please only enter 1 or 0.");
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