#include<iostream>
#include<string>
#include<bitset>
int main(){
    std::string s;
    std::cin>>s;
    std::string pat("PATest");
    std::bitset<6> b;
    b.set();
    while(b.any()){
        for(size_t i=0;i<6;++i){
            if(b.test(i)){
                auto pos = s.find(pat[i]);
                if(pos != std::string::npos){
                    std::cout<<pat[i];
                    s.erase(pos,1);
                }else{
                    b.reset(i);
                }
            }
        }
    }
    return 0;
}