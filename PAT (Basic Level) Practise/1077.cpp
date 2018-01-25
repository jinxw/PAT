#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
int main(){
    std::size_t n,m;
    std::cin>>n>>m;
    for(std::size_t i=0;i<n;++i){
        double teacher;
        std::cin>>teacher;
        std::vector<double> other;
        for(std::size_t j=0;j<n-1;++j){
            double tmp;
            std::cin>>tmp;
            if(tmp<0||tmp>m){
                continue;
            }
            other.push_back(tmp);
        }
        std::sort(other.begin(),other.end());
        double other_sum=0;
        for(std::size_t pos=1;pos<other.size()-1;++pos){
            other_sum+=other[pos];
        }
        std::cout<<round((teacher + other_sum/(other.size()-2))/2)<<std::endl;
    }
    return 0;
}