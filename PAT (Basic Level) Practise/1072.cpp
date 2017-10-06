#include<iostream>
#include<set>
#include<string>
int main(){
    size_t n,m;
    std::cin>>n>>m;
    std::set<size_t> search;
    size_t problem_stu = 0;
    size_t problem_thing = 0;
    for(size_t i=0;i<m;++i){
        size_t tmp;
        std::cin>>tmp;
        search.insert(tmp);
    }
    for(size_t i=0;i<n;++i){
        std::string name;
        size_t k;
        std::cin>>name>>k;
        bool problem = false;
        for(size_t j=0;j<k;++j){
            size_t thing;
            std::cin>>thing;
            if(search.find(thing)!=search.end()){
                ++problem_thing;
                if(problem == false){
                    problem = true;
                    ++problem_stu;
                    std::cout<<name<<":";
                }
                printf(" %04d",thing);
            }
        }
        if(problem==true){
            std::cout<<std::endl;
        }
    }
    std::cout<<problem_stu<<" "<<problem_thing<<std::endl;
    return 0;
}