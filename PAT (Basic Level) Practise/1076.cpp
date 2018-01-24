#include <iostream>
#include <string>
int main(){
    std::size_t n;
    std::cin>>n;
    std::string passwd;
    for(std::size_t i=0;i<n;++i){
        for(std::size_t j=0;j<4;++j){
            std::string tmp;
            std::cin>>tmp;
            if(tmp[2]=='T'){
                switch(tmp[0]){
                    case 'A':
                    passwd+='1';
                    break;

                    case 'B':
                    passwd+='2';
                    break;

                    case 'C':
                    passwd+='3';
                    break;

                    case 'D':
                    passwd+='4';
                    break;
                }
            }
        }
    }
    std::cout<<passwd<<std::endl;
    return 0;
}