#include <stdio.h>

void oddArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] % 2 == 1) {
                printf("Array: arr[%d][%d] = %d\n", i, j, arr[i][j]);
            }
        }
    }
}

void oddPointer(int *p) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*p % 2 == 1) {
                printf("Pointer: i = %d, j = %d, *p = %d\n", i, j, *p);
            }
            p++;
        }
    }
}

void oddArrayAct(int (*arr)[3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(arr + i) + j) % 2 == 1){
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

    printf("\nARRAY\nThe Odd numbers are: \n");
    oddArray(arr);
    printf("\nPOINTER\nThe Odd numbers are: \n");
    oddPointer(p);
    printf("\nARRAY ACTING AS POINTER\nThe Odd numbers are: \n");
    oddArrayAct(arr);

    return 0;
}
