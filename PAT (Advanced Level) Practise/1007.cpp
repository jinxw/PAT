#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <climits>

std::tuple<std::size_t, std::size_t, int> find_maximum_subarray(std::vector<int> &v,std::size_t low,std::size_t high);
std::tuple<std::size_t, std::size_t, int> find_max_crossing_subarray(std::vector<int> &v,std::size_t low,std::size_t mid,std::size_t high);

int main(){
    std::size_t k;
    std::cin>>k;
    std::vector<int> v;
    for(std::size_t i=0;i<k;++i){
        int tmp;
        std::cin>>tmp;
        v.push_back(tmp);
    }
    //最大子数组问题
    auto res = find_maximum_subarray(v,0,v.size()-1);
    if(std::get<2>(res) < 0)
        std::cout<<"0"<<" "<<v.front()<<" "<<v.back()<<std::endl;   //#4
    else
        std::cout<<std::get<2>(res)<<" "<<v[std::get<0>(res)]<<" "<<v[std::get<1>(res)]<<std::endl;
    return 0;
}

std::tuple<std::size_t, std::size_t, int> find_maximum_subarray(std::vector<int> &v,std::size_t low,std::size_t high){
    if(high == low)
        return std::make_tuple(low,high,v[low]);
    else{
        std::size_t mid = floor((low+high)*0.5);
        auto left = find_maximum_subarray(v,low,mid);
        auto right = find_maximum_subarray(v,mid+1,high);
        auto cross = find_max_crossing_subarray(v,low,mid,high);
        if(std::get<2>(left)>=std::get<2>(right) && std::get<2>(left)>= std::get<2>(cross))
            return left;
        else if(std::get<2>(right)>=std::get<2>(left) && std::get<2>(right)>=std::get<2>(cross))
            return right;
        else
            return cross;
    }
}

std::tuple<std::size_t, std::size_t, int> find_max_crossing_subarray(std::vector<int> &v,std::size_t low,std::size_t mid,std::size_t high){
    int left_sum = INT_MIN;
    int max_left;
    int sum = 0;
    for(int i=mid;i>=(int)low;--i){ //注意有符号数与无符号数的比较
        sum += v[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    int max_right;
    sum = 0;
    for(int j=mid+1;j<=(int)high;++j){
        sum += v[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return std::make_tuple(max_left,max_right,left_sum+right_sum);
}