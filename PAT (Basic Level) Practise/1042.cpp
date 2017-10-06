#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<cctype>
int main(){
    std::string s;
    std::getline(std::cin,s);
    std::map<char,size_t> cnt;
    for(const auto &c:s){
        if(isalpha(c)){
            ++cnt[tolower(c)];
        }
    }
    std::pair<char,size_t> max={'\0',0};
    for(const auto &n:cnt){
        if(n.second>max.second){
            max = n;
        }
    }
    std::cout<<max.first<<" "<<max.second<<std::endl;
    return 0;
}