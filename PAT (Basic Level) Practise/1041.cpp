#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
int main(){
    size_t n;
    std::cin>>n;
    std::vector<std::tuple<size_t,size_t,size_t>> candidates;
    for(size_t i = 0 ;i<n;++i){
        std::tuple<size_t,size_t,size_t> tmp;
        std::cin>>std::get<0>(tmp)>>std::get<1>(tmp)>>std::get<2>(tmp);
        candidates.push_back(tmp);
    }
    size_t m;
    std::cin>>m;
    for(size_t i=0;i<m;++i){
        size_t test_seat;
        std::cin>>test_seat;
        //原本在lambda的（）中使用auto本机可行PAT提示编译错误
        auto result=std::find_if(candidates.cbegin(),candidates.cend(),[test_seat](const std::tuple<size_t,size_t,size_t> &n){return std::get<1>(n)==test_seat;});
        std::cout<<std::get<0>(*result)<<" "<<std::get<2>(*result)<<std::endl;
    }
    return 0;
}