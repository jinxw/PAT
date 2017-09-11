#include <iostream>
#include <list>
#include <algorithm>
#include <string>
class node{
public:
	node()=default;
	node(int a,int b,int c):address(a),data(b),next(c){};
	friend std::ostream &operator<<(std::ostream &,const node &);
	friend std::istream &operator>>(std::istream &,node &);
	int get_address() const {
		return this->address;
	}
	int get_next() const {
		return this->next;
	}
private:
	int address;
	int data;
	int next;
};
std::ostream &operator<<(std::ostream &os,const node &n){
	std::string s_address(std::to_string(n.address));
	std::string s_next(std::to_string(n.next));
	os<<std::string(5-s_address.size(),'0')+s_address<<" "<<n.data<<" "<<(n.next==-1?"-1":std::string(5-s_next.size(),'0')+s_next);
	return os;
}
std::istream &operator>>(std::istream &is,node &n){
	is>>n.address>>n.data>>n.next;	//没有处理可能失败的情况
	return is;
}

std::list<node>::iterator ln_iter_add (std::list<node>::iterator iter,std::size_t n){
	for(int i=0;i<n;i++){
		++iter;
	}
	return iter;
}

int main()
{
	int first_address,n,k;
	std::cin>>first_address>>n>>k;

	std::list<node> ln;
	for(std::size_t i =0;i<n;i++){
		node tmp(0,0,0);
		std::cin>>tmp;
		ln.push_back(tmp);
	}

	auto iter = ln.end();
	int next_address = -1 ;
	while(iter != ln.begin()){
		auto pre_iter = find_if(ln.begin(),ln.end(),[next_address](const node &n){return n.get_next() == next_address;});
		ln.insert(iter,*pre_iter);
		ln.erase(pre_iter);
		--iter;
		next_address = iter->get_address();
	}
	
	iter = ln.begin();
	for(int j=0;j<n/k;j++){
		for(int i=k-1;i>0;--i){
			auto tmp = ln_iter_add(iter,i);
			ln.insert(iter,*tmp);
			ln.erase(tmp);
		}
		++iter;
	}

	for(auto &n:ln){
		std::cout<<n<<std::endl;
	}
	std::cout<<std::flush;

	return 0;
}
