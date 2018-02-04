#include <iostream>

class Fraction{
public:
    Fraction() = default;
    Fraction(int n,int m):n(n),m(m){};
    const Fraction operator+(const Fraction &) const;
    const Fraction operator-(const Fraction &) const;
    const Fraction operator*(const Fraction &) const;
    const Fraction operator/(const Fraction &) const;
    friend std::istream &operator>>(std::istream &,Fraction &);
    friend std::ostream &operator<<(std::ostream &,const Fraction &);
    void toIrreducible();
private:
    int minus = 1;  //1正 -1负 
    int k = 0;
    int n;
    int m;
};
const Fraction Fraction::operator+(const Fraction &rhs) const{
    Fraction sum;
    sum.n = this->minus*(this->k*this->m + this->n)*rhs.m + this->m*(rhs.n + rhs.k*rhs.m)*rhs.minus;
    sum.m = this->m*rhs.m;
    sum.toIrreducible();
    return sum;
}
const Fraction Fraction::operator-(const Fraction &rhs) const{
    Fraction tmp(rhs);
    tmp.minus*=-1;
    return this->operator+(tmp);
}
const Fraction Fraction::operator*(const Fraction &rhs) const{
    Fraction res;
    res.minus = this->minus * rhs.minus;
    res.n = (this->k*this->m + this->n)*(rhs.k*rhs.m + rhs.n);
    res.m = this->m * rhs.m;
    res.toIrreducible();
    return res;
}
const Fraction Fraction::operator/(const Fraction &rhs) const{
    Fraction tmp(rhs);
    tmp.n += tmp.k*tmp.m;
    std::swap(tmp.n,tmp.m);
    tmp.k = 0;
    tmp.toIrreducible();
    return this->operator*(tmp);
}
std::istream &operator>>(std::istream &is,Fraction &f){
    is>>f.n;
    getchar();
    is>>f.m;
    if(f.n < 0){
        f.n *= -1;
        f.minus = -1;
    }
    return is;
}
std::ostream &operator<<(std::ostream &os,const Fraction &f){
    if(f.minus == -1)
        std::cout<<"(-";
    if(f.k!=0){
        std::cout<<f.k;
        if(f.n!=0){
            std::cout<<" ";
        }
    }
    if(f.n!=0)
        os<<f.n<<"/"<<f.m;
    if(f.minus == -1)
        std::cout<<")";
    return os;
}
void Fraction::toIrreducible(){
    this->k += this->n / this->m;
    this->n %= this->m;
    for(int i=this->n;i>=2;--i){    //可优化
        if(this->n%i==0 && this->m%i==0){
            this->n /= i;
            this->m /= i;
            break;
        }
    }
}

int main(){
    Fraction a,b;
    std::cin>>a>>b;
    a.toIrreducible();
    b.toIrreducible();
    std::cout<<a<<" + "<<b<<" = "<<a+b<<std::endl;
    std::cout<<a<<" - "<<b<<" = "<<a-b<<std::endl;
    std::cout<<a<<" * "<<b<<" = "<<a*b<<std::endl;
    std::cout<<a<<" / "<<b<<" = "<<a/b<<std::endl;
    return 0;
}