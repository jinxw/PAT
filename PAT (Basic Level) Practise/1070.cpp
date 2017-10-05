#include<iostream>
#include<queue>
#include<vector>
#include<functional> //greater
#include<algorithm>
int main(){
    size_t n;
    std::cin>>n;
    std::priority_queue<size_t,std::vector<size_t>,std::greater<size_t>> ropes;
    for(size_t i=0;i<n;++i){
        size_t tmp;
        scanf("%d",&tmp);
        ropes.push(tmp);
    }
    while(ropes.size()!=1){
        size_t first = ropes.top();
        ropes.pop();
        size_t second = ropes.top();
        ropes.pop();
        ropes.emplace((first+second)/2);
    }
    std::cout<<ropes.top()<<std::endl;
    return 0;
}