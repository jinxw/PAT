#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<cctype>
int main(){
    std::string true_string,false_string;
    std::set<char> wrong_key;
    std::cin>>true_string>>false_string;
    for(auto c:true_string){
        auto wc = std::find(false_string.begin(),false_string.end(),c);
        c=toupper(c);
        if(wc==false_string.end()&&wrong_key.find(c)==wrong_key.end()){
            std::cout<<c;
            wrong_key.insert(c);
        }
    }
    std::cout<<std::endl;
    return 0;
}