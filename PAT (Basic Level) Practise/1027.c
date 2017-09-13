#include <stdio.h>
int f (int n){
    return 2 * n * n - 1;
}
void print(int full,int fill,char c){
    int blank = full-fill;
    for(int i =0;i<blank;++i){
        printf(" ",c);
    }
    for(int i = 0;i<2*fill-1;++i){
        printf("%c",c);
    }
    printf("\n");
}
int main(void){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int i = 1;
    while(f(i)<=n){
        ++i;
    }
    --i;
    int remain = n - f(i);
    for(int j =i;j>0;--j){
        print(i,j,c);
    }
    for(int j = 2;j<=i;++j){
        print(i,j,c);
    }
    printf("%d",remain);
    return 0;
}