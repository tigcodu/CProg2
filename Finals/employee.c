#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
Abc company will celebrate their 10 year anniversary and plans to recognize their employees that has served for 10 years by giving them a loyalty award

Using FILE in c, create a structure within the structures and array of structures for employee records that holds the specific info

Employee id
Employee name
Address

Each employee belongs to a department with a structure filed such as

dept name
position 
year hired 

and it should be stored within the employee structure using record.txt as the file name

Implement a function to determine the years in-service of each employee and display employees information system and display the amount of employees to be given a loyalty award

Add ways to input, here is a sample input

EmployeeID:2015-00768
Employeename: Juan dela Cruz
Employee Address: sta mesa manila
Dept name: human resource
Position: hr manager
Year hired: 2015
*/

typedef struct {
	int empID;
	char empName[80];
	char address[80];
}Personal;

typedef struct{
	Personal personal;
	char deptName[80];
	char position[80];
	int yearHired;
}Employee;

void inputData(Employee record[], int num) {
	for (int i = 0; i < num; i++) {
		printf("Employee #%d\n", i + 1);
		do {
			printf("Employee ID: ");
			if (scanf("%d", &record[i].personal.empID) == 1) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		printf("Employee Name: ");
		scanf(" %[^\n]", record[i].personal.empName);
		printf("Employee Address: ");
		scanf(" %[^\n]", record[i].personal.address);
		printf("Dept Name: ");
		scanf(" %[^\n]", record[i].deptName);
		printf("Position: ");
		scanf(" %[^\n]", record[i].position);
		do {
			printf("Year Hired: ");
			if (scanf("%d", &record[i].yearHired) == 1 && (record[i].yearHired >= 2015 && record[i].yearHired <= 2025)) {
				break;
			}
			printf("Invalid Option. Please try again.\n");
			while (getchar() != '\n');
		} while (1);
		printf("\n");
	}
}

void saveData(Employee record[], int num) {
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\record.txt", "w");
	for (int i = 0; i < num; i++) {
		fprintf(fp, "%d\t%s\t%s\t", record[i].personal.empID, record[i].personal.empName, record[i].personal.address);
		fprintf(fp, "%s\t%s\t%d\n", record[i].deptName, record[i].position, record[i].yearHired);
	}
	fclose(fp);
}

void readData(Employee dataFile[], int num) {
	FILE *fp = fopen("D:\\_Files\\Coding\\txts\\record.txt", "r");
	for (int i = 0; i < num; i++) {
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t", &dataFile[i].personal.empID, dataFile[i].personal.empName, dataFile[i].personal.address);
		fscanf(fp, "%[^\t]\t%[^\t]\t%d\n", dataFile[i].deptName, dataFile[i].position, &dataFile[i].yearHired);
	}
	fclose(fp);
}

void yearsInService(Employee dataFile[], int num, int service[]) {
	for (int i = 0; i < num; i++) {
		service[i] = 2025 - dataFile[i].yearHired;
	}
}

void displayData(Employee dataFile[], int num, int service[]) {
	printf("-----EMPLOYEES DATA-----\n");
	for (int i = 0; i < num; i++) {
		printf("Employee #%d\n", i + 1);
		printf("Employee ID: %d\n", dataFile[i].personal.empID);
		printf("Employee Name: %s\n", dataFile[i].personal.empName);
		printf("Employee Address: %s\n", dataFile[i].personal.address);
		printf("Department Name: %s\n", dataFile[i].deptName);
		printf("Position: %s\n", dataFile[i].position);
		printf("Year Hired: %d\n", dataFile[i].yearHired);
		printf("No. of years in service: %d\n", service[i]);
		printf("\n");
	}
}

void loyaltyAward(int num, int service[]) {
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (service[i] == 10) {
			count++;
		}
	}
	printf("No. of employees to be given the loyalty award: %d\n", count);
}

int main() {
	
	Employee record[MAX];
	int num;
	
	do {
		printf("Please enter how many employees to input: ");
		if (scanf("%d", &num) == 1 ||(num > 0 && num < MAX)) {
			break;
		}
		printf("Invalid Option. Please try again.\n");
		while (getchar() != '\n');
	} while (1);
	
	Employee dataFile[num];
	int service[num];
	
	inputData(record, num);
	saveData(record, num);
	readData(dataFile, num);
	yearsInService(dataFile, num, service);
	displayData(dataFile, num, service);
	loyaltyAward(num, service);
	
	return 0;
}