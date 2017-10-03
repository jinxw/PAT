#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
int main(){
    size_t n;
    std::cin>>n;
    size_t team,member,score;
    std::map<size_t,size_t> sum_score;
    for(size_t i=0;i<n;++i){
        scanf("%d-%d%d",&team,&member,&score);
        sum_score[team]+=score;
    }
    std::pair<size_t,size_t> max;
    for(const auto &n:sum_score){
        std::cout<<max.first<<" "<<max.second<<std::endl;   //
        if(n.second>=max.second){
            max.first = n.first;
            max.second = n.second;
        }
    }
    std::cout<<max.first<<" "<<max.second<<std::endl;
    return 0;
}