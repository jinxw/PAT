#include <stdio.h>
int main(void){
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);
    int sum = a+b;
    int arr[31]={0},i=0;
    do{
        arr[i++]=sum%d;
        sum/=d;
    }while(sum!=0);
    for(int j=i-1;j>=0;j--){
        printf("%d",arr[j]);
    }
}