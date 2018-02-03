#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> hands,eyes,mouth;

void ReadSymbolSet(std::istream &, std::vector<std::string> &);

class User{
public:
    friend std::istream &operator>>(std::istream &,User &);
    friend std::ostream &operator<<(std::ostream &,User &);
private:
    int left_hand;
    int left_eye;
    int mouth;
    int right_eye;
    int right_hand;
};
std::istream &operator>>(std::istream &is,User &u){
    is>>u.left_hand>>u.left_eye>>u.mouth>>u.right_eye>>u.right_hand;
    return is;
}
std::ostream &operator<<(std::ostream &os,User &u){
    //#2
    if(u.left_hand>hands.size() || u.right_hand>hands.size() || u.left_eye>eyes.size() || u.right_eye>eyes.size() || u.mouth>mouth.size() || u.left_eye < 1 || u.left_hand < 1 || u.mouth < 1 || u.right_eye < 1 || u.right_hand < 1){
        os<<"Are you kidding me? @\\/@";
    }else{
        os<<hands[u.left_hand-1]<<"("<<eyes[u.left_eye-1]<<mouth[u.mouth-1]<<eyes[u.right_eye-1]<<")"<<hands[u.right_hand-1];
    }
    return os;
}

int main(){
    //std::vector<std::string> hands,eyes,mouth;
    ReadSymbolSet(std::cin,hands);
    ReadSymbolSet(std::cin,eyes);
    ReadSymbolSet(std::cin,mouth);
    int k;
    std::cin>>k;
    for(int i=0;i<k;++i){
        User u;
        std::cin>>u;
        std::cout<<u<<std::endl;
    }
}

void ReadSymbolSet(std::istream &is, std::vector<std::string> &v){
    std::string s;
    std::getline(is,s);
    char status = 0;    //0:[]外 1:[]内
    std::string tmp;
    for(const auto &ch:s){
        switch(status){
            case 0:
            if(ch == '['){
                status = 1;
            }
            break;

            case 1:
            if(ch != ']'){
                tmp.push_back(ch);
            }else{
                v.push_back(tmp);
                tmp.clear();
                status = 0;
            }
        }
    }
}