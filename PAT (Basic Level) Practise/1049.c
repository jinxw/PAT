/*
1   1
2   2  2
3   3  4  3
4   4  6  6  4
5   5  8  9  8 5
6   6 10 12 12 10 6
猜想：
7   7 12 15 16 15 12 7
n   n (n-1)*2 (n-2)*3 (n-3)*4 ...
*/
#include<stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    double num;
    double sum = 0.0;
    for(int i=0;i<n;++i){
        scanf("%lf",&num);
        sum+=num*(n-i)*(i+1);
    }
    printf("%.2f",sum);
    return 0;
}