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
        
        box1 -= 1;
        box2 -= 1;
        
        int length = box2 + box1;
        
        for(int i= box1; i<= (box1+box2)/2; i++){
            int temp = arr[i];
            arr[i] = arr[length - i];
            arr[length - i] = temp;// 값을 교환하는 방법을 꼭 알자.
        }
    }
    
    for(int i= 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}