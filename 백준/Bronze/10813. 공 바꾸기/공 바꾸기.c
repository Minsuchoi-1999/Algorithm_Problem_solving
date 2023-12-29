#include<stdio.h>
#define MAX 101

int main(){
    int size, orders;
    scanf("%d %d", &size, &orders);

    int arr[MAX] ={0, };
    
    for(int i= 0; i<size; i++){
        arr[i] = i+1;
    }
    
    for(int i = 0; i<orders; i++){
        int box1, box2;
        scanf("%d %d", &box1 ,&box2);
        
        int temp = arr[box1-1];
        arr[box1-1] = arr[box2-1];
        arr[box2-1] = temp;
    }
    
    for(int i= 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}