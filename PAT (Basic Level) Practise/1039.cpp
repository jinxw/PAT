#include<iostream>
#include<string>
int main(){
    std::string sell,want;
    std::cin>>sell>>want;
    size_t no=0;
    for(const auto &c:want){
        auto pos = sell.find(c);
        if(pos!=std::string::npos){
            sell.erase(pos,1);
        }else{
            ++no;
        }
    }
    if(no==0){
        std::cout<<"Yes "<<sell.size()<<std::endl;
    }else{
        std::cout<<"No "<<no<<std::endl;
    }
}