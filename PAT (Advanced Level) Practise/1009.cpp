#include <iostream>
#include <map>
#include <iomanip>

class Polynomials{
public:
    const Polynomials operator+(const Polynomials &rhs) const;
    const Polynomials operator*(const Polynomials &rhs) const;
    friend std::istream &operator>>(std::istream &is,Polynomials &p);
    friend std::ostream &operator<<(std::ostream &os,const Polynomials &p);
private:
    int k;
    std::map<int,double> n;
};
const Polynomials Polynomials::operator+(const Polynomials &rhs) const{
    Polynomials sum(*this);
    for(auto &n:rhs.n){
        sum.n[n.first] += n.second;
        if(sum.n[n.first]==0)
            sum.n.erase(n.first);
    }
    sum.k = sum.n.size();
    return sum;
}
const Polynomials Polynomials::operator*(const Polynomials &rhs) const{
    
}
std::istream &operator>>(std::istream &is,Polynomials &p){
    is>>p.k;
    for(int i=0;i<p.k;++i){
        int n;
        double a;
        is>>n>>a;
        p.n[n] = a;
    }
    return is;
}
std::ostream &operator<<(std::ostream &os,const Polynomials &p){
    os<<p.k;
    for(auto it=p.n.crbegin();it!=p.n.crend();++it){
        os<<std::fixed<<std::setprecision(1)<<" "<<it->first<<" "<<it->second;
    }
    return os;
}