#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 4

struct Seat {
    int row;
    char col;
    int taken;
};

// 1. Passing individual members
void assignSeat_individual(int *taken) {
    if (!*taken) {
        *taken = 1;
    }
}

// 2. Passing whole structure
void assignSeat_structure(struct Seat s, struct Seat *original) {
    if (!s.taken) {
        original->taken = 1;
    }
}

// 3. Passing structure pointer
void assignSeat_pointer(struct Seat *s) {
    if (!s->taken) {
        s->taken = 1;
    }
}

// 4. Passing array of structures
void assignSeat_array(struct Seat seats[ROWS][COLS], int row, int col) {
    if (!seats[row][col].taken) {
        seats[row][col].taken = 1;
    }
}

// Print labeled seat chart
void printSeats(struct Seat seats[ROWS][COLS], const char *title) {
    char rowLabel[] = {'A', 'B', 'C', 'D'};

    printf("\n%s:\n", title);
    printf("   A B C D\n");  // Column headers
    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i + 1); // Row number
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j].taken)
                printf("X ");
            else
                printf("%c ", seats[i][j].col);
        }
        printf("\n");
    }
}

int main() {
    struct Seat seats[ROWS][COLS];
    char colLetters[] = {'A', 'B', 'C', 'D'};

    // Initialize seat values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j].row = i + 1;
            seats[i][j].col = colLetters[j];
            seats[i][j].taken = 0;
        }
    }

    char input[3];
    int row, col, total = 0, con = 1;
    printSeats(seats, "Plane Seats");

    while (total < 20) {
        if (con > 1) {
            printSeats(seats, "Method 1: Individual Members");
            printSeats(seats, "Method 2: Whole Structure");
            printSeats(seats, "Method 3: Structure Pointer");
            printSeats(seats, "Method 4: Array of Structure");
        }

        printf("\nEnter seat (e.g., 1A) or 'Q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
            break;

        if (strlen(input) != 2 || input[0] < '1' || input[0] > '5') {
            printf("Invalid format. Use 1A to 5D.\n");
            con = 1;
            continue;
        }

        row = input[0] - '1';

        char seatLetter = toupper(input[1]);
        if (seatLetter == 'A') col = 0;
        else if (seatLetter == 'B') col = 1;
        else if (seatLetter == 'C') col = 2;
        else if (seatLetter == 'D') col = 3;
        else {
            printf("Invalid seat letter. Must be A-D.\n");
            con = 1;
            continue;
        }

        if (seats[row][col].taken) {
            printf("Seat %d%c is already taken. Try another.\n", seats[row][col].row, seats[row][col].col);
            con = 1;
            continue;
        }

        printf("\nSeat %d%c is now assigned \n", seats[row][col].row, seats[row][col].col);
        printf("Applying input to all 4 methods:\n");

        assignSeat_individual(&seats[row][col].taken);
        assignSeat_structure(seats[row][col], &seats[row][col]);
        assignSeat_pointer(&seats[row][col]);
        assignSeat_array(seats, row, col);

        total++;
        con++;
    }

    printf("\nFinal Seat Plan:\n");
    printSeats(seats, "Method 1: Individual Members");
    printSeats(seats, "Method 2: Whole Structure");
    printSeats(seats, "Method 3: Structure Pointer");
    printSeats(seats, "Method 4: Array of Structure");

    if (total == 20) {
        printf("\nAll seats are now assigned. Thank you for using our program.\n");
    } else {
        printf("\nThank you for using our program.\n");
    }

    return 0;
}
