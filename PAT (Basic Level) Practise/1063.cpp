#include<iostream>
#include<cmath>
int main(){
    size_t n;
    std::cin>>n;
    double max=0.0;
    for(size_t i=0;i<n;++i){
        double real,virt;
        std::cin>>real>>virt;
        double radius=sqrt(real*real+virt*virt);
        if(radius>max){
            max=radius;
        }
    }
    printf("%.2f\n",max);
    return 0;
}