#include <stdio.h>
// #include <string.h>
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    m%=n;
    int arr[n];
    for(int i=m;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(i!=0)
            putchar(' ');
        printf("%d",arr[i]);
    }
    return 0;
}