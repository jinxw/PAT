#include <iostream>
#include <cstdio>
#include <utility>

class Fraction{
public:
    Fraction() = default;
    Fraction(int n,int m):n(n),m(m){};
    friend std::istream &operator>>(std::istream &,Fraction &);
    friend std::ostream &operator<<(std::ostream &,const Fraction &);
    friend bool operator<(const Fraction &,const Fraction &);
    friend bool operator==(const Fraction &,const Fraction &);
    bool isIrreducible();
private:
    int n;
    int m;
};
std::istream &operator>>(std::istream &is,Fraction &f){
    is>>f.n;
    getchar();
    is>>f.m;
    return is;
}
std::ostream &operator<<(std::ostream &os,const Fraction &f){
    os<<f.n<<"/"<<f.m;
    return os;
}
bool operator<(const Fraction &lhs,const Fraction &rhs){
    return lhs.n*rhs.m < lhs.m*rhs.n;
}
bool operator==(const Fraction &lhs,const Fraction &rhs){
    return lhs.n*rhs.m == lhs.m*rhs.n;
}
bool Fraction::isIrreducible(){
    for(int i=2;i<=this->n;++i){    //可优化
        if(this->n%i==0 && this->m%i==0)
            return false;
    }
    return true;
}

int main(){
    Fraction floor,ceil;
    int k;
    std::cin>>floor>>ceil>>k;
    if(ceil<floor){ //#1
        std::swap(ceil,floor);
    }
    bool first = true;
    for(int i=1;;++i){
        Fraction f(i,k);
        if(ceil<f || ceil==f){  //#2
            break;
        }else if(f<floor || f==floor){
            continue;
        }else if(f.isIrreducible()){
            if(!first){
                std::cout<<" ";
            }
            std::cout<<f;
            first = false;
        }else{
            continue;
        }
    }
    std::cout<<std::endl;
    return 0;
}