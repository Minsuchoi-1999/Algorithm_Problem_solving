#include<stdio.h>

int main(){
    int number;
    scanf("%d", &number);
    
    for(int i = 0; i<number/4; i++){
        printf("long ");
    }
    printf("int");
}