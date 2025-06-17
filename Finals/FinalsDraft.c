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
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Shoe.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct Shoe *newStock = (struct Shoe *)malloc(sizeof(struct Shoe));
    newStock->stockNumber = inventoryCount;

    int already;
    printf("Stock number: %d\n", newStock->stockNumber); 
    do {
        printf("Enter the Style number (Only Between 0-50): ");
        if (scanf("%d", &newStock->styleNumber) != 1 || newStock->styleNumber < 0 || newStock->styleNumber > 50) {
            printf("Invalid output. Please enter a number between 0 and 50.\n");
            while (getchar() != '\n');
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
        if (already == 0) {
            break;
        }
    } while (1);

    printf("Enter the no. of pairs in each size.\n");
    for (int i = 0; i <= 11; i++) {
        do {
            printf("Size %d: ", i + 3);
            if (scanf("%d", &newStock->size[i]) == 1 && newStock->size[i] >= 0) {
                break;
            }
            printf("Invalid output. Please enter a positive integer.\n");
            while (getchar() != '\n');
        } while (1);
    }

    do {
        printf("Enter the price: ");
        if (scanf("%f", &newStock->price) == 1 && newStock->price >= 0) {
            break;
        }
        printf("Invalid output. Please enter a positive integer.\n");
        while (getchar() != '\n');
    } while (1);

    printf("Record added.\n\n");
    inventory[inventoryCount++] = newStock;

    fprintf(fp, "%d %d ", newStock->stockNumber, newStock->styleNumber);
    for (int i = 0; i < 12; i++) {
        fprintf(fp, "%d ", newStock->size[i]);
    }
    fprintf(fp, "%.2f\n", newStock->price);
    fclose(fp);
}

void displayRecord() {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Shoe.txt", "r");
    struct Shoe temp;

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int search, num;
    do {
        printf("Search by (1 - Stock No., 2 - Style No.): ");
        if (scanf("%d", &search) != 1 || search < 1 || search > 2) {
            printf("Invalid output. Please enter 1 or 2.\n");
            while (getchar() != '\n');
        }
    } while (search < 1 || search > 2);

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

    while (fscanf(fp, "%d %d", &temp.stockNumber, &temp.styleNumber) != EOF) {
        for (int i = 0; i < 12; i++) {
            fscanf(fp, "%d", &temp.size[i]);
        }
        fscanf(fp, "%f", &temp.price);

        if (temp.stockNumber == num || temp.styleNumber == num) {
            printf("---LIST---\n"); 
            printf("Stock Number: %d\n", temp.stockNumber);
            printf("Style Number: %d\n", temp.styleNumber);
            printf("No. of pairs in each size:\n");
            for (int j = 0; j < 12; j++) {
                printf("Size %d: %d\n", j + 3, temp.size[j]);
            }
            printf("Price: P%.2f\n", temp.price);
            printf("\n");
            fclose(fp);
            return;
        }
    }
    printf("Record not found.\n");
    fclose(fp);
}

void changePrice() {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Shoe.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int priceChange;

    do {
        printf("Enter the stock number: ");
        if (scanf("%d", &priceChange) != 1 || priceChange < 0 || priceChange >= inventoryCount) {
            printf("Invalid stock number. Please enter a valid number.\n");
            while (getchar() != '\n');
        }
    } while (priceChange < 0 || priceChange >= inventoryCount);

    struct Shoe temp;

    for (int i = 0; i < inventoryCount; i++) {
        fscanf(fp, "%d %d", &temp.stockNumber, &temp.styleNumber);
        for (int j = 0; j < 12; j++) {
            fscanf(fp, "%d", &temp.size[j]);
        }
        fscanf(fp, "%f", &temp.price);

        if (temp.stockNumber == priceChange) {
            printf("Current price: P%.2f\n", temp.price);
            printf("Enter the new price: ");
            if (scanf("%f", &temp.price) != 1 || temp.price < 0) {
                printf("Invalid price. Please enter a positive number.\n");
                fclose(fp);
                return;
            }
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fprintf(fp, "%d %d ", temp.stockNumber, temp.styleNumber);
            for (int j = 0; j < 12; j++) {
                fprintf(fp, "%d ", temp.size[j]);
            }
            fprintf(fp, "%.2f\n", temp.price);
            printf("Price changed successfully.\n\n");
            fclose(fp);
            return;
        }
    }
}

void changeNumber() {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Shoe.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int stockChange, shoeChange, option;
    do {
        printf("Enter the stock number: ");
        if (scanf("%d", &stockChange) != 1 || stockChange < 0 || stockChange >= inventoryCount) {
            printf("Invalid stock number. Please enter a valid number.\n");
            while (getchar() != '\n');
        }
    } while (stockChange < 0 || stockChange >= inventoryCount);

    struct Shoe temp;

    for (int i = 0; i < inventoryCount; i++) {
        fscanf(fp, "%d %d", &temp.stockNumber, &temp.styleNumber);
        for (int j = 0; j < 12; j++) {
            fscanf(fp, "%d", &temp.size[j]);
        }
        fscanf(fp, "%f", &temp.price);
    }

    do {
        do {
            printf("Enter the shoe size (3-14) to change stock: ");
            if (scanf("%d", &shoeChange) != 1 || shoeChange < 3 || shoeChange > 14) {
                printf("Invalid size. Please enter a number between 3 and 14.\n");
                while (getchar() != '\n');
            }
        } while (shoeChange < 3 || shoeChange > 14);
        printf("Enter the no. of new stocks: ");
        if (scanf("%d", &temp.size[shoeChange - 3]) != 1 || temp.size[shoeChange - 3] < 0) {
            printf("Invalid output. Please enter a positive integer.\n");
            while (getchar() != '\n');
        } else {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fprintf(fp, "%d %d ", temp.stockNumber, temp.styleNumber);
            for (int j = 0; j < 12; j++) {
                fprintf(fp, "%d ", temp.size[j]);
            }
            fprintf(fp, "%.2f\n", temp.price);
            printf("Stock changed successfully.\n\n");
            fclose(fp);
            return;
        }
    } while (!option);
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

        switch (choice) {
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
                printf("Thank you for using the program\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}