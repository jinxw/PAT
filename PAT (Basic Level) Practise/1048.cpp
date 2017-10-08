#include<iostream>
#include<string>
#include<array>
int main(){
    std::string a,b;
    std::cin>>a>>b;
    if(a.size()>b.size()){
        b=std::string(a.size()-b.size(),'0')+b;
    }else{
        a=std::string(b.size()-a.size(),'0')+a;
    }
    std::array<char,13> thirteen{'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
    for(int pos = a.size()-1;pos>=0;--pos){
        size_t result;
        if((a.size()-pos)%2==0){
            result = (b[pos] - a[pos] + 10)%10;
        }else{
            result = ((b[pos]-'0')+(a[pos]-'0')) % 13;
        }
        b[pos] = thirteen[result];
    }
    std::cout<<b<<std::endl;
    return 0;
}