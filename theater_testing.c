#include <stdio.h>

void seatingChart(int rows, int columns, char theater[rows][columns]) {
    printf("Seating Chart: \n");
    printf("\t");
    for (int h = 0; h < columns; h++) {
        printf("%d\t", h);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (theater[i][j] != 'R') {
                theater[i][j] = 'A';
            }
            if (j == 0)  {
                printf("Row %d:\t", i);
            }
            printf("%c\t", theater[i][j]);
        }
        printf("\n");
    }
}

void reserveSeat(int rows, int columns, int target_row, int target_col, char theater[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (target_row == i && target_col == j) {
                theater[target_row][target_col] = 'R';
                printf("\nSeat at row %d, and column %d has been reserved.\n", target_row, target_col);
            }
        }
    }
}

void cancelSeat(int rows, int columns, int target_row, int target_col, char theater[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (target_row == i && target_col == j) {
                theater[target_row][target_col] = 'A';
                printf("\nSeat at row %d, and column %d has been cancelled.\n", target_row, target_col);
            }
        }
    }
}

int main() {
    
    int rows = 5;
    int columns = 10;
    char theater[rows][columns];
    int select;
    int target_row, target_col;
    
    do {
        do {
        printf("\nCinema Seat Reservation System\n");
        printf("1. Display seating chart\n");
        printf("2. Reserve a seat\n");
        printf("3. Cancel a reservation\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &select) != 1) {
            printf("INVALID INPUT. Please enter the applicable choice.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
        } while (1);
        printf("\n");
    
    if (select == 1) {
        seatingChart(rows, columns, theater);
    }
    else if (select == 2) {
        do {
        do {
        printf("Enter row (0-4) to reserve: ");
            if (scanf("%d", &target_row) != 1) {
            printf("INVALID INPUT. Please enter the applicable choice.\n");
            while (getchar() != '\n');
            } else {
                break;
            }
        } while (1);
        if (target_row > 4 || target_row < 0) {
            printf("INVALID INPUT. Please enter the applicable choice.\n");
        }
        else {
            do {
            do {
            printf("Enter column (0-9) to reserve: ");
                if (scanf("%d", &target_col) != 1) {
                printf("INVALID INPUT. Please enter the applicable choice.\n");
                while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
                if (target_col > 9 || target_col < 0) {
                    printf("INVALID INPUT. Please enter the applicable choice.\n");
                }
                else {
                    reserveSeat(rows, columns, target_row, target_col, theater);
                }
            } while (target_col > 9 || target_col < 0);
        }
        } while (target_row > 4 || target_row < 0);
        
        
    }
    else if (select == 3) {
        do {
        do {
        printf("Enter row (0-4) to cancel reservation: ");
            if (scanf("%d", &target_row) != 1) {
            printf("INVALID INPUT. Please enter the applicable choice.\n");
            while (getchar() != '\n');
            } else {
                break;
            }
        } while (1);
        if (target_row > 4 || target_row < 0) {
            printf("INVALID INPUT. Please enter the applicable choice.\n");
        }
        else {
            do {
            do {
            printf("Enter column (0-9) to cancel reservation: ");
                if (scanf("%d", &target_col) != 1) {
                printf("INVALID INPUT. Please enter the applicable choice.\n");
                while (getchar() != '\n');
                } else {
                    break;
                }
            } while (1);
                if (target_col > 9 || target_col < 0) {
                    printf("INVALID INPUT. Please enter the applicable choice.\n");
                }
                else {
                    cancelSeat(rows, columns, target_row, target_col, theater);
                }
            } while (target_col > 9 || target_col < 0);
        }
        } while (target_row > 4 || target_row < 0);
        
        
    }
    else if (select == 4) {
        printf("Exiting the program.");
        break;
    }
    else {
        printf("INVALID INPUT. Please enter the applicable choice.\n");
    }
    
    
    } while (select != 4);

    return 0;
}