#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int a[5]={0},count[5]={0};
    int num;
    int flag=1;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        switch(num%5){
            case 0:
                if(num%2==0){
                    a[0]+=num;
                    count[0]=1;
                }
                break;
            case 1:
                a[1]+=flag*num;
                flag*=-1;
                count[1]=1;
                break;
            case 2:
                a[2]++;
                count[2]=1;
                break;
            case 3:
                a[3]+=num;
                count[3]++;
                break;
            case 4:
                count[4]++;
                if(num>a[4])
                    a[4]=num;
                break;
        }
    }
    for(int i=0;i<5;i++){
        if(i!=0)
            putchar(' ');
        if(count[i]!=0){
            if(i!=3){
                printf("%d",a[i]);
            }else{
                printf("%.1f",(double)a[3]/count[3]);
            }
        }else{
            putchar('N');
        }
    }
    return 0;
}