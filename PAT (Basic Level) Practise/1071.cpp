#include<iostream>
int main(){
    size_t chips,k;
    std::cin>>chips>>k;
    for(size_t i=0;i<k;++i){
        size_t n1,b,t,n2;
        std::cin>>n1>>b>>t>>n2;
        if(t>chips){
            std::cout<<"Not enough tokens.  Total = "<<chips<<"."<<std::endl;  
            continue;          
        }
        if(b==1&&n2>n1||b==0&&n2<n1){
            chips+=t;
            printf("Win %d!  Total = %d.\n",t,chips);
        }else{
            chips-=t;
            printf("Lose %d.  Total = %d.\n",t,chips);
            if(chips==0){
                printf("Game Over.\n");
                break;
            }
        }
    }
    return 0;
}