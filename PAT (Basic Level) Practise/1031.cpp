#include<array>
#include<string>
#include<iostream>
#include<cctype>
std::array<std::size_t,17> weight={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
std::array<char,11> verify={'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
    std::size_t n;
    std::cin>>n;
    std::size_t count = 0;
    for(std::size_t i=0;i<n;++i){
        std::string tmp;
        std::cin>>tmp;
        bool flag = true;
        std::size_t sum =0;
        for(std::size_t j=0;j<17;++j){  //前17位
            if(!isdigit(tmp[j])){
                flag=false;
                break;
            }
            sum+=(tmp[j]-'0')*weight[j];
        }
        if(flag==false){
            std::cout<<tmp<<std::endl;
            continue;
        }
        std::size_t z=sum%11;
        if(tmp[17]!=verify[z])
            flag=false;
        if(flag==true){
            ++count;
        }else{
            std::cout<<tmp<<std::endl;
        }
    }
    if(count==n){
        std::cout<<"All passed";
    }
    return 0;
}