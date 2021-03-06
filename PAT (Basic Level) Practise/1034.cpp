#include <iostream>

long long gcd(long long t1, long long t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

class Fraction{
public:
    Fraction() = default;
    Fraction(long long n,long long m):n(n),m(m){};
    const Fraction operator+(const Fraction &) const;
    const Fraction operator-(const Fraction &) const;
    const Fraction operator*(const Fraction &) const;
    const Fraction operator/(const Fraction &) const;
    friend std::istream &operator>>(std::istream &,Fraction &);
    friend std::ostream &operator<<(std::ostream &,const Fraction &);
    void toIrreducible();
	bool isZero();
private:
    int minus = 1;  //1正 -1负 
    long long n;
    long long m;
};
const Fraction Fraction::operator+(const Fraction &rhs) const{
    Fraction sum;
    sum.n = this->minus*this->n*rhs.m + this->m*rhs.n*rhs.minus;
    sum.m = this->m*rhs.m;
    if(sum.n < 0){
        sum.n *= -1;
        sum.minus = -1;
    }
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
    res.n = this->n*rhs.n;
    res.m = this->m * rhs.m;
    res.toIrreducible();
    return res;
}
const Fraction Fraction::operator/(const Fraction &rhs) const{
    Fraction tmp(rhs.m,rhs.n);
    tmp.minus = rhs.minus;
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
	if(f.n == 0){
		os<<"0";
		return os;
	}
    if(f.minus == -1)
        os<<"(-";
    if(f.n/f.m != 0){
        os<<f.n/f.m;
        if(f.n%f.m!=0){
            os<<" ";
        }
    }
    if(f.n%f.m!=0)
        os<<f.n%f.m<<"/"<<f.m;
    if(f.minus == -1)
        std::cout<<")";
    return os;
}
void Fraction::toIrreducible(){
    long long i = gcd(this->m,this->n);
    this->n /= i;
    this->m /= i;
}
bool Fraction::isZero(){
	if(this->n == 0)
		return true;
	else
		return false;
}

int main(){
    Fraction a,b;
    std::cin>>a>>b;
    a.toIrreducible();
    b.toIrreducible();
    std::cout<<a<<" + "<<b<<" = "<<a+b<<std::endl;
    std::cout<<a<<" - "<<b<<" = "<<a-b<<std::endl;
    std::cout<<a<<" * "<<b<<" = "<<a*b<<std::endl;
	if(b.isZero())
    	std::cout<<a<<" / "<<b<<" = "<<"Inf"<<std::endl;
	else
		std::cout<<a<<" / "<<b<<" = "<<a/b<<std::endl;
    return 0;
}