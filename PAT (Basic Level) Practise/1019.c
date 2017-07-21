#include <stdio.h>
#include <stdlib.h>
int jian(int);
int main(void){
    int n;
    scanf("%d",&n);
    do{
        n = jian(n);
    }while(n!=0&&n!=6174);
    return 0;
}
int jian(int n){
    inline int dijian(int n){
        int num[4]={n/1000,n%1000/100,n%100/10,n%10};
        int cmp1(const void *pl, const void *pr){
            const int *p1 = (const int *)pl;
            const int *p2 = (const int *)pr;
            return *p2-*p1;
        }
        qsort(num,4,sizeof(int),cmp1);
        return num[0]*1000+num[1]*100+num[2]*10+num[3];
    }
    inline int dizeng(int n){
        int num[4]={n/1000,n%1000/100,n%100/10,n%10};
        int cmp1(const void *pl, const void *pr){
            const int *p1 = (const int *)pl;
            const int *p2 = (const int *)pr;
            return *p1-*p2;
        }
        qsort(num,4,sizeof(int),cmp1);
        return num[0]*1000+num[1]*100+num[2]*10+num[3];
    }
    int max = dijian(n);
    int min = dizeng(n);
    printf("%04d - %04d = %04d\n",max,min,max-min);
    return max-min;
}