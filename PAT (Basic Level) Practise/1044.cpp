#include<iostream>
#include<array>
#include<string>
#include<cctype>
void translate_to_Mars(std::string &);
void translate_to_earth(std::string &);
std::array<std::string,13> low{"tret","jan", "feb", "mar", "apr",
"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
std::array<std::string,12> high{"tam", "hel", "maa", "huh", "tou",
"kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(){
    size_t n;
    std::cin>>n;
    getchar();
    for(size_t i=0;i<n;++i){
        std::string s;
        std::getline(std::cin,s);
        if(isdigit(s[0])){
            translate_to_Mars(s);
        }else{
            translate_to_earth(s);
        }
    }
    return 0;
}
void translate_to_Mars(std::string &s){
    int i = stoi(s);
    if(i>12){
        std::cout<<high[i/13-1];
        if(i%13!=0){
            std::cout<<" "<<low[i%13];
        }
        std::cout<<std::endl;
    }else{
        std::cout<<low[i]<<std::endl;
    }
}
void translate_to_earth(std::string &s){
    if(s.size()>4){
        size_t sum=0;
        std::string a(s,0,3);
        for(size_t i=0;i<12;++i){
            if(high[i]==a){
                sum+=(i+1)*13;
                break;
            }
        }
        s.erase(0,4);
        for(size_t i=0;i<13;++i){
            if(low[i]==s){
                sum+=i;
                break;
            }
        }
        std::cout<<sum<<std::endl;
    }else{
        for(size_t i=0;i<13;++i){
            if(low[i]==s){
                std::cout<<i<<std::endl;
                break;
            }
            if(high[i]==s){
                std::cout<<(i+1)*13<<std::endl;
                break;
            }
        }
    }
}