#include <stdio.h>

int factors(int num) {
    int sum = 0;
    printf("Factors are: ");
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
        
    }
    return sum;
}

float halfNumber(int num) {
    return num / 2.0;
}

void isDwarf(int num, int sum, int half) {
    if (sum > half) {
        printf("%d is DWARF\n", num);
    }
    else {
        printf("%d is NOT DWARF\n", num);
    }
}

int main() {

    printf("DWARF (Array Acting As A Pointer Version)\n\n");
    
    int arr[5] = {12, 23, 34, 45, 56};
    for (int i = 0; i < 5; i++) {
        printf("Number: %d\n", *(arr + i));
        int sum = factors(*(arr + i));
        printf("\nSum of its factors: %d\n", sum);
        float half = halfNumber(*(arr + i));
        printf("Half of the number: %.1f\n", half);
        isDwarf(*(arr + i), sum, half);
        
        printf("\n");
    }

    return 0;
}