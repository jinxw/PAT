#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
int main(){
    int n;
    std::cin>>n;
    int team,member,score;
    std::map<int,int> sum_score;
    for(int i=0;i<n;++i){
        scanf("%d-%d%d",&team,&member,&score);
        sum_score[team]+=score;
    }
    std::pair<int,int> max;
    for(const auto &n:sum_score){
        if(n.second>=max.second){
            max = n;
        }
    }
    std::cout<<max.first<<" "<<max.second<<std::endl;
    return 0;
}