#include <stdio.h>

int main(int argc, const char* arg[]){
    int *p = 0; 
    scanf("%d\n",p); 
    p++; 
    while(*p != 0) { 
        printf("Enter value:\n"); 
        scanf("%d",p); p++; 
        } 
        --p; 
        while(*p != 0) { 
            printf("%d\t",*p); 
            --p; 
            } 
    return 0;
}

/*
#include <stdio.h>

int main(int argc, const char* arg[]){
    int *p = 0; 
    *(p++); 
    while(p != 0) { 
        
        printf("Enter value:\n"); 
        scanf("%d", p); 
        *(p++); 
    } 
    *(--p); 
    while(p != 0) { 
        printf("%d\t",*p); 
        *(--p); 
    } 
    return 0;
}

*/

// p <= arr + 80