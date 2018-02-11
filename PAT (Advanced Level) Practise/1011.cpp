#include <iostream>
#include <cstdio>
#include <array>

int main(){
    std::array<std::array<double,3>,3> arr;
    std::array<int,3> flag;
    std::array<char,3> wtl{'W','T','L'};
    double res = 1.0;
    for(std::size_t i=0;i<3;++i){
        double max = 0.0;
        for(std::size_t j=0;j<3;++j){
            std::cin>>arr[i][j];
            if(arr[i][j]>max){
                max = arr[i][j];
                flag[i] = j;
            }
        }
        res *= max;
        std::cout<<wtl[flag[i]]<<" ";
    }
    res = (res*0.65-1)*2.0;
    printf("%.2f\n",res);   //不用+0.005
    return 0;
}