#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
int main(){
    size_t n;
    std::cin>>n;
    std::map<size_t,size_t> wife;
    std::map<size_t,size_t> husbnd;
    for(size_t i=0;i<n;++i){
        size_t male,female;
        std::cin>>male>>female;
        wife[male]=female;
        husbnd[female]=male;
    }

    size_t m;
    std::cin>>m;
    std::vector<size_t> guests;
    for(size_t i=0;i<m;++i){
        size_t guest;
        std::cin>>guest;
        guests.push_back(guest);
    }

    std::vector<size_t> single_dog;
    for(const auto &guest:guests){
        if(wife.find(guest)!=wife.end()){
            if(find(guests.cbegin(),guests.cend(),wife[guest])==guests.end()){
                single_dog.push_back(guest);
            }
        }else if(husbnd.find(guest)!=husbnd.end()){
            if(find(guests.cbegin(),guests.cend(),husbnd[guest])==guests.end()){
                single_dog.push_back(guest);
            }
        }else{
            single_dog.push_back(guest);
        }
    }

    std::sort(single_dog.begin(),single_dog.end());
    std::cout<<single_dog.size()<<std::endl;
    if(single_dog.size()==0){
        return 0;
    }
    bool begin=true;
    for(const auto &n:single_dog){
        if(begin==false){
            std::cout<<" ";
        }
        printf("%05d",n);
        begin=false;
    }
    std::cout<<std::endl;
    return 0;
}