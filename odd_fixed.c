#include <stdio.h>

void oddArray(int arr[]) {
for (int i = 0; i < 5; i++) {
    if (arr[i] % 2 == 1) {
        printf("Array: arr[%d] = %d\n", i, arr[i]);
    }
    }
}

void oddPointer(int *p) {
for (int i = 0; i < 5; i++) {
    if (*p % 2 == 1) {
        printf("Pointer: i = %d, *p = %d\n", i, *p);
        }
        p++;
    }
}

void oddArrayAct(int *arr){
for (int i=0; i < 5; i++){
    if (*(arr + i) % 2 == 1){
        printf("Array acting as pointer: *(arr + %d) = %d\n", i, *(arr + i));
        }
    }
}

int main(){

    int arr[5] = {12, 23, 34, 45, 56};
    int *p;
    p = arr;

    printf("The elements of array are: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    printf("\nARRAY\nThe Odd numbers are: \n");
    oddArray(arr);
    printf("\nPOINTER\nThe Odd numbers are: \n");
    oddPointer(p);
    printf("\nARRAY ACTING AS POINTER\nThe Odd numbers are: \n");
    oddArrayAct(arr);

    return 0;
}