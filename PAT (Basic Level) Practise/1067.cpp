#include<iostream>
#include<string>
int main(){
    std::string correct_passwd;
    size_t n;
    std::cin>>correct_passwd>>n;
    getchar();
    size_t try_times=0;
    while(1){
        std::string tmp;
        std::getline(std::cin,tmp);    //错误密码可能有空格
        if(tmp=="#"){
            break;
        }else{
            if(tmp==correct_passwd){
                std::cout<<"Welcome in"<<std::endl;
                break;
            }else{
                std::cout<<"Wrong password: "<<tmp<<std::endl;
                if(++try_times==n){
                    std::cout<<"Account locked"<<std::endl;
                    break;
                }
            }
        }
    }
    return 0;
}