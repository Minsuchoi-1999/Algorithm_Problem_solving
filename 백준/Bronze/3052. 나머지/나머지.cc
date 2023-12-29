#include<stdio.h>

int main(){
    int numbers[42] = {0,};
    
    for(int i = 0; i<10; i++){
        int number;
        scanf("%d", &number);
        numbers[number%42] += 1;
    }

    int count = 0;
    
    for(int i= 0; i<42; i++){
        if(numbers[i]!=0){
            count+=1;
        }
    }
    
    printf("%d", count);
}