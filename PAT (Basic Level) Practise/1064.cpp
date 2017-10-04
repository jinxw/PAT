#include<iostream>
#include<set>
int main(){
    size_t n;
    std::cin>>n;
    std::set<size_t> friend_card_set;
    for(size_t i=0;i<n;++i){
        size_t tmp;
        std::cin>>tmp;
        size_t friend_card=0;
        while(tmp!=0){
            friend_card+=tmp%10;
            tmp/=10;
        }
        friend_card_set.insert(friend_card);
    }
    std::cout<<friend_card_set.size()<<std::endl;
    bool flag=false;
    for(const auto &n:friend_card_set){
        if(flag==true){
            std::cout<<" ";
        }
        std::cout<<n;
        flag=true;
    }
    std::cout<<std::endl;
    return 0;
}