#include <iostream>
#include <unordered_map>
#include <vector>

int main(){
    int n,m;
    std::cin>>n>>m;
    if(m == 0){
        std::cout<<"1"<<std::endl;  //#2 其实本来以为错掉的那个点是因为家族内远亲结婚。。。
        return 0;
    }
    std::unordered_map<int,std::vector<int>> child;
    for(int i=0;i<m;++i){
        int id,k;
        std::cin>>id>>k;
        child[id].resize(k);
        for(int j=0;j<k;++j){
            std::cin>>child[id][j];
        }
    }
    auto &v = child[1];
    std::cout<<"0";
    while(!v.empty()){
        std::vector<int> next;
        int cnt = 0;
        for(auto &n:v){
            if(child.find(n) == child.end()){
                cnt++;
            }else{
                next.insert(next.end(),child[n].begin(),child[n].end());
            }
        }
        std::cout<<" "<<cnt;
        v = next;
    }
    std::cout<<std::endl;
    return 0;
}