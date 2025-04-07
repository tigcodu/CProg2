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
#include<stdio.h>

int main(){
        int arr[80];
	int *p = arr;

	scanf("%d",p);

	while(*p!=0){
        p++;
		printf("Enter value\n");
		scanf("%d",p);
	}
	--p;
	while(p >= arr){
		printf("%d\t",*p);
		--p;
	}

}
*/