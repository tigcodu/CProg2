#include <stdio.h>

struct student
{ char name[80];
int roll;
float mark;
};
int main() {
struct student s;
printf("Enter name:\t");
scanf("%s", s.name);
printf("\nEnter roll:\t");
scanf("%d", &s.roll);
printf("\nEnter mark:\t");
scanf("%f ", &s.mark);
printf("\nname\troll\tmark\n");
printf("%s\t%d\t%f\n", s.name, s.roll, s.mark);
return 0;
}
