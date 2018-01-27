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
    std::sort(vn.begin(),vn.end()); //按从小到大排序

    auto it1 = vn.begin();
    auto it2 = it1;
    std::size_t cnt = 1;
    while(it2!=vn.end() && vn.end()-it1>cnt){
        while(it2!=vn.end() && *it2<=*it1*p){
            ++it2;
        }
        std::size_t num = it2 - it1;
        cnt = num>cnt?num:cnt;
        ++it1;
    }
    std::cout<<cnt<<std::endl;
    return 0;
}