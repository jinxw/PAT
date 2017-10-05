#include<iostream>
#include<vector>
#include<string>
#include<set>
int main(){
    size_t m,n,s;
    std::cin>>m>>n>>s;
    if(s>m){
        std::cout<<"Keep going..."<<std::endl;
        return 0;
    }
    std::vector<std::string> forwarding;
    for(size_t i=0;i<m;++i){
        std::string name;
        std::cin>>name;
        forwarding.push_back(name);
    }
    std::set<std::string> winning;
    for(size_t i=s;i<=m;i=i+n){
        if(winning.find(forwarding[i-1])==winning.end()){  //没有中过奖
            std::cout<<forwarding[i-1]<<std::endl;
            winning.insert(forwarding[i-1]);
        }else{
            ++i;
            if(i>m){
                goto end;
            }
            while(winning.find(forwarding[i-1])!=winning.end()){ //中过奖
                ++i;
                if(i>m){
                    goto end;
                }
            }
            std::cout<<forwarding[i-1]<<std::endl;
            winning.insert(forwarding[i-1]);
        }
    }
    end:
    return 0;
}