#include <stdio.h>

int main(){

// Example 1

int vvvar1 = 11; // define and
char vvvar2 = 'A'; // initialize
float vvvar3 = 33.34; // three variable
printf("Address of Var1 = %x\n", &vvvar1);
printf("Address of Var2 = %x\n", &vvvar2);
printf("Address of Var3 = %x\n", &vvvar3);

/* Ex. 1 Result:
Address of Var1 = 61ff10
Address of Var2 = 61ff0f
Address of Var3 = 61ff08
*/

printf("\n");

// Example 2

int *pptr;
int vvar1 = 11;
int vvar2 = 22;

printf("& ptr = %x\n", &pptr);
printf("& var1 = %x\n", &vvar1);
printf("& var2 = %x\n", &vvar2);
pptr = &vvar1;
printf("ptr = %x\n", pptr);
printf("*ptr = %d\n", *pptr);
pptr = &vvar2;
printf("ptr = %x\n", pptr);
printf("*ptr = %d\n", *pptr);

/* Ex. 2 Result:
& ptr = 61ff04
& var1 = 61ff00
& var2 = 61fefc
ptr = 61ff00
*ptr = 11
ptr = 61fefc
*ptr = 22
*/

printf("\n");

// Example 3

int var1, var2;
int* ptr;
ptr = &var1;
*ptr = 37;
var2 = *ptr;
printf("var1 = %d\n", var1);
printf("var2 = %d\n", var2);

/* Ex. 3 Result:
var1 = 37
var2 = 37
*/

printf("\n");

// Example 4

int my_array[] = {31, 54, 77, 72, 93};

int* pntr;

pntr = my_array;
printf("%d\t", *pntr);

pntr = pntr + 2;
printf("%d\t", *pntr);

pntr++;
printf("%d\t", *pntr);

pntr = pntr - 2;
printf("%d\t", *pntr);

pntr--;
printf("%d\t", *pntr);

/* Ex. 4 Result:
31      77      72      54      31
*/

return 0;
}