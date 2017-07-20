#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[11];
    char number[11];
    int grade;
};
int mycmp(const void *,const void *);
int main(void){
    int n;
    scanf("%d",&n);
    struct student arr[n];
    for(int i=0;i<n;i++){
        scanf("%s",arr[i].name);
        scanf("%s",arr[i].number);
        scanf("%d",&arr[i].grade);
    }
    qsort(arr,n,sizeof(struct student),mycmp);     //为了练习qsort()
    printf("%s %s\n",arr[0].name,arr[0].number);
    printf("%s %s",arr[n-1].name,arr[n-1].number);
    return 0;
}
int mycmp(const void *p1,const void *p2){
    const struct student *pa =(const struct student *) p1;
    const struct student *pb =(const struct student *) p2;
    return pb->grade-pa->grade;
}