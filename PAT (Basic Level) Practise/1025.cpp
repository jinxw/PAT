#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class node{
public:
	node()=default;
	friend ostream &operator<<(ostream &,const node &);
	friend istream &operator>>(ostream &,node &);
private:
	int address;
	int data;
	int next;
};
std::ostream &operator<<(ostream &os,const node &n){
	os<<n.address<<" "<<n.data<<" "<<n.next;
	return os;
}
std::istream &operator>>(istream &is,node &n){
	is>>n.address>>n.data>>n.next;	//没有处理可能失败的情况
	return is;
}
// std::list<node> &ReadNode(std::istream &in,std::size_t n){
// 	std::list<node> ln();
// 	for(std::size_t i = 0;i<n;i++){
// 		node tmp;
// 		in>>tmp;
// 		ln.push_back(tmp);
// 	}
// 	return ln;
// }
// void sortLn(std::list<node> ln&, int first_address){
// 	auto first_iter = find_if(ln.begin(),ln.end(),[first_address](const node n&){n.address == first_address});
// 	ln.push_front(*first_iter);
// 	ln.erase(first_iter);
// }
// void printLn(std::list<node> &ln,int k){
// 	for_each(ln.begin(),ln.end(),[](const node &n){std::cout<<n<<std::endl});
// 	// std::vector<node> vn(ln.begin(),ln.end());
// 	// for_each(vn.begin(),vn.end(),[](const node n&){std::cout<<n.address<<" "<<n.data<<" "<<n.next<<std::endl})
// }
int main()
{
	int first_address,n,k;
	std::cin>>first_address>>n>>k;
	// auto ln = ReadNode(std::cin,n);
	// sortLn(ln,first_address);
	// std::list<node> ln = {node(1000,1,1001)};
	// printLn(ln,k);
	node tmp();
	std::cin>>tmp;
	std::cout<<tmp;
	return 0;
}
