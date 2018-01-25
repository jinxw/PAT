#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

class Student{
public:
    Student() = default;
    Student(std::string id):id(id){};
    bool isQualified() const;
    int zongping() const;
    friend bool operator< (const Student &lhs,const Student &rhs);
    friend std::ostream &operator<< (std::ostream &,const Student &);
//private:
    std::string id;
    int biancheng = -1;
    int qizhong = -1;
    int qimo = -1;
};
bool Student::isQualified() const{
    if(this->biancheng>=200&&this->zongping()>=60){
        return true;
    }else{
        return false;
    }
}
int Student::zongping() const{
    return this->qimo>this->qizhong ? this->qimo : round(this->qizhong*0.4+this->qimo*0.6);
}
bool operator< (const Student &lhs,const Student &rhs){
    if(lhs.zongping()!=rhs.zongping()){
        return lhs.zongping()<rhs.zongping();
    }else{
        return lhs.id>rhs.id;
    }
}
std::ostream &operator<< (std::ostream &os,const Student &n){
    os<<n.id<<" "<<n.biancheng<<" "<<n.qizhong<<" "<<n.qimo<<" "<<n.zongping();
    return os;
}

int main(){
    std::size_t p,m,n;
    std::cin>>p>>m>>n;
    std::map<std::string,Student> v;
    for(std::size_t i=0;i<p;++i){
        std::string id;
        int biancheng;
        std::cin>>id>>biancheng;
        v[id].id=id;
        v[id].biancheng=biancheng;
    }
    for(std::size_t i=0;i<m;++i){
        std::string id;
        int qizhong;
        std::cin>>id>>qizhong;
        v[id].id=id;
        v[id].qizhong=qizhong;
    }
    for(std::size_t i=0;i<n;++i){
        std::string id;
        int qimo;
        std::cin>>id>>qimo;
        v[id].id=id;
        v[id].qimo=qimo;
    }
    std::vector<Student> vStudent;
    for(auto &n:v){
        if(n.second.isQualified()){
            vStudent.push_back(n.second);
        }
    }
    std::sort(vStudent.begin(),vStudent.end());
    for(auto it=vStudent.crbegin();it!=vStudent.crend();++it){
        std::cout<<*it<<std::endl;
    }
    return 0;
}