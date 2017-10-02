#include<iostream>
#include<map>
int main(){
    std::ios::sync_with_stdio(false);    
    size_t n;
    std::cin>>n;
    std::map<size_t,size_t> score;
    size_t tmp;
    for(size_t i=0;i<n;++i){
        std::cin>>tmp;
        ++score[tmp];
    }
    size_t k;
    std::cin>>k;
    bool flag=false;
    for(size_t i=0;i<k;++i){
        std::cin>>tmp;
        if(flag == true){
            std::cout<<" ";
        }
        std::cout<<score[tmp];
        flag = true;
    }
    std::cout<<std::endl;
    return 0;
}