#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    if(num<=100 && num>=90){
        printf("A");
    }
    else if(num>=80 && num<=89){
        printf("B");
    }
    else if(num>=70 && num<=79){
        printf("C");
    }
    else if(num>=60 && num<=69){
        printf("D");
    }
    else{
        printf("F");
    }
    
    return 0;
}