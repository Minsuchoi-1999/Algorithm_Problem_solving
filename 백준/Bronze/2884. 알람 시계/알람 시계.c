#include<stdio.h>

int main(){
    int hour;
    int minute;

    scanf("%d %d", &hour, &minute);

    int time = hour*60+minute;

    time -= 45;

    if(time<0){
        time += 24*60;   
    }

    hour = time/60;
    minute = time%60;
    
    printf("%d %d", hour, minute);
    
    return 0;
}