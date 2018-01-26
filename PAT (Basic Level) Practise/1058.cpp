#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

struct Problem{
    friend std::istream &operator>>(std::istream &, Problem &);
    std::size_t max;
    std::size_t all_num;
    std::size_t true_num;
    std::vector<char> true_answers;
    std::size_t err_cnt = 0;
};
std::istream &operator>>(std::istream &is, Problem &p){
    is>>p.max>>p.all_num>>p.true_num;
    char ch;
    while((ch=getchar())!='\n'){
        if(isspace(ch))
            continue;
        p.true_answers.push_back(ch);
    }
    return is;
}

struct Student{
    friend std::istream &operator>>(std::istream &, Student &);
    std::vector<std::vector<char>> answer;  //答题情况
};
std::istream &operator>>(std::istream &is, Student &s){
    std::size_t status=0;   //0:括号外 1：括号内 2：读入选项中
    char ch;
    std::vector<char> v;
    while((ch=getchar())!='\n'){
        if(isspace(ch)){
            continue;
        }
        switch(status){
            case 0:
            if(ch=='('){
                status = 1;
            }
            break;

            case 1:
            if(isdigit(ch)){
                status = 2;
            }
            break;

            case 2:
            if(isalpha(ch)){
                v.push_back(ch);
            }else if(ch == ')'){
                s.answer.push_back(v);
                v.clear();
                status = 0;
            }
            break;
        }
    }
    return is;
}

void check(Student &s, std::vector<Problem> &vP){
    std::size_t score = 0;
    for(std::size_t i=0;i<vP.size();++i){   //每题
        bool status = true;
        if(s.answer[i].size()!=vP[i].true_num){
            status = false;
        }else{
            for(std::size_t j=0;j<vP[i].true_num;++j){
                if(vP[i].true_answers[j]!=s.answer[i][j]){
                    status = false;
                    break;
                }
            }
        }
        if(status){
            score += vP[i].max;
        }else{
            ++vP[i].err_cnt;
        }
    }
    std::cout<<score<<std::endl;
}

int main(){
    std::size_t n,m;
    std::cin>>n>>m;
    std::vector<Problem> Problems;
    for(std::size_t i=0;i<m;++i){
        Problem p;
        std::cin>>p;
        Problems.push_back(p);
    }
    for(std::size_t i=0;i<n;++i){
        Student s;
        std::cin>>s;
        check(s,Problems);
    }
    std::size_t max=0;
    for(auto &p:Problems){
        max = p.err_cnt>max ? p.err_cnt : max;
    }
    if(max == 0){
        std::cout<<"Too simple"<<std::endl;
    }else{
        std::cout<<max;
        for (std::size_t pos = 0; pos < Problems.size(); ++pos){
            if (Problems[pos].err_cnt == max){
                std::cout << " " << pos + 1;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}