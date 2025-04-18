#include <stdio.h>

void evenArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] % 2 == 0) {
                printf("Array: arr[%d][%d] = %d\n", i, j, arr[i][j]);
            }
        }
    }
}

void evenPointer(int *p) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*p % 2 == 0) {
                printf("Pointer: i = %d, j = %d, *p = %d\n", i, j, *p);
            }
            p++;
        }
    }
}

void evenArrayAct(int (*arr)[3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(arr + i) + j) % 2 == 0){
                printf("Array acting as pointer: *(*(arr + %d) + %d) = %d\n", i, j, *(*(arr + i) + j));
            }
        }
    }
}

int main(){

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

    printf("\nARRAY\nThe Even numbers are: \n");
    evenArray(arr);
    printf("\nPOINTER\nThe Even numbers are: \n");
    evenPointer(p);
    printf("\nARRAY ACTING AS POINTER\nThe Even numbers are: \n");
    evenArrayAct(arr);

    return 0;
}