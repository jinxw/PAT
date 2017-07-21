#include <stdio.h>
#include <stdlib.h>
int mycmp(const void *, const void *);
struct mooncake{
    double kucun;
    double sum;
    double price;
};
int main(void){
    int n;
    double d;
    scanf("%d%lf",&n,&d);
    struct mooncake arr[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&arr[i].kucun);
    }
    for(int i=0;i<n;i++){
        scanf("%lf",&arr[i].sum);
        arr[i].price = arr[i].sum/arr[i].kucun;
    }
    qsort(arr,n,sizeof(struct mooncake),mycmp); //按单价从高到低排序
    double profit = 0.0;
    int flag = 0;
    while(d>0){
        if(arr[flag].kucun<d){
            d -= arr[flag].kucun;
            profit +=arr[flag].sum;
            ++flag;
            if(flag==n){
                break;
            }
        }else{
            profit += d*arr[flag].price;
            d = 0;
        }
    }
    printf("%.2f",profit);
    return 0;
}
int mycmp(const void *p1,const void *p2){
    const struct mooncake *pa = (const struct mooncake *)p1;
    const struct mooncake *pb = (const struct mooncake *)p2;
    return (pb->price - pa->price)>0?1:-1;
}