#include<iostream>
//#include<cstdio>
#include<vector>
#include<algorithm>
int main(){
    std::size_t n;
    long long p;
    std::cin>>n>>p;
    std::vector<long long> vn;
    for(std::size_t i=0;i<n;++i){
        long long tmp;
        std::cin>>tmp;
        vn.push_back(tmp);
    }
    std::sort(vn.begin(),vn.end()); //按从小到大排序

    auto min_iter = vn.begin();
    std::size_t max = 1;
    while(true){
        auto min = *min_iter;
        auto first_big_iter = std::find_if(vn.begin(),vn.end(),[min,p](const long long &n){return n>min*p;});   //这里还可以优化，自己用迭代器来找
        std::size_t num = first_big_iter - min_iter;
        std::cout<<num<<std::endl;  //test
        max = num>max?num:max;
        ++min_iter;
        if(first_big_iter==vn.end()||vn.end()-min_iter<=max)
            break;
    }
    std::cout<<max<<std::endl;
    return 0;
}