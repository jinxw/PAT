#include <iostream>
#include <string>
#include <cmath>

class BigNumber{
public:
	BigNumber() = default;
	BigNumber(const std::string &str):s(str){};
	bool isPalindromic();
	const BigNumber reverse() const;
	const BigNumber operator+(const BigNumber &);
	friend std::istream &operator>>(std::istream &,BigNumber &);
	friend std::ostream &operator<<(std::ostream &,const BigNumber &);
private:
	std::string s;
};
bool BigNumber::isPalindromic(){
	for(std::size_t pos = 0; pos!=ceil(this->s.size()*0.5); ++pos){
		if(this->s[pos] != this->s[this->s.size()-pos-1])
			return false;
	}
	return true;
}
const BigNumber BigNumber::reverse() const{
	std::string rs(this->s.crbegin(),this->s.crend());
	BigNumber rb(rs);
	return rb;
}
const BigNumber BigNumber::operator+(const BigNumber &rhs){
	std::string s;
	int jinwei = 0;
	for(std::size_t pos=0;pos<this->s.size() && pos<rhs.s.size();++pos){
		int a = this->s[this->s.size()-1-pos] - '0';
		int b = rhs.s[rhs.s.size()-1-pos] - '0';
		int sum = a+b+jinwei;
		if(sum>9){
			sum -= 10;
			jinwei = 1;
		}else{
			jinwei = 0;
		}
		s.insert(s.begin(),sum+'0');
	}
	if(jinwei == 1){
		s.insert(s.begin(),'1');
	}
	BigNumber sum(s);
	return sum;
}
std::istream &operator>>(std::istream &is,BigNumber &bn){
	is>>bn.s;
	return is;
}
std::ostream &operator<<(std::ostream &os,const BigNumber &bn){
	//os<<bn.s.substr(bn.s.find_first_not_of('0'));	//开头的0不需要去掉
	os<<bn.s;
	return os;
}

int main(){
	BigNumber a;
	std::cin>>a;
	std::size_t i;
	for(i=0;i<10 && !a.isPalindromic();++i){
		BigNumber b = a.reverse();
		BigNumber c = a+b;
		std::cout<<a<<" + "<<b<<" = "<<c<<std::endl;
		a = c;
	}
	if(i != 10){
		std::cout<<a<<" is a palindromic number."<<std::endl;
	}else{
		std::cout<<"Not found in 10 iterations."<<std::endl;
	}
	return 0;
}