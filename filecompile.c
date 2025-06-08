#include <stdio.h>
#include <string.h>

int main() {

   FILE *fp;
   
   char name[80] = "Mimi";
   int ans = 1;
   fp = fopen("E:\\TextFiles\\devcompiletest.txt", "w");
   fprintf(fp, "%s\n", name);
   fclose(fp);
   
   fp = fopen("E:\\TextFiles\\devcompiletest.txt", "a");
   while(ans==1) { 
   		printf("Enter name:\t");
        scanf("%s",name);
        fprintf(fp,"%s\n", name);
        printf("Another name? ");
        scanf("%d",&ans);
    }
    fclose(fp);
   
    fp = fopen("E:\\TextFiles\\devcompiletest.txt", "r");
    while(fscanf(fp, "%s", name) != EOF) {
        printf("%s\n", name);
    }
    fclose(fp);

    return 0;
}