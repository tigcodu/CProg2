#include <stdio.h>

int main(int argc, const char* arg[]) {
    int arr[80];
    int *p = arr; 
    
    while(1) { 
        printf("Enter value: "); 
        scanf("%d", p); 
        if (*p == 0) {
            break;
        }
        p++; 
    } 
    --p; 
    while(*p != 0) { 
        printf("%d\t",*p); 
        --p; 
    } 
    return 0;
}



/*
    int a = 0;
    int *p = &a; 
    
    while(1) { 
        
        printf("Enter value: "); 
        scanf("%d", p); 
        if (*p == 0) {
            break;
        }
        p++; 
    } 
    --p; 
    while(*p != 0) { 
        printf("%d\t", *p); 
        --p; 
    } 
    return 0;
*/