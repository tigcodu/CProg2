#include <stdio.h>

int main() {

    int a, b = 10;
    int *pa, *pb = &b;
    *pb = b + 15;
    a = *pb + 5;
    pa = pb;
    *pa = a + b;
    
    printf("%d %d %d %d", pa, pb, a, b);
    printf("\n");

    int x[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int temp = *(x + 8);
    printf("%d", temp);
    printf("\n");

    int y[10] = {2, 5, 3, 6, 4, 7, 1, 8, 10, 9}, *p;
    p = y;

    printf("%d", *(p + 2));

    return 0;
}