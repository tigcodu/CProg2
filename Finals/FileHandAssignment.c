#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Product {
    char code[3];
    char name[80];
    int quantity;
};

void saveProduct(struct Product products[], int num) {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Inventory.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.");
        return;
    }
    for (int i = 0; i < num; i++) {
        fprintf(fp, "%s\t%s\t%d\n", products[i].code, products[i].name, products[i].quantity);
    }
    fclose(fp);
}

void updateQuantity(struct Product products[], int i) {
    char quan;
    int temp;
    while (1) {
        printf("Enter quantity option (A - Add, S - Subtract): ");
        scanf(" %c", &quan);
        if (quan == 'A' || quan == 'a') {
            do {
                printf("Enter amount: ");
                if (scanf("%d", &temp) == 1 && temp > 0) {
                    products[i].quantity += temp;
                    return;
                }
                printf("Invalid output. Please enter a positive integer.\n");
                while (getchar() != '\n');
            } while (1);  
        }
        else if (quan == 'S' || quan == 's') {
            do {
                printf("Enter amount: ");
                if (scanf("%d", &temp) == 1 && temp > 0) {
                    products[i].quantity -= temp;
                    return;
                }
                printf("Invalid output. Please enter a positive integer.\n");
                while (getchar() != '\n');
            } while (1);
        } 
        else {
            printf("Invalid input. Please enter 'A' or 'S'.\n");
        }
    }
}

void updateProduct(struct Product products[], int num) {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Inventory.txt", "w");
    char code[3];
    int found = 0;
    if (fp == NULL) {
        printf("Error opening file.");
        return;
    }
    do {
        printf("Product code: ");
        scanf("%2s", code);
        for (int i = 0; i < num; i++) {
            if (strcmp(code, products[i].code) == 0) {
                found = 1;
                printf("Update Code: ");
                scanf("%2s", products[i].code);
                updateQuantity(products, i);
            }
            fprintf(fp, "%s\t%s\t%d\n", products[i].code, products[i].name, products[i].quantity);
            return;
        }
        printf("Product not found. Please try again.\n");
    } while (!found);
    fclose(fp);
}

void displayProduct(struct Product products[], int num) {
    FILE *fp = fopen("D:\\_Files\\Coding\\txts\\Inventory.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.");
        return;
    }
    printf("Product Code\tProduct Name\tQuantity\n");
    for (int i = 0; i < num; i++) {
        fscanf(fp, "%2s %79s %d", products[i].code, products[i].name, &products[i].quantity);
        printf("%s\t\t%s\t\t%d\n", products[i].code, products[i].name, products[i].quantity);
    }
    fclose(fp);
}

int main() {

    int number, j;
    char upd;
    struct Product products[MAX];

    do {
        printf("Please enter how many products: ");
        if (scanf("%d", &number) == 1 && number > 0) {
            break;
        }
        printf("Invalid output. Please enter a positive integer.\n");
        while (getchar() != '\n');
    } while (1);  

    for (int i = 0; i < number; i++) {
        printf("Product code: ");
        scanf(" %[^\n]", products[i].code);
        printf("Product name: ");
        scanf(" %[^\n]", products[i].name);
        do {
            printf("Quantity: ");
            if (scanf("%d", &products[i].quantity) == 1 && products[i].quantity > 0) {
                break;
            }
            printf("Invalid output. Please enter a positive integer.\n");
            while (getchar() != '\n');
        } while (1);  
    }

    saveProduct(products, number);
    while (1) {
        printf("Do you want to update the quantity of a product? (Y or N): ");
        scanf(" %c", &upd);
        if (upd == 'Y' || upd == 'y') {
            updateProduct(products, number);
            break;
        }
        else if (upd == 'N' || upd == 'n') {
            break;
        } 
        else {
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
        }
    }
    while (1) {
        printf("Update more? (Y or N): ");
        scanf(" %c", &upd);
        if (upd == 'Y' || upd == 'y') {
            updateProduct(products, number);
        }
        else if (upd == 'N' || upd == 'n') {
            break;
        } 
        else {
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
        }
    }
    displayProduct(products, number);

    return 0;
}