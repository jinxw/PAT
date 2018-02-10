#include <iostream>
#include <cmath>
#include <cstdio>

int main(){
    int a,b;
    std::cin>>a>>b;
    int sum = a+b;
    if(abs(sum)>=1000000){
        printf("%d,%03d,%03d\n",sum/1000000,abs(sum)%1000000/1000,abs(sum)%1000);
    }else if(abs(sum)>=1000){
        printf("%d,%03d\n",sum/1000,abs(sum)%1000);
    }else{
        printf("%d\n",sum);
    }
    return 0;
}