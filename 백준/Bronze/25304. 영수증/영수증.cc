#include<stdio.h>

int main(){
    long long target;
    int n;
    scanf("%lld %d", &target, &n);
    
    for(int i= 0; i<n; i++){
        long long price, num;
        scanf("%d %d", &price, &num);
        
        target -= price*num;
    }// 영수증 총 금액에서 값을 뺀다.
    
    if(target){//0이 아니라면 총 금액과 합산액이 다르단 소리이고
        //0이 아닌 모든 경우는 참이니까 No가 여기서 실행된다.
        printf("No");
    }
    else{//반면에 0이라면 같다는 소리이고, 위의 if문에서 실행되지 않고 여기서 실행된다.
        printf("Yes");
    }
}