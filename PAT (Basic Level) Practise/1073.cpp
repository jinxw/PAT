#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <tuple>
#include <iomanip>

struct Problem{
    friend std::istream &operator>>(std::istream &, Problem &);
    std::size_t max;
    std::size_t all_num;
    std::size_t true_num;
    std::vector<char> true_answers;
    // std::size_t err_cnt = 0;
    std::vector<std::size_t> err_cnt;   //每个选项的错误次数
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
    double score = 0;
    for(std::size_t i=0;i<vP.size();++i){   //每题
        int status = 2; //0：错 1：半对 2：全对
        for(auto &n:s.answer[i]){   //每个选项
            if(std::find(vP[i].true_answers.begin(),vP[i].true_answers.end(),n)==vP[i].true_answers.end()){
                //cnt
                vP[i].err_cnt[n-'a']++;
                status = 0;
            }
        }
        if(status == 2){
            if(s.answer[i].size() != vP[i].true_num){
                status = 1;
            }
        }
        //计分
        if(status == 1){
            score += 0.5 * vP[i].max;
            for(auto &c:vP[i].true_answers){
                if(std::find(s.answer[i].begin(),s.answer[i].end(),c)==s.answer[i].end()){
                    vP[i].err_cnt[c-'a']++;
                }
            }
        }else if(status == 2){
            score += vP[i].max;
        }else{
            for(auto &c:vP[i].true_answers){
                if(std::find(s.answer[i].begin(),s.answer[i].end(),c)==s.answer[i].end()){
                    vP[i].err_cnt[c-'a']++;
                }
            }
            ;
        }
    }
    std::cout<<std::fixed<<std::setprecision(1)<<score<<std::endl;
    std::cout.unsetf(std::ios::fixed);
    // printf("%.1f\n",score);
}

int main(){
    std::size_t n,m;
    std::cin>>n>>m;
    std::vector<Problem> Problems;
    for(std::size_t i=0;i<m;++i){
        Problem p;
        std::cin>>p;
        p.err_cnt.resize(p.all_num);
        Problems.push_back(p);
    }
    for(std::size_t i=0;i<n;++i){
        Student s;
        std::cin>>s;
        check(s,Problems);
    }
    std::vector<std::tuple<std::size_t, std::size_t, std::size_t>> vErr;
    for(std::size_t tihao=0;tihao!=Problems.size();++tihao){
        for(std::size_t xuanxianghao=0;xuanxianghao!=Problems[tihao].all_num;++xuanxianghao){
            if(Problems[tihao].err_cnt[xuanxianghao]!=0){
                vErr.push_back(std::make_tuple(tihao,xuanxianghao,Problems[tihao].err_cnt[xuanxianghao]));
            }
        }
    }
    if(vErr.size()==0){
        puts("Too simple");
        return 0;
    }
    std::sort(vErr.begin(),vErr.end(),
    [](std::tuple<std::size_t, std::size_t, std::size_t> &lhs,std::tuple<std::size_t, std::size_t, std::size_t> &rhs)->bool{
        if(std::get<2>(lhs)!=std::get<2>(rhs)){
            return std::get<2>(lhs) > std::get<2>(rhs);
        }else if(std::get<0>(lhs)!=std::get<0>(rhs)){
            return std::get<0>(lhs) < std::get<0>(rhs);
        }else {
            return std::get<1>(lhs) < std::get<1>(rhs);
        }
    });
    std::size_t max = std::get<2>(vErr[0]);
    for(auto &n:vErr){
        if(std::get<2>(n) == max)
            printf("%lu %lu-%c\n",std::get<2>(n),std::get<0>(n)+1,std::get<1>(n)+'a');
        // std::cout<<std::get<2>(n)<<std::get<0>(n)<<"-"<<std::get<1>(n)+'a'<<std::endl;
    }
    return 0;
}