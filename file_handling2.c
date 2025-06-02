#include <stdio.h>
#include <string.h>


int main() {
    FILE *file;

    file = fopen("C:\\Users\\ALMARIE\\Documents\\file2.txt", "r");

    char name[80];

    while(fscanf(file, "%s", name) != EOF) {
        printf("%s\n", name);
    }

    fclose(file);

    return 0;
}

/* 
    FILE *file;
    char name[80];

    file = fopen("C:\\Users\\ALMARIE\\Documents\\file2.txt", "r");

    fscanf(file, "%s\n", name);
    printf("My name is %s", name);
    fclose(file);


    fputc(code, file);
*/