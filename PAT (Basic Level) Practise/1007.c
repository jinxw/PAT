#include <stdio.h>
inline _Bool isPrime(int);
int main(void){
    int n;
    scanf("%d",&n);
    if(n<5){
        printf("%d",0);
        return 0;
    }
    int a=2,b=3,count=0;
    for(int i=4;i<=n;i++){
        if(isPrime(i)){
            a=b;
            b=i;
            if(b-a==2){
                // printf("%d %d\n",a,b);  //test
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
_Bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}