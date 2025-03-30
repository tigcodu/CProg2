#include <stdio.h>

void perfectSquare(int number, int root) {
    int square = root * root;
    if (square > number) {
        return;
    }
    printf("%d\t", square);
    perfectSquare(number, ++root);
}

int main() {

    int number;

    do {
        printf("Enter a positive integer: ");
        if ((scanf("%d", &number)) == 1 && number > 0) {
            break;
        }
        printf("Invalid Input. Please enter a positive number.\n");
        while (getchar() != '\n');
    } while (1);

    int root = 1;

    printf("\nHere are the perfect squares until %d: \n", number);
    perfectSquare(number, root);

    return 0;
}

/*
#include <stdio.h>

void perfectSquare(int number, int root, int count) {
    int square = root * root;
    if (square > number) {
        return;
    }
    printf("%d\t", square);
    count++;
    if (count % 8 == 0) {
        printf("\n");
    }
    perfectSquare(number, root + 1, count);
}

int main() {

    int number;

    do {
        printf("Enter a positive integer: ");
        if ((scanf("%d", &number)) == 1 && number > 0) {
            break;
        }
        printf("Invalid Input. Please enter a positive number.\n");
        while (getchar() != '\n');
    } while (1);

    int root = 1;
    int count = 0;

    printf("\nHere are the perfect squares until %d: \n", number);
    perfectSquare(number, root, count);

    return 0;
}
*/