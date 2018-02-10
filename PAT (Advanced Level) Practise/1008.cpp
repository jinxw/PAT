#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int current = 0;
    int next;
    int total = 0;
    for(int i=0;i<n;++i){
        std::cin>>next;
        int differ = next - current;
        if(differ>0){
            total += differ*6+5;
        }else if(differ<0){
            total += (-differ)*4+5;
        }else{
            total += 5; //#2,3,6
        }
        current = next;
    }
    std::cout<<total<<std::endl;
    return 0;
}