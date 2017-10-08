#include<iostream>
int main(){
    size_t n;
    std::cin>>n;
    size_t sum=0;
    for(size_t i=0;i<n;++i){
        size_t tmp;
        std::cin>>tmp;
        sum+=tmp*11*(n-1);
    }
    std::cout<<sum<<std::endl;
    return 0;
}