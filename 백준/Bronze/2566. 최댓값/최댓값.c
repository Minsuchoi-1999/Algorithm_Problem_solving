#include<stdio.h>

int main(){
    int arr[9][9] = {0,};
    
    for(int i= 0; i<9; i++){
        for(int j= 0; j<9; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int max = -1;
    int pos_x, pos_y;
    
    for(int i= 0; i<9; i++){
        for(int j= 0; j<9; j++){
            if(max < arr[i][j]){
                max = arr[i][j];
                pos_x = i;
                pos_y = j;
            }
        }
    }
    printf("%d\n%d %d", max, pos_x+1, pos_y+1);
    
    return 0;
}