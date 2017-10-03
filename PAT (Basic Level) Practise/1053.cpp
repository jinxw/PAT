#include<iostream>
int main(){
    size_t n,d;
    double e;
    std::cin>>n>>e>>d;
    size_t may_empty=0,empty=0;
    for(size_t i=0;i<n;++i){
        size_t k,count=0;
        double electricity;
        std::cin>>k;
        for(size_t j=0;j<k;++j){
            std::cin>>electricity;
            if(electricity<e){
                ++count;
            }
        }
        if(2*count>k){
            ++may_empty;
            if(k>d){
                --may_empty;
                ++empty;
            }
        }
    }
    printf("%.1f\%% %.1f%%\n",static_cast<double>(may_empty)/n*100,static_cast<double>(empty)/n*100);
    return 0;
}