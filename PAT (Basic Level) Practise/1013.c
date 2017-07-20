#include <stdio.h>
inline _Bool isPrime(int);
int main(void){
    int m,n;
    scanf("%d%d",&m,&n);
    int count = 0;
    for(int i=2;count<n;i++){
        if(isPrime(i)){
            count++;
            if(count >= m){
                if((count-m+1)%10!=1)
                    putchar(' ');
                printf("%d",i);
                if((count-m+1)%10 == 0)
                    putchar('\n');
            }
        }
    }
    return 0;
}
_Bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}