#include<iostream>
int main(){
    size_t n;
    std::cin>>n;
    size_t a_han,a_hua,b_han,b_hua;
    size_t a=0,b=0;
    for(size_t i=0;i<n;++i){
        std::cin>>a_han>>a_hua>>b_han>>b_hua;
        if(a_hua==a_han+b_han&&b_hua!=a_han+b_han){
            ++b;    //输的人喝酒
        }
        if(a_hua!=a_han+b_han&&b_hua==a_han+b_han){
            ++a;
        }
    }
    std::cout<<a<<" "<<b<<std::endl;
    return 0;
}