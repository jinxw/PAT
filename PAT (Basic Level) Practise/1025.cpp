#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

int main(){
    int first_addr,n,k;
    scanf("%d%d%d",&first_addr,&n,&k);
    //还可以直接把addr当作数组下标，那样速度更快。
    std::unordered_map<int,std::pair<int,int>> map;
    for(int i=0;i<n;++i){
        int addr;
        scanf("%d",&addr);
        scanf("%d%d",&map[addr].first,&map[addr].second);
    }
    std::vector<std::pair<int,int>> list;    //addr,data
    for(int next_addr=first_addr;next_addr!=-1;){
        auto &tmp = map[next_addr];
        list.push_back(std::make_pair(next_addr,tmp.first));
        next_addr = tmp.second;
    }
    for(int i=0;i+k<=list.size();i+=k){
        std::reverse(list.begin()+i,list.begin()+i+k);
    }
    bool is_first = true;
    for (const auto &a : list){
        if (is_first){
            printf("%05d %d ", a.first, a.second);
            is_first = false;
        }else{
            printf("%05d\n%05d %d ", a.first, a.first, a.second);
        }
    }
    printf("-1\n");
    return 0;
}