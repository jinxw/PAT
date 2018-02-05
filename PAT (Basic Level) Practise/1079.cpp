#include <iostream>
#include <string>
#include <cmath>

bool isPalindromic(const std::string &);
const std::string reverse(const std::string &);
const std::string add(const std::string &, const std::string &);

int main(){
	std::string s;
	std::cin>>s;
	std::string a = s;
	std::size_t i;
	for(i=0;i<10;++i){
		std::string b = reverse(a);
		std::string c = add(a,b);
		std::cout<<a<<" + "<<b<<" = "<<c<<std::endl;
		if(isPalindromic(c)){
			break;
		}else{
			a = c;
		}
	}
	if(i != 10){
		std::cout<<s<<" is a palindromic number."<<std::endl;
	}else{
		std::cout<<"Not found in 10 iterations."<<std::endl;
	}
	return 0;
}

bool isPalindromic(const std::string &s){
	for(std::size_t pos = 0; pos!=ceil(s.size()*0.5); ++pos){
		if(s[pos] != s[s.size()-pos-1])
			return false;
	}
	return true;
}

const std::string reverse(const std::string &s){
	std::string rs(s.crbegin(),s.crend());
	return rs;
}

const std::string add(const std::string &lhs, const std::string &rhs){
	std::string s;
	int jinwei = 0;
	for(std::size_t pos=0;pos<lhs.size() && pos<rhs.size();++pos){
		int a = lhs[lhs.size()-1-pos] - '0';
		int b = rhs[rhs.size()-1-pos] - '0';
		int sum = a+b+jinwei;
		if(sum>9){
			sum -= 10;
			jinwei = 1;
		}else{
			jinwei = 0;
		}
		s.insert(s.begin(),sum);
	}
	return s;
}

