#include<iostream>
#include<map>
#include<utility>
int main(){
    std::ios::sync_with_stdio(false);
    size_t n;
    std::cin>>n;
    std::map<size_t,size_t> school_score;
    size_t school_number,stu_mark;
    for(size_t i =0;i<n;++i){
        std::cin>>school_number>>stu_mark;
        school_score[school_number]+=stu_mark;
    }
    std::pair<size_t,size_t> max;
    for(const auto &s:school_score){
        if(s.second>max.second){
            max.second = s.second;
            max.first = s.first;
        }
    }
    std::cout<<max.first<<" "<<max.second<<std::endl;
}