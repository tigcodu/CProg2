#include <stdio.h>
#include <stdlib.h>

struct Shoe {
    int stockNumber;
    int styleNumber;
    int size[12];
    float price;
};

struct Shoe *inventory[51];
int inventoryCount = 0;

void addRecord() {
    struct Shoe *newStock = (struct Shoe *)malloc(sizeof(struct Shoe));
    newStock->stockNumber = inventoryCount;
    
    int already;
    printf("Stock number: %d\n", newStock->stockNumber); 
    do {
        printf("Enter the Style number (Only Between 0-50): ");
        scanf("%d", &newStock->styleNumber);
        if (newStock->styleNumber > 50 || newStock->styleNumber < 0) {
            printf("Invalid number.\n");
        }
        for (int i = 0; i < 51; i++) {
            if (inventory[i] != NULL 
            && inventory[i]->styleNumber == newStock->styleNumber) {
                already = 1;
                printf("Style number already exists.\n");
                break;
            } else {
                already = 0;
            }
        }
    } while (newStock->styleNumber > 50 || newStock->styleNumber < 0 || already == 1);
    
    printf("Enter the no. of pairs in each size.\n");
    for (int i = 0; i <= 11; i++) {
        printf("Size %d: ", i + 3);
        scanf("%d", &newStock->size[i]);
    }
    
    printf("Enter the price: ");
    scanf("%f", &newStock->price);
    
    printf("Record added.\n\n");
    inventory[inventoryCount++] = newStock;
}

void displayRecord() {
    int search, num;
    
    do {
        printf("Search by (1 - Stock No., 2 - Style No.): ");
        scanf("%d", &search);
        if (search > 2 || search < 1) {
            printf("Invalid number.\n");
        }
    } while (search > 2 || search < 1);
    
    switch (search) { 
        case 1: 
            printf("Enter a stock number: ");
            scanf("%d", &num);
            break;
        case 2: 
            printf("Enter a style number: ");
            scanf("%d", &num);
            break;
    }

    for (int i = 0; i < 51; i++) {
        if (inventory[i] && (inventory[i]->stockNumber == num || 
        inventory[i]->styleNumber == num)) {
            printf("---LIST---\n"); 
            printf("Stock Number: %d\n", inventory[i]->stockNumber);
            printf("Style Number: %d\n", inventory[i]->styleNumber);
            printf("No. of pairs in each size:\n");
            for (int j = 0; j < 12; j++) {
                printf("Size %d: %d\n", j + 3, inventory[i]->size[j]);
            }
            printf("Price: P%.2f\n", inventory[i]->price);
            printf("\n");
            return;
        }
    }

    printf("Data not found.\n\n");
}

void changePrice() {
    int priceChange;

    do {
        printf("Enter the stock number: ");
        scanf("%d", &priceChange);
        if (priceChange >= inventoryCount) {
            printf("Invalid stock number.\n");
        }
    } while (priceChange >= inventoryCount);

    printf("Enter the new price: ");
    scanf("%f", &inventory[priceChange]->price);
    printf("Price changed successfully.\n\n");
}

void changeNumber() {
    int stockChange, shoeChange, option;

    do {
        printf("Enter the stock number: ");
        scanf("%d", &stockChange);
        if (stockChange >= inventoryCount) {
            printf("Invalid stock number.\n");
        }
    } while (stockChange >= inventoryCount);

    do {
        do {
            printf("Enter the shoe size to change stocks (3-14): ");
            scanf("%d", &shoeChange);
            if (shoeChange < 3 || shoeChange > 14) {
                printf("Invalid shoe size.\n");
            }
        } while (shoeChange < 3 || shoeChange > 14);
        printf("Enter the no. of new stocks: ");
        scanf("%d", &inventory[stockChange]->size[shoeChange - 3]);
        printf("Do you want to change for the other sizes? (1 - Yes, 0 - No): ");
        scanf("%d", &option);
    } while (option != 0);

    printf("Stocks changed successfully.\n\n");
}

int main() {

    int choice, num;
    
    while (1) {     
        printf("---SHOE STOCKS---\n");   
        printf("1. Enter a new record\n");
        printf("2. Display a record\n");
        printf("3. Change the price of the stock item\n");
        printf("4. Change the shoe stocks on hand\n");
        printf("5. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            changePrice();
             break;
        case 4:
            changeNumber();
            break;
        case 5:
            printf("Thank you for using the shoe stocks program.\n");
            return 0; 
        default:
            printf("Invalid Input.\n\n");
            break;
        }
    }
    return 0;
}