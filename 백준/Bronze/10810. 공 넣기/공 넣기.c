#include<stdio.h>
#define MAX 101

int main(){
    int size, orders;
    scanf("%d %d", &size, &orders);

    int arr[MAX] ={0, };
    
    for(int i = 0; i<orders; i++){
        int start, end, ball;
        scanf("%d %d %d", &start,&end, &ball);
        
        for(int j = start -1; j<end; j++){
            arr[j] = ball;
        }
    }
    
    for(int i= 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}