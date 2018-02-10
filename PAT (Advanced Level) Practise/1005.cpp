#include <iostream>
#include <string>
#include <array>

std::array<std::string,10> english{"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    std::string input;
    std::cin>>input;
    int sum = 0;
    for(auto &ch:input){
        sum += ch-'0';
    }
    std::string output = std::to_string(sum);
    for(auto it=output.begin();it!=output.end();it++){
        if(it!=output.begin())
            std::cout<<" ";
        std::cout<<english[*it-'0'];
    }
    std::cout<<std::endl;
    return 0;
}