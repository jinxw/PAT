#include <stdio.h>
#include <stdlib.h>  //qsort
int mycmp(const void *,const void *);
int main(void){
    int n;
    scanf("%d",&n);
    int num[n];
    int primary[n];

    //读入的同时从左向右筛选一遍
    int left_max=0;
    for(int i=0;i<n;++i){
        scanf("%d",&num[i]);
        if(num[i]>=num[left_max]){
            left_max = i;
            primary[i]=1;
        }else{
            primary[i]=0;
            primary[left_max]=0;
        }
    }

    //从右向左筛选一遍
    int right_min=n-1;
    for(int i=n-2;i>=0;--i){   //或者将下一行改成<=
        if(num[i]<num[right_min]){
            right_min = i;
        }else{
            primary[i]=0;
            primary[right_min]=0;
        }
    }

    int cnt=0;
    int arr[n];
    for(int i=0;i<n;++i){
        if(primary[i]==1){
            arr[cnt] = num[i];
            ++cnt;
        }
    }
    printf("%d\n",cnt);
    qsort(arr,cnt,sizeof(int),mycmp);
    for(int i=0;i<cnt;++i){
        if(i!=0){
            printf(" ");
        }
        printf("%d",arr[i]);
    }
    printf("\n");

    return 0;
}
int mycmp(const void *lhs,const void *rhs){
    const int *pa =(const int *) lhs;
    const int *pb =(const int *) rhs;
    return *pa-*pb;
}