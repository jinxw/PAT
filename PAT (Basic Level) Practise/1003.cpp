#include <iostream>
#include <string>

bool isAC(std::string &);

int main(){
    std::size_t n;
    std::cin >> n;
    for(std::size_t i=0;i<n;++i){
        std::string s;
        std::cin >> s;
        if(isAC(s)){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}

bool isAC(std::string &s){
    std::size_t cnt[3]={0};
    int status = 0;
    for(const auto &ch:s){
        switch(status){
            case 0:
            if(ch == 'A'){
                cnt[0]++;
            }else if(ch == 'P'){
                status = 1;
            }else{
                return false;
            }
            break;

            case 1:
            if(ch == 'A'){
                cnt[1]++;
            }else if(ch == 'T'){
                status = 2;
            }else{
                return false;
            }
            break;

            case 2:
            if(ch == 'A'){
                cnt[2]++;
            }else{
                return false;
            }
            break;
        }
    }
    if (status == 2 && cnt[0]*cnt[1] == cnt[2] && cnt[1] > 0){
        return true;
    }else{
        return false;
    }
}