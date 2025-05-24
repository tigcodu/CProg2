#include <stdio.h>

struct card {
    char value;
    char suit;
};

void legendChart() {
    printf("Legend:\n");
    printf("T - Ten, J - Jack, Q - Queen, K - King, A - Ace\n");
    printf("H - Hearts, D - Diamonds, C - Clubs, S - Spades\n");
    printf("\n");
}

void pointChart() {
    printf("Point System:\n");
    printf("8 -  Straight Flush\n");
    printf("7 -  Four of a Kind\n");
    printf("6 -  Full House\n");
    printf("5 -  Flush\n");
    printf("4 -  Straight\n");
    printf("3 -  Three of a Kind\n");
    printf("2 -  Two Pair\n");
    printf("1 -  One Pair\n");
    printf("0 -  Nothing\n");
    printf("\n");
}

void pointSystem(struct card hand[5], char values[13], char suits[4]) {

    int valueCount[13] = {0};
    int suitCount[4] = {0};
    int points;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            if (hand[i].value == values[j]) {
                valueCount[j]++;
            }
        }
        for (int k = 0; k < 4; k++) {
            if (hand[i].suit == suits[k]) {
                suitCount[k]++;
            }
        }
    }

    int pairs = 0, threeKind = 0, fourKind = 0;
    for (int i = 0; i < 13; i++) {
        if (valueCount[i] == 2) pairs++;
        else if (valueCount[i] == 3) threeKind++;
        else if (valueCount[i] == 4) fourKind++;
    }

    int flush = 0;
    for (int i = 0; i < 4; i++) {
        if (suitCount[i] == 5) {
            flush = 1;
        }
    }

    int straight = 0;
    for (int i = 0; i < 9; i++) {
        if (valueCount[i] == 1 && valueCount[i + 1] == 1 && valueCount[i + 2] == 1 &&
            valueCount[i + 3] == 1 && valueCount[i + 4] == 1) {
            straight = 1;
            break;
        }
    }

    printf("\nPoker Hand Rank: ");
    if (flush && straight) {
        points = 8;
        printf("Straight Flush\n");
    }
    else if (fourKind) {
        points = 7;
        printf("Four of a Kind\n");
    }
    else if (threeKind && pairs == 1) {
        points = 6;
        printf("Full House\n");
    }
    else if (flush && !straight) {
        points = 5;
        printf("Flush\n");
    }
    else if (straight && !flush) {
        points = 4;
        printf("Straight\n");
    }
    else if (threeKind && pairs == 0) {
        points = 3;
        printf("Three of a Kind\n");
    }
    else if (pairs == 2) {
        points = 2;
        printf("Two Pair\n");
    }
    else if (pairs == 1) {
        points = 1;
        printf("One Pair\n");
    }
    else {
        printf("Nothing\n");
    }
    printf("Points: %d\n", points);

}

int main() {

    char values[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[4] = {'H', 'D', 'C', 'S'};

    struct card hand[5] = {
        {'9', 'H'},
        {'Q', 'H'},
        {'2', 'H'},
        {'2', 'S'},
        {'2', 'C'}
    };

    legendChart();
    pointChart();

    printf("5-card poker hand:\n");
    for (int i = 0; i < 5; i++) {
        printf("%c%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");

    pointSystem(hand, values, suits);

    return 0;
}
