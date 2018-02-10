#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

class Time{
public:
    Time() = default;
    Time(const std::string &s){
        std::stringstream ss(s);
        ss>>*this;
    }
    bool operator<(const Time &rhs);
    friend std::istream &operator>>(std::istream &is,Time &t);
private:
    int h;
    int m;
    int s;
};
bool Time::operator<(const Time &rhs){
    if(this->h != rhs.h){
        return this->h < rhs.h;
    }else if(this->m != rhs.m){
        return this->m < rhs.m;
    }else{
        return this->s < rhs.s;
    }
}
std::istream &operator>>(std::istream &is,Time &t){
    char ch;
    is>>t.h>>ch>>t.m>>ch>>t.s;
    return is;
}

int main(){
    std::size_t m;
    std::cin>>m;
    std::string first_ID,last_ID;
    Time first_time("23:59:59");
    Time last_time("00:00:00");
    for(std::size_t i=0;i<m;++i){
        std::string id;
        Time sign_in,sign_out;
        std::cin>>id>>sign_in>>sign_out;
        if(sign_in < first_time){
            first_time = sign_in;
            first_ID = id;
        }
        if(last_time < sign_out){
            last_time = sign_out;
            last_ID = id;
        }
    }
    std::cout<<first_ID<<" "<<last_ID<<std::endl;
    return 0;
}