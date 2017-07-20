#include <stdio.h>
inline void print(int,char);
int main(void){
    int n;
    scanf("%d",&n);
    if(n>=100)
        print(n/100,'B');
    if(n>=10)
        print(n%100/10,'S');
    print(n%10,'n');
    return 0;
}
void print(int n,char ch){
    if(ch=='n'){
        for(int i=0;i<n;i++)
            putchar('0'+i+1);
    }else{
        for(int i=0;i<n;i++)
            putchar(ch);
    }
}