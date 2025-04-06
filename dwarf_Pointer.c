#include <stdio.h>

int factors(int *p) {
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

float halfNumber(int *p) {
    return *p / 2.0;
}

void isDwarf(int *p, int sum, int half) {
    if (sum > half) {
        printf("%d is DWARF\n", *p);
    }
    else {
        printf("%d is NOT DWARF\n", *p);
    }
}

int main() {

    printf("DWARF (Pointer Version)\n\n");
    
    int arr[5] = {12, 23, 34, 45, 56};
    int *p;
    p = arr;
    for (int i = 0; i < 5; i++) {
        printf("Number: %d\n", *p);
        int sum = factors(p);
        printf("\nSum of its factors: %d\n", sum);
        float half = halfNumber(p);
        printf("Half of the number: %.1f\n", half);
        isDwarf(p, sum, half);
        p++;
        
        printf("\n");
    }

    return 0;
}