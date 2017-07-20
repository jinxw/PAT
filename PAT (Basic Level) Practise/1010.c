#include <stdio.h>
int main(void){
    int a,b;
    _Bool flag = 0;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(b==0&&flag==0){
            printf("0 0");
            break;
        }
        if(b!=0){
            if(flag == 1)
                putchar(' ');
            printf("%d %d",a*b,b-1);
        }else{
            break;
        }
        flag = 1;
    }
    return 0;
}