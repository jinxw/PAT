#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
struct node{
	int address;
	int data;
	int next;
};
std::list<node> & ReadNode(std::istream &in,std::size_t n){
	std::list<node> ln();
	for(std::size_t i = 0;i<n;i++){
		node tmp;
		in>>tmp.address>>tmp.data>>tmp.next;
		ln.push_back(tmp);
	}
	return ln;
}
void sortLn(std::list<node> ln&, int first_address){
	auto first_iter = find_if(ln.begin(),ln.end(),[first_address](const node n&){n.address == first_address});
	ln.push_front(*first_iter);
	ln.erase(first_iter);
}
void printLn(std::list<node> ln&,int k){
	std::vector<node> vn(ln.begin(),ln.end());
	for_each(vn.begin(),vn.end(),[](const node n&){std::cout<<n.address<<" "<<n.data<<" "<<n.next<<std::endl})
}
int main()
{
	int first_address,n,k;
	std::cin>>first_address>>n>>k;
	auto ln& = ReadNode(cin,n);
	sortLn(ln,first_address);
	printLn(ln,k);
	return 0;
}
