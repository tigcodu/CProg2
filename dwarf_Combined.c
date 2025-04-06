#include <stdio.h>

// Array
int factorsArray(int arr[], int idx) {
    int sum = 0;
    printf("Factors are: ");
    for (int i = 1; i < arr[idx]; i++) {
        if (arr[idx] % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    return sum;
}

void isDwarfArray(int arr[], int idx, int sum, int half) {
    if (sum > half) {
        printf("%d is DWARF\n", arr[idx]);
    }
    else {
        printf("%d is NOT DWARF\n", arr[idx]);
    }
}

// Pointer
int factorsPointer(int *p) {
    int sum = 0;
    printf("Factors are: ");
    for (int i = 1; i < *p; i++) {
        if (*p % i == 0) {
            printf("%d ", i);
            sum += i;
        } 
    }
    return sum;
}

void isDwarfPointer(int *p, int sum, int half) {
    if (sum > half) {
        printf("%d is DWARF\n", *p);
    }
    else {
        printf("%d is NOT DWARF\n", *p);
    }
}

// Array Act as Pointer
int factorsArrayAct(int *arr, int idx) {
    int sum = 0;
    printf("Factors are: ");
    for (int i = 1; i < *(arr + idx); i++) {
        if (*(arr + idx) % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    return sum;
}

void isDwarfArrayAct(int *arr, int idx, int sum, int half) {
    if (sum > half) {
        printf("%d is DWARF\n", *(arr + idx));
    }
    else {
        printf("%d is NOT DWARF\n", *(arr + idx));
    }
}

int main() {

    int arr[] = {12, 23, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("DWARF\n\nThe elements of the array are: \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

    printf("ARRAY Version\n\n");
    for (int i = 0; i < size; i++) {
        printf("Number: %d\n", arr[i]);
        int sum = factorsArray(arr, i);
        printf("\nSum of its factors: %d\n", sum);
        float half = arr[i] / 2.0;
        printf("Half of the number: %.1f\n", half);
        isDwarfArray(arr, i, sum, half);
        printf("\n");
    }

    printf("POINTER Version\n\n");
    int *p;
    p = arr;
    for (int i = 0; i < size; i++) {
        printf("Number: %d\n", *p);
        int sum = factorsPointer(p);
        printf("\nSum of its factors: %d\n", sum);
        float half = *p / 2.0;
        printf("Half of the number: %.1f\n", half);
        isDwarfPointer(p, sum, half);
        p++;
        printf("\n");
    }

    printf("ARRAY ACT AS POINTER Version\n\n");
    for (int i = 0; i < size; i++) {
        printf("Number: %d\n", *(arr + i));
        int sum = factorsArray(arr, i);
        printf("\nSum of its factors: %d\n", sum);
        float half = *(arr + i) / 2.0;
        printf("Half of the number: %.1f\n", half);
        isDwarfArray(arr, i, sum, half);
        printf("\n");
    }

    return 0;
}