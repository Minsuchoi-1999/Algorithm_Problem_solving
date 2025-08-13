#include <stdio.h>

int main()
{
    int var1;
    int var2;
    
    
    scanf("%d %d",&var1,&var2);

    int var3 = var1 - 1;
    int var4 = var2 - 45;
    int var5 = var2 + 15;
    int var6 = var1 + 23;

    if(var1>=1){
        if(var2>=45){
            printf("%d %d",var1, var4);
        }
        else if(var2<45){
        printf("%d %d", var3, var5);
        }
    }
    else if(var1<1){
        if(var2>=45){
            printf("%d %d",var1, var4);
        }
        else if(var2<45){
        printf("%d %d", var6, var5);
        }
    }



    return 0;
}