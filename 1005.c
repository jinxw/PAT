#include <stdio.h>
#include <stdlib.h>
int mycmp(const void *,const void *);
int delete(int *,int,int);
int main(void){
    int k;
    scanf("%d",&k);
    int count = k;
    int n[k];
    for(int i=0;i<k;i++){
        scanf("%d",&n[i]);
    }
    // for(int i=0;i<k;i++){   //test
    //     printf("%d",n[i]);
    // }
    for(int i=0;i<k;i++){
        if(n[i]==0)
            continue;
        int tmp=n[i];
        while(tmp!=1){
            if(tmp%2==0){
                tmp/=2;
                count-=delete(n,k,tmp);
            }else{
                tmp=(3*tmp+1)/2;
                count-=delete(n,k,tmp);
            }
        }
    }
    // for(int i=0;i<k;i++){   //test
    //     printf("%d",n[i]);
    // }
    int remain[count];
    for(int i=0,j=0;i<count;j++){
        if(n[j]!=0){
            remain[i]=n[j];
            i++;
        }
    }
    qsort(remain,count,sizeof(int),mycmp);
    for(int i=0;i<count;i++){
        if(i!=0)
            putchar(' ');
        printf("%d",remain[i]);
    }
    return 0;
}
int delete(int *n,int size,int d){
    for(int i=0;i<size;i++){
        if(n[i]==d){
            n[i]=0;
            return 1;
        }
    }
    return 0;
}
int mycmp(const void *p1,const void *p2){
    const int *pa=(const int *)p1;
    const int *pb=(const int *)p2;
    return *pb-*pa;
}