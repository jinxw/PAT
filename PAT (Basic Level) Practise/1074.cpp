#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

std::vector<int> s2v(std::string &s);

int main(){
    std::string s,s1,s2;
    std::cin>>s>>s1>>s2;
    auto jinzhi = s2v(s);
    auto a = s2v(s1);
    auto b = s2v(s2);
    std::string result;
    int t1,t2;
    int jinwei = 0;
    for(std::size_t pos=0;pos<jinzhi.size();++pos){
        if(pos<a.size()){
            t1 = a[pos];
        }else{
            t1 = 0;
        }
        if(pos<b.size()){
            t2 = b[pos];
        }else{
            t2 = 0;
        }
        int recent_jinzhi = jinzhi[pos]==0 ? 10 : jinzhi[pos];
        int sum = t1+t2+jinwei;
        if(sum>=recent_jinzhi){
            jinwei = 1;
            sum -= recent_jinzhi;
        }else{
            jinwei = 0;
        }
        result.insert(result.begin(),'0'+sum);
    }
    if(jinwei == 1){
        result.insert(result.begin(),'1');
    }
    //std::cout<<atoi(result.c_str())<<std::endl;
    for(auto it=result.begin();it!=result.end();){
        if(*it == '0'){
            it = result.erase(it);
        }else{
            break;
        }
    }
    if(result.size() == 0){
        std::cout<<"0"<<std::endl;  //#5
    }else{
        std::cout<<result<<std::endl;
    }
    return 0;
}

std::vector<int> s2v(std::string &s){
    std::vector<int> v;
    for(auto it=s.crbegin();it!=s.crend();++it){
        v.push_back(*it-'0');
    }
    return v;
}