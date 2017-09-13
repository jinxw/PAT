#include <iostream>
#include <vector>
#include <algorithm>
class person{
public:
    person() = default;
    person(std::size_t y,std::size_t m,std::size_t d):year(y),month(m),day(d){};
    friend bool operator< (const person &lhs,const person &rhs);
    friend std::istream &operator>> (std::istream &,person &);
    friend std::ostream &operator<< (std::ostream &,const person &);
    bool isValid() const{
        if(*this<person(1814,9,6)||person(2014,9,6)<*this){
            return false;
        }else{
            return true;
        }
    }
    std::string getName() const {
        return name;
    }
private:
    std::string name = "null" ;
    std::size_t year;
    std::size_t month;
    std::size_t day;
};
bool operator< (const person &lhs,const person &rhs){
    if(lhs.year!=rhs.year){
        return lhs.year<rhs.year;
    }else if(lhs.month!=rhs.month){
        return lhs.month < rhs.month;
    }else{
        return lhs.day<rhs.day;
    }
}
std::istream &operator>> (std::istream &is,person &n){
    char tmp;
    is >> n.name >> n.year >> tmp >> n.month >> tmp >> n.day;
    return is;
}
std::ostream &operator<< (std::ostream &os,const person &n){
    os << n.name << " " << n.year<<"/"<<n.month<<"/"<<n.day;
    return os;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::size_t n;
    std::cin >> n;
    std::vector<person> people;
    for(std::size_t i=0;i<n;++i){
        person tmp;
        std::cin>>tmp;
        if(tmp.isValid()){
            people.push_back(tmp);
        }
    }
    std::sort(people.begin(),people.end());
    if (people.size()){
        std::cout<<people.size()<<" "<<people.front().getName()<<" "<<people.back().getName();
    }else{
        std::cout<<"0"; //测试点3
    }
    return 0;
}