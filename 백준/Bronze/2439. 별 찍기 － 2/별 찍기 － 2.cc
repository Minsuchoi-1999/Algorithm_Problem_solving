#include<stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    for(int i = 1; i<=number; i++){
        for(int k = i+1; k<=number; k++){
            printf(" ");
        }
        for(int j =1; j<=i; j++){
            printf("*");
        }
        
        if(i!=number){
            printf("\n");
        }
    }

}