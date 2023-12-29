#include<stdio.h>
#define MAX 1001

int main(){
    int n;
    scanf("%d", &n);
    
    int max = -1; //최대값을 구하기 위한 초기값 설정
    
    int arr[MAX] = {0,};
     
    for(int i= 0; i<n; i++){
        scanf("%d", &arr[i]);
        if(max < arr[i]){
             max = arr[i];   
        }//최대값 구하기 알고리즘
    }
    
    double sum = 0;
    
    for(int i= 0; i<n; i++){
        sum += 100.0*arr[i]/max; //형변환 스킬      
    }
    
    printf("%.3lf", sum/n);
}