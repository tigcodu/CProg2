#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char name[80];
    int ans = 1;

    file = fopen("C:\\Users\\ALMARIE\\Documents\\file.txt", "a");

    while(ans==1)
    { printf("Enter name:\t");
        scanf("%s",name);
        fprintf(file,"%s\n",name);
        printf("Another name? ");
        scanf("%d",&ans);
    }
    fclose(file);

    return 0;
}