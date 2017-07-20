#include <stdio.h>
#include <stdlib.h>
struct student{
    int id;
    int de;
    int cai;
    int sum;
};
int mycmp(const void *,const void *);
int main(void){
    int n,l,h;  //考生总数、录取最低分数线、优先录取线
    scanf("%d%d%d",&n,&l,&h);
    struct student arr[n];
    struct student *parr[4][n];
    int f[4]={0};
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].id,&arr[i].de,&arr[i].cai);
        arr[i].sum=arr[i].de+arr[i].cai;
        if(arr[i].cai<l||arr[i].de<l)
            continue;
        if(arr[i].cai>=h&&arr[i].de>=h){
            parr[0][f[0]]=&arr[i];
            f[0]++;
        }else if(arr[i].de>=h){
            parr[1][f[1]]=&arr[i];
            f[1]++;
        }else if(arr[i].de>=arr[i].cai){
            parr[2][f[2]]=&arr[i];
            f[2]++;
        }else{
            parr[3][f[3]]=&arr[i];
            f[3]++;
        }
    }
    printf("%d\n",f[0]+f[1]+f[2]+f[3]);
    for(int i=0;i<4;i++){
        qsort(parr[i],f[i],sizeof(struct student *),mycmp);
        for(int j=0;j<f[i];j++){
            printf("%d %d %d\n",parr[i][j]->id,parr[i][j]->de,parr[i][j]->cai);
        }
    }
    return 0;
}
int mycmp(const void *pl,const void *pr){
    const struct student **p1 = (const struct student **)pl;
    const struct student **p2 = (const struct student **)pr;
    if((*p1)->sum!=(*p2)->sum){
        return (*p2)->sum-(*p1)->sum;
    }else if((*p1)->de!=(*p2)->de){
        return (*p2)->de-(*p1)->de;
    }else{
        return (*p1)->id-(*p2)->id;
    }
}