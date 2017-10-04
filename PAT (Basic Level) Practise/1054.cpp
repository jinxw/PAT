#include<iostream>
#include<string>
#include<cctype> //判断字符
#include<cmath> //fabs
bool isValid(std::string s){
    size_t point=0,decimal=0;
    if(s[0]=='-'){
        s.erase(s.begin());
    }
    for(const auto &c:s){
        if(!isdigit(c)){
            if(c=='.'&&point==0){
                ++point;
            }else{
                return false;
            }
        }else{
            if(point==0){
                continue;
            }else{
                ++decimal;
            }
        }
    }
    if(decimal>2||fabs(std::stod(s))>1000){
        return false;
    }else{
        return true;
    }
}
int main(){
    size_t n;
    std::cin>>n;
    size_t legel=0;
    double sum=0.0;
    for(size_t i=0;i<n;++i){
        std::string s;
        std::cin>>s;
        if(isValid(s)){
            ++legel;
            sum+=std::stod(s);
        }else{
            std::cout<<"ERROR: "<<s<<" is not a legal number"<<std::endl;
        }
    }
    if(legel==0){
        std::cout<<"The average of 0 numbers is Undefined"<<std::endl;
    }else if(legel==1){
        printf("The average of 1 number is %.2f\n",sum);
    }else{
        printf("The average of %d numbers is %.2f\n",legel,sum/legel);
    }
    return 0;
}