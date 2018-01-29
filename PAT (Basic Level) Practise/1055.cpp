#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person{
    std::string name;
    int height;
};

int main(){
    int n,k;
    std::cin>>n>>k;
    std::vector<Person> People;
    People.resize(n);
    for(int i=0;i<n;++i){
        std::cin>>People[i].name>>People[i].height;
    }
    std::sort(People.begin(), People.end(), [](Person &lhs,Person &rhs)->bool{
        if(lhs.height!=rhs.height){
            return lhs.height < rhs.height;
        }else{
            return lhs.name > rhs.name;
        }
    });
    for(int i=0;i<k;++i){
        int length = i==0 ? n/k+n%k : n/k;
        int now = i==0 ? n-n/k-n%k : n-n%k-(i+1)*(n/k);
        if(length%2 == 1 && length!=1){
            now += 1;
        }
        bool left = true; //true:+2/+1 false:-2
        for(int j=0;j<length;++j){
            if(j!=0)
                std::cout<<" ";
            std::cout<<People[now].name;
            if(left){
                if(j==length/2-1){
                    now += 1;
                    left = false;
                }else{
                    now += 2;
                }
            }else{
                now -= 2;
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}