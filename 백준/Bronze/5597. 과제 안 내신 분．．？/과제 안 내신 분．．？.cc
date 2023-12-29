#include<stdio.h>

int main(){
    int arr[30] ={0, };
    
    for(int i= 0; i<28; i++){
        int num;
        scanf("%d", &num);
        arr[num-1] = 1;
    }
    
    for(int i= 0; i<30; i++){
        if(arr[i] == 0){
            printf("%d\n", i+1);
        }
    }

    return 0;
}