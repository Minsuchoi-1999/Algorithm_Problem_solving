#include<stdio.h>

int main(){
    int arr[100][100] = {0,};
    
    int n;
    scanf("%d", &n);
    
    for(int k = 0; k<n; k++){
        int x, y;
        scanf("%d %d", &x, &y);
        
        for(int i= 0; i<10; i++){
            for(int j= 0; j<10; j++){
                arr[y+i][x+j] += 1;   
            }
        }
    }
    
    int count =0;
    
    for(int i= 0; i<100; i++){
        for(int j= 0; j<100; j++){
            if(arr[i][j] != 0){
                count+=1;            
            }        
        }
    }
    
    printf("%d", count);
    
    return 0;
}