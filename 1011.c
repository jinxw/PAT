#include <stdio.h>
int main(void){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("Case #%d: ",i+1);
        if(a+b>c){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    return 0;
}