#include <stdio.h>

int main()
{
    int var1;
    int var2;

    scanf("%d",&var1);
    scanf("%d",&var2);

    if(var1>0&&var2>0){
        printf("1");
    }
    else if(var1<0&&var2>0){
        printf("2");
    }
    else if(var1<0&&var2<0){
        printf("3");
    }
    else if(var1>0&&var2<0){
        printf("4");
    }

    return 0;
}