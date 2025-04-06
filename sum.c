#include <stdio.h>

void sumarray(int arr[]){ 
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 5; i++){
        if (arr[i] % 2 == 1){
            sumOdd += arr[i];
        }
        else {
            sumEven += arr[i];
        }
    }
    printf("\nArray Form (arr[i]): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}

void sumPointer(int *p){
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < 5; i++){
        if (*p % 2 == 1){
            sumOdd += *p;
        }
        else {
            sumEven += *p;
        }
        p++;
    }
    printf("\nPointer Form (*p): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}

void sumAct(int *arr){
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i <5 ; i++){
        if (*(arr + i) % 2 == 1){
            sumOdd += *(arr + i);
        }
        else {
            sumEven += *(arr + i);
        }
    }
    printf("\nArray Acting as a Pointer Form (*(arr + i)): \n");
    printf("Sum of Odd numbers: %d\n", sumOdd);
    printf("Sum of Even numbers: %d\n", sumEven);
}

int main(){

    int arr[5] = {12, 23, 34, 45, 56};
    int *p;
    p = arr;

    printf("The elements of array are: \n");
    for (int i = 0; i<5; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n");

    sumarray(arr);
    sumPointer(p);
    sumAct(arr);

    return 0;
}