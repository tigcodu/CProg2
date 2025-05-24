#include <stdio.h>
#include <ctype.h>

struct Airplane {
    int numRow;
    char letCol;
} seat[5][4];

void seatingArrangement(struct Airplane seat[5][4]) {
    printf("Seating Arrangement.\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (seat[i][j].numRow == 0) {
                seat[i][j].numRow = i + 1;
                seat[i][j].letCol = 'A' + j;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\t", seat[i][0].numRow);
        for (int j = 0; j < 4; j++) {
            printf("%c\t", seat[i][j].letCol);
        }
        printf("\n");
    }
}

void choice (struct Airplane seat[5][4], int rowChoice, char columnChoice) { 
    int rowIndex = rowChoice - 1;
    int columnIndex = columnChoice - 'A';
    if (rowIndex >= 0 && rowIndex < 5 && columnIndex >= 0 && columnIndex < 4) {
        if (seat[rowIndex][columnIndex].letCol == 'X') {
            printf("Seat %d%c already occupied.\n", rowChoice, columnChoice);
        }
        else {
            seat[rowIndex][columnIndex].letCol = 'X';
            printf("Seat %d%c has been reserved.\n", rowChoice, columnChoice);
        }
    }
    else {
        printf("Seat Invalid.\n");
    }
}

int fullSeats (struct Airplane seat[5][4]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (seat[i][j].letCol != 'X') {
                return 0;
            }
        }
    }
    return 1;
}


int main() {

    int rowChoice;
    char columnChoice;

    do {
        seatingArrangement(seat);
        if (fullSeats(seat)) {
            printf("All seats occupied.\n");
            break;
        }
        printf("Assigning a passenger seat.\n");
        printf("Enter the seat number (1-5) & label (A-D), or 0 to quit: ");
        scanf("%d", &rowChoice); 
        if (rowChoice == 0) {
            printf("Exiting the program.\n");
            break;
        }
        scanf(" %c", &columnChoice);
        columnChoice = toupper(columnChoice);
        choice(seat, rowChoice, columnChoice);

    } while (1);

    return 0;
}