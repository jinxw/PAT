#include<iostream>
int main(){
    size_t m,n,a,b,replace;
    std::cin>>m>>n>>a>>b>>replace;
    for(size_t i=0;i<m;++i){
        for(size_t j=0;j<n;++j){
            size_t tmp;
            scanf("%d",&tmp);
            if(tmp>=a&&tmp<=b){
                tmp=replace;
            }
            if(j!=0){
                printf(" ");
            }
            printf("%03d",tmp);
        }
        printf("\n");
    }
    return 0;
}