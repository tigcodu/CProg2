#include <stdio.h>

struct Card {
    int value;
    char suit;
};

// Common evaluator
void evaluate(int values[], char suits[], const char *label) {
    int valueCount[15] = {0};
    int suitCount[4] = {0};
    int i, isFlush = 0, isStraight = 1;

    for (i = 0; i < 5; i++) {
        valueCount[values[i]]++;
        if (suits[i] == 'H') suitCount[0]++;
        else if (suits[i] == 'D') suitCount[1]++;
        else if (suits[i] == 'S') suitCount[2]++;
        else if (suits[i] == 'C') suitCount[3]++;
    }

    int start = 0;
    for (i = 2; i <= 10; i++) {
        if (valueCount[i] && valueCount[i+1] && valueCount[i+2] &&
            valueCount[i+3] && valueCount[i+4]) {
            start = i;
            break;
        }
    }
    isStraight = start != 0;
    isFlush = (suitCount[0]==5 || suitCount[1]==5 || suitCount[2]==5 || suitCount[3]==5);

    int pairs = 0, three = 0, four = 0;
    for (i = 2; i <= 14; i++) {
        if (valueCount[i] == 2) pairs++;
        if (valueCount[i] == 3) three++;
        if (valueCount[i] == 4) four++;
    }

    printf("%s\nCategory: ", label);
    if (isStraight && isFlush)
        printf("Straight Flush\n\n");
    else if (four)
        printf("Four of a Kind\n\n");
    else if (three && pairs)
        printf("Full House\n\n");
    else if (isFlush)
        printf("Flush\n\n");
    else if (isStraight)
        printf("Straight\n\n");
    else if (three)
        printf("Three of a Kind\n\n");
    else if (pairs == 2)
        printf("Two Pairs\n\n");
    else if (pairs == 1)
        printf("One Pair\n\n");
    else
        printf("Nothing\n\n");
}

// Function 1: Passing individual members
void indiv_members(int v1, char s1, int v2, char s2, int v3, char s3, int v4, char s4, int v5, char s5) {
    int values[5] = {v1, v2, v3, v4, v5};
    char suits[5] = {s1, s2, s3, s4, s5};
    evaluate(values, suits, "Case 1: By Individual Members");
}

// Function 2: Passing whole structures
void whole_struct(struct Card c1, struct Card c2, struct Card c3, struct Card c4, struct Card c5) {
    int values[5] = {c1.value, c2.value, c3.value, c4.value, c5.value};
    char suits[5] = {c1.suit, c2.suit, c3.suit, c4.suit, c5.suit};
    evaluate(values, suits, "Case 2: By Whole Structures");
}

// Function 3: Passing structure pointers
void struct_pointer(struct Card *c1, struct Card *c2, struct Card *c3, struct Card *c4, struct Card *c5) {
    int values[5] = {c1->value, c2->value, c3->value, c4->value, c5->value};
    char suits[5] = {c1->suit, c2->suit, c3->suit, c4->suit, c5->suit};
    evaluate(values, suits, "Case 3: By Structure Pointers");
}

// Function 4: Passing array of structures
void array_structure(struct Card hand[]) {
    int values[5], i;
    char suits[5];
    for (i = 0; i < 5; i++) {
        values[i] = hand[i].value;
        suits[i] = hand[i].suit;
    }
    evaluate(values, suits, "Case 4: By Array of Structures");
}

int main() {
    struct Card hand[5];
    int i, again;

    do {
        again = 0;
        printf("Enter 5 cards:\n");
        for (i = 0; i < 5; i++) {
            printf("Card %d value (2 to 14, Jack=11, Queen=12, King=13, Ace=14): ", i + 1);
            scanf("%d", &hand[i].value);
            while (hand[i].value < 2 || hand[i].value > 14) {
                printf("Invalid value. Enter a value between 2 and 14: ");
                scanf("%d", &hand[i].value);
            }
            printf("Card %d suit (H/D/S/C): ", i + 1);
            scanf(" %c", &hand[i].suit);
            while (hand[i].suit != 'H' && hand[i].suit != 'D' && hand[i].suit != 'S' && hand[i].suit != 'C') {
                printf("Invalid suit. Enter H, D, S, or C: ");
                scanf(" %c", &hand[i].suit);
            }
        }

        printf("\nPoker Hand:\n");
        for (i = 0; i < 5; i++) {
            printf("%d %c\n", hand[i].value, hand[i].suit);
        }
        printf("\n");

        // Run all four evaluations
        indiv_members(hand[0].value, hand[0].suit,hand[1].value, hand[1].suit,hand[2].value, hand[2].suit,hand[3].value, hand[3].suit,hand[4].value, hand[4].suit);
        whole_struct(hand[0], hand[1], hand[2], hand[3], hand[4]);
        struct_pointer(&hand[0], &hand[1], &hand[2], &hand[3], &hand[4]);
        array_structure(hand);
        printf("Would you like to try again(Yes=1, No=0)? ");
        scanf("%d", &again);
    } while (again == 1);
    
    printf("Thank you for using our program");
    return 0;
}
