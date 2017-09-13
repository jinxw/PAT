#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::size_t n;
    long long p;
    std::cin>>n>>p;
    std::vector<long long> vn;
    for(std::size_t i=0;i<n;++i){
        long long tmp;
        std::cin>>tmp;
        vn.push_back(tmp);
    }
    std::sort(vn.begin(),vn.end());
    auto min = vn.front();
    auto first_big = std::find_if(vn.begin(),vn.end(),[min,p](const long long &n){return n>min*p;});
    vn.erase(first_big,vn.end());
    std::cout<<vn.size()<<std::endl;
    return 0;
}