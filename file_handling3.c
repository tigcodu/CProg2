#include <stdio.h>
#include <string.h>


int main() {
    FILE *fp;

    fp = fopen("D:\\Tempo\\binaryfile.dat", "r");

    char name[80];

    fread(name, sizeof(name), 1, fp);
    printf("%s", name);

    fclose(fp);

    return 0;
}

/*
    fp = fopen("D:\\Tempo\\binaryfile.dat", "a");
    fwrite(&name, sizeof(name), 1, fp);

*/