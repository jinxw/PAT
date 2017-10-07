#include<stdio.h>
void print_n(int n, char c);
int main(void){
    int n,c;
    scanf("%d %c",&n,&c);
    print_n(n,c);
    printf("\n");
    int row = (n+1)/2;
    for(int i=0;i<row-2;++i){
        putchar(c);
        print_n(n-2,' ');
        putchar(c);
        printf("\n");
    }
    print_n(n,c);
    return 0;
}
void print_n(int n, char c){
    for(int i=0;i<n;++i){
        putchar(c);
    }
}