#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    size_t n;
    std::cin>>n;
    std::vector<size_t> ride;
    for(size_t i=0;i<n;++i){
        size_t tmp;
        std::cin>>tmp;
        ride.push_back(tmp);
    }
    std::sort(ride.begin(),ride.end());
    size_t e=n;
    for(size_t i=0;i<n;++i){
        if(ride[i]>e){
            break;
        }else{
            --e;
        }
    }
    std::cout<<e<<std::endl;
    return 0;
}