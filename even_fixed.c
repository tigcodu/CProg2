#include <stdio.h>

void evenArray(int arr[]) {
for (int i = 0; i < 5; i++) {
    if (arr[i] % 2 == 0) {
        printf("Array: arr[%d] = %d\n", i, arr[i]);
    }
    }
}

void evenPointer(int *p) {
for (int i = 0; i < 5; i++) {
    if (*p % 2 == 0) {
        printf("Pointer: i = %d, *p = %d\n", i, *p);
        }
        p++;
    }
}

void evenArrayAct(int *arr){
for (int i=0; i < 5; i++){
    if (*(arr + i) % 2 == 0){
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

    printf("\nARRAY\nThe Even numbers are: \n");
    evenArray(arr);
    printf("\nPOINTER\nThe Even numbers are: \n");
    evenPointer(p);
    printf("\nARRAY ACTING AS POINTER\nThe Even numbers are: \n");
    evenArrayAct(arr);

    return 0;
}