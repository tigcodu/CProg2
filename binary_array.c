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
    
    int target;

    printf("\nPlease enter your target: ");
    scanf("%d", &target);

    int found = 0;
    int left_row = 0;
    int left_col = 0;
    int right_row = rows - 1;
    int right_col = columns - 1;
    int mid, mid_row, mid_col;

    while (left_row <= right_row && left_col <= right_col) {
        mid = ((left_row * columns + left_col) + (right_row * columns + right_col)) / 2;
        mid_row = mid / columns;
        mid_col = mid % columns;
        if (target == value[mid_row][mid_col]) {
                printf("The target is located at row[%d] and column[%d]", mid_row, mid_col);
                found = 1;
                break;
        }
        else if (target < value[mid_row][mid_col]) {
            right_row = mid_row;
            right_col = mid_col - 1;
            if (right_col < 0) {
                right_row -= 1;
                right_col = columns - 1;
            }
        }
        else {
            left_row = mid_row;
            left_col = mid_col + 1;
            if (left_col == columns) {
                left_row += 1;
                left_col = 0;
            }
        }
    }

    if (!found) {
        printf("Target not found.");
    }

    return 0;
}

/*
alternate

    int found = 0;
    int left = 0;
    int right = size - 1;
    int mid, mid_row, mid_col;

    while (left <= right) {
        mid = (left + right) / 2;
        mid_row = mid / columns;
        mid_col = mid % columns;
        if (target == value[mid_row][mid_col]) {
                printf("The target is located at row[%d] and column[%d]", mid_row, mid_col);
                found = 1;
                break;
        }
        else if (target < value[mid_row][mid_col]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }



*/