#include <stdio.h>
#include <ctype.h>

struct card {
    char value;
    char suit;
} hand[5];

void legendChart() {
    printf("Legend:\n");
    printf("T - Ten, J - Jack, Q - Queen, K - King, A - Ace\n");
    printf("H - Hearts, D - Diamonds, C - Clubs, S - Spades\n\n");
    printf("Point System:\n");
    printf("8 -  Straight Flush\n");
    printf("7 -  Four of a Kind\n");
    printf("6 -  Full House\n");
    printf("5 -  Flush\n");
    printf("4 -  Straight\n");
    printf("3 -  Three of a Kind\n");
    printf("2 -  Two Pair\n");
    printf("1 -  One Pair\n");
    printf("0 -  Nothing\n\n");
}

void value(struct card hand[5], int valueCount[13], char values[13]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            if (hand[i].value == values[j]) {
                valueCount[j]++;
                break;
            }
        }
    }
}

void checkKinds(int valueCount[13], int *pairs, int *threeKind, int *fourKind) {
    *pairs = 0;
    *threeKind = 0;
    *fourKind = 0;

    for (int i = 0; i < 13; i++) {
        if (valueCount[i] == 2) (*pairs)++;
        else if (valueCount[i] == 3) (*threeKind)++;
        else if (valueCount[i] == 4) (*fourKind)++;
    }
}

int isFlush(struct card hand[5], char suits[4]) {
    int suitCount[4] = {0};
    for (int k = 0; k < 4; k++) {
            if (hand[k].suit == suits[k]) suitCount[k]++;
            if (suitCount[k] == 5) return 1;
        }
    return 0;
}

int isStraight(int valueCount[13]) {
    for (int i = 0; i < 9; i++) {
        if (valueCount[i] == 1 && valueCount[i + 1] == 1 && valueCount[i + 2] == 1 &&
            valueCount[i + 3] == 1 && valueCount[i + 4] == 1) {
            return 1;
        }
    }
    return 0;
}

void pointSystem(int flush, int straight, int fourKind, int threeKind, int pairs) {
    int points;

    printf("\nPoker Hand Rank: ");
    if (flush && straight) {
        points = 8;
        printf("Straight Flush\n");
    } else if (fourKind) {
        points = 7;
        printf("Four of a Kind\n");
    } else if (threeKind && pairs == 1) {
        points = 6;
        printf("Full House\n");
    } else if (flush) {
        points = 5;
        printf("Flush\n");
    } else if (straight) {
        points = 4;
        printf("Straight\n");
    } else if (threeKind) {
        points = 3;
        printf("Three of a Kind\n");
    } else if (pairs == 2) {
        points = 2;
        printf("Two Pair\n");
    } else if (pairs == 1) {
        points = 1;
        printf("One Pair\n");
    } else {
        points = 0;
        printf("Nothing\n");
    }
    printf("Points: %d\n", points);
}

int main() {
    char values[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[4] = {'H', 'D', 'C', 'S'};

    legendChart();

    printf("Enter 5 poker-hand cards (Value = 2-9, T, J, Q, K, A | Suit = H, D, C, S):\n");

    int i = 0;
    while (i < 5) {
        char value, suit;
        int validValue = 0, validSuit = 0, duplicate = 0;

        printf("Card %d: ", i + 1);
        scanf(" %c%c", &value, &suit);

        value = toupper(value);
        suit = toupper(suit);

        for (int j = 0; j < 13; j++) {
            if (values[j] == value) {
                validValue = 1;
                break;
            }
        }

        for (int k = 0; k < 4; k++) {
            if (suits[k] == suit) {
                validSuit = 1;
                break;
            }
        }

        for (int l = 0; l < i; l++) {
            if (hand[l].value == value && hand[l].suit == suit) {
                duplicate = 1;
                break;
            }
        }

        if (!validValue) {
            printf("Invalid card value. Please enter 2-9, T, J, Q, K, or A.\n");
            continue;
        }
        if (!validSuit) {
            printf("Invalid card suit. Please enter H, D, C, or S.\n");
            continue;
        }
        if (duplicate) {
            printf("Duplicate card detected. Please enter a different card.\n");
            continue;
        }

        hand[i].value = value;
        hand[i].suit = suit;
        i++;
    }

    printf("\nPoker Hand:\n");
    for (int i = 0; i < 5; i++) {
        printf("%c%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");

    int valueCount[13] = {0};
    value(hand, valueCount, values);
    int pairs, threeKind, fourKind;
    checkKinds(valueCount, &pairs, &threeKind, &fourKind);
    int flush = isFlush(hand, suits);
    int straight = isStraight(valueCount);
    pointSystem(flush, straight, fourKind, threeKind, pairs);

    return 0;
}
