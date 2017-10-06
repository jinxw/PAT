#include<stdio.h>
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[2][m];
    for(int i=0;i<m;++i){
        scanf("%d",&arr[0][i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&arr[1][i]);
    }
    for(int i=0;i<n;++i){
        int score=0;
        for(int j=0;j<m;++j){
            int tmp;
            scanf("%d",&tmp);
            if(tmp==arr[1][j]){
                score+=arr[0][j];
            }
        }
        printf("%d\n",score);
    }
    return 0;
}