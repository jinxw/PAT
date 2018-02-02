#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    int k;
    std::cin>>k;
    std::vector<int> num(k);
    for(int i=0;i<k;++i){
        std::cin>>num[i];
    }
    std::sort(num.rbegin(),num.rend());
    double m = ceil(pow(k,0.5));
    double n = k/m;
    while((n - floor(n)) != 0){
        ++m;
        n = k/m;
    }
    std::vector<std::vector<int>> mat(m,std::vector<int>(n));
    int status = 0; //0,1,2,3
    int x = 0;
    int y = 0;
    int right = n-1;
    int ceil = 1;
    int floor = m-1;
    int left = 0;
    for(auto it=num.cbegin();it!=num.cend();++it){
        mat[x][y] = *it;
        switch(status){
            case 0:
            if(y!=right){
                ++y;
            }else{
                status = 1;
                ++x;
                --right;
            }
            break;

            case 1:
            if(x!=floor){
                ++x;
            }else{
                status = 2;
                --y;
                --floor;
            }
            break;

            case 2:
            if(y!=left){
                --y;
            }else{
                status = 3;
                --x;
                ++left;
            }
            break;

            case 3:
            if(x!=ceil){
                --x;
            }else{
                status = 0;
                ++y;
                ++ceil;
            }
        }
    }
    for(auto &row:mat){
        for(auto it=row.cbegin();it!=row.cend();++it){
            if(it!=row.cbegin()){
                std::cout<<" ";
            }
            std::cout<<*it;
        }
        std::cout<<std::endl;
    }
    return 0;
}