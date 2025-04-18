#include <stdio.h>

void sumArray(int arr[3][3]) {
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] % 2 == 0) {
                sumEven += arr[i][j]; 
            }
            else {
                sumOdd += arr[i][j];
            }
        }
    }
    printf("\nArray Form (arr[i][j]): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}


void sumPointer(int *p) {
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*p % 2 == 0) {
                sumEven += *p; 
            }
            else {
                sumOdd += *p;
            }
            p++;
        }
    }
    printf("\nPointer Form (*p): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}

void sumAct(int (*arr)[3]) {
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(arr + i) + j) % 2 == 0) {
                sumEven += *(*(arr + i) + j); 
            }
            else {
                sumOdd += *(*(arr + i) + j);
            }
        }
    }
    printf("\nArray Acting as a Pointer Form (*(*(arr + i) + j): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}

int main() {

    int arr[3][3] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *p;
    p = (int*)arr;

    printf("The elements of array are: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    sumArray(arr);
    sumPointer(p);
    sumAct(arr);

    return 0;
}