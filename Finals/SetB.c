#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

typedef struct {
	int itemID;
	char itemName[80];
	int partNumber;
	int quantity;
	int pricePerUnit;
}Parts;

void inputParts(Parts compParts[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		printf("Enter details for Part %d\n", i + 1);
		do {
			printf("Item ID: ");
			if (scanf("%d", &compParts[i].itemID) == 1) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		getchar();
		printf("Item Name: ");
		// fgets(compParts[i].itemName, sizeof(compParts[i].itemName), stdin);
		scanf(" %[^\n]", compParts[i].itemName);
		do {
			printf("Part Number: ");
			if (scanf("%d", &compParts[i].partNumber) == 1) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		do {
			printf("Quantity: ");
			if (scanf("%d", &compParts[i].quantity) == 1) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		do {
			printf("Price per Unit: ");
			if (scanf("%d", &compParts[i].pricePerUnit) == 1) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		printf("\n");
	}
}

void displayParts(Parts compParts[SIZE]) {
	printf("List of Computer Parts\n");
	printf("Item ID\t\tItem Name\t\tPart Number\t\tQuantity\t\tPrice Per Unit\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", compParts[i].itemID, compParts[i].itemName, compParts[i].partNumber, compParts[i].quantity, compParts[i].pricePerUnit);
	}
	printf("\n");
}

void updateParts(Parts compParts[SIZE]) {
	int ID;
	printf("Enter the Item ID: ");
	scanf("%d", &ID);
	for (int i = 0; i < SIZE; i++) {
		if (ID == compParts[i].itemID) {
			printf("Update the details of ID %d\n", ID);
			getchar();
			printf("Item Name: ");
			scanf(" %[^\n]", compParts[i].itemName);
			printf("Part Number: ");
			scanf("%d", &compParts[i].partNumber);
			printf("Quantity: ");
			scanf("%d", &compParts[i].quantity);
			printf("Price per Unit: ");
			scanf("%d", &compParts[i].pricePerUnit);
			printf("All parts are updated.\n");
			printf("\n");
			return;
		}
	}
	printf("Item ID not found.\n\n");
}

void findLowest(Parts compParts[SIZE]) {
	int low = 0;
	for (int i = 1; i < SIZE; i++) {
		if (compParts[i].pricePerUnit < compParts[low].pricePerUnit) {
			low = i;
		}
	}
	printf("Lowest Price per Unit: %d\n", compParts[low].pricePerUnit);
	printf("Item ID: %d\n", compParts[low].itemID);
	printf("Item Name: %s\n", compParts[low].itemName);
	printf("Part Number: %d\n", compParts[low].partNumber);
	printf("Quantity: %d\n", compParts[low].quantity);
	printf("\n");
}

void writeFile(Parts compParts[SIZE]) {
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\inventoryB.txt", "w");
	for (int i = 0; i < SIZE; i++) {
		fprintf(fp, "%d\t%s\t%d\t%d\t%d\n", compParts[i].itemID, compParts[i].itemName, compParts[i].partNumber, compParts[i].quantity, compParts[i].pricePerUnit);
	}
	fclose(fp);
}

void readFile() {
	Parts data[SIZE];
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\inventoryB.txt", "r");
	printf("-----DATA-----\n");
	for (int i = 0; i < SIZE; i++) {
		fscanf(fp, "%d\t%[^\t]\t%d\t%d\t%d\n", &data[i].itemID, data[i].itemName, &data[i].partNumber, &data[i].quantity, &data[i].pricePerUnit);
		printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", data[i].itemID, data[i].itemName, data[i].partNumber, data[i].quantity, data[i].pricePerUnit);
	}
	printf("\n");
	fclose(fp);
}

int main() {
	
	Parts compParts[SIZE];
	
	inputParts(compParts);
	
	int option;

	do {
		printf("-----MENU-----\n");
		printf("1. Display\n2. Update\n3. Find the Lowest Price\n4. Read from File\n5. Exit\n");
		do {
			printf("Choose an option: ");
			if (scanf("%d", &option) != 1 || option > 5 || option < 1) {
				printf("Invalid Option. Please try again.\n");
				while (getchar() != '\n');
			}
			else {
				printf("\n");
				break;
			}
		} while (1);
		
		switch (option) {
			case 1:
				displayParts(compParts);
				break;
			case 2:
				updateParts(compParts);
				break;
			case 3:
				findLowest(compParts);
				break;
			case 4:
				writeFile(compParts);
				readFile();
				break;
			case 5:
				printf("Exiting the program.\n");
				exit(0);
		}
	} while(1);
	
	return 0;
}