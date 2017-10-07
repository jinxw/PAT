#include<iostream>
#include<vector>
#include<set>
size_t My_find(std::vector<size_t> &,size_t &);
bool isPrime(int);
int main(){
    size_t n;
    std::cin>>n;
    std::vector<size_t> ranking;
    for(size_t i=0;i<n;++i){
        size_t id;
        std::cin>>id;
        ranking.push_back(id);
    }
    size_t k;
    std::cin>>k;
    std::set<size_t> check;
    for(size_t i=0;i<k;++i){
        size_t id;
        std::cin>>id;
        int pos = My_find(ranking,id);
        if(pos != 0){
            if(check.find(id)!=check.end()){
                printf("%04d: Checked\n",id);
            }else{
                check.insert(id);
                if(pos==1){
                    //冠军
                    printf("%04d: Mystery Award\n",id);
                }else if(isPrime(pos)){
                    //素数
                    printf("%04d: Minion\n",id);
                }else{
                    //其他
                    printf("%04d: Chocolate\n",id);
                }
            }
        }else{
            printf("%04d: Are you kidding?\n",id);
        }
    }
    return 0;
}
size_t My_find(std::vector<size_t> &v,size_t &n){
    for(size_t i=0;i<v.size();++i){
        if(v[i]==n){
            return i+1;
        }
    }
    return 0;
}
bool isPrime(int n){
    for(size_t i=2;i*i<=n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}