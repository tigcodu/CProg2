#include <stdio.h>

int main(){

    int a[5] = {2, 4, 6, 8, 10};
    int *p;

    p = a;

    printf("%d\n", a[0]);
    printf("%d\n", *p);
    printf("%d\n", *a);

    p = &a[2];

    printf("%d\n", a[2]);
    printf("%d\n", *p);
    printf("%d\n", *(a + 2));

    --p;

    printf("%x\n", p);
    printf("%x\n", &a[0]);
    printf("%d\n", *p);

    p = p + 3;

    printf("%x\n", &a[4]);
    printf("%x\n", p);

    /*
    2
    2
    2
    6
    6
    6
    61ff0c
    61ff08
    4
    61ff18
    61ff18
    */

return 0;
}