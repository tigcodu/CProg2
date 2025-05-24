#include <stdio.h> 

struct Airplane {
    char seat;
    char label;
};

void seatArrangement(struct Airplane seat[5][4], struct Airplane label[4]) {
    printf("Seating Arrangement.\n");
    for (int i = 0; i < 4; i++) {
        label[i].label = 'A' + i;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (seat[i][j].seat != 'X') {
                seat[i][j].seat = label[j].label;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%c\t", seat[i][j].seat);
        }
        printf("\n");
    }
}

void choice (int rowChoice, char columnChoice, struct Airplane seat[5][4]) {
    int rowIndex = rowChoice - 1;
    int columnIndex = columnChoice - 'A';
    if (rowIndex >= 0 && rowIndex < 5 && columnIndex >= 0 && columnIndex < 4) {
        if (seat[rowIndex][columnIndex].seat == 'X') {
            printf("Seat %d%c already occupied.\n", rowChoice, columnChoice);
        }
        else {
            seat[rowIndex][columnIndex].seat = 'X';
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
            if (seat[i][j].seat != 'X') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    
    int rowChoice;
    char columnChoice;
    struct Airplane seat[5][4];
    struct Airplane label[4];
    int end;
    
    do {
        printf("---AIRPLANE SEATS---");
        seatArrangement(seat, label);
        printf("Assign a seat? (1 - YES, 0 - NO): ");
        scanf("%d", &end);
        printf("Assigning a passenger seat.\n");
        printf("Enter the row number (1-5): ");
        scanf("%d", &rowChoice);
        printf("Enter the column letter (A-D): ");
        scanf(" %c", &columnChoice);
        choice(rowChoice, columnChoice, seat);
        if (fullSeats(seat)) {
            printf("All seats occupied.\n");
            break;
        }
    } while (end != 0);
    
    return 0;
}