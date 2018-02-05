#include <iostream>
#include <string>
#include <cmath>

bool isPalindromic(std::string &);
std::string & reverse(std::string &);
std::string & add(std::string &, std::string &);

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

bool isPalindromic(std::string &s){
	for(std::size_t pos = 0; pos!=ceil(s.size()*0.5); ++pos){
		if(s[pos] != s[s.size()-pos-1])
			return false;
	}
	return true;
}

std::string & reverse(std::string &)