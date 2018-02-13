#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct Student{
    friend std::istream &operator>>(std::istream &is,Student &s);
    int id;
    int c;
    int m;
    int e;
    int a;
};
std::istream &operator>>(std::istream &is,Student &s){
    is>>s.id>>s.c>>s.m>>s.e;
    s.a = round((s.c+s.m+s.e)/3.0);
}

int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<Student> vS;
    std::vector<int> score_c;
    std::vector<int> score_m;
    std::vector<int> score_e;
    std::vector<int> score_a;    
    for(int i=0;i<n;++i){
        Student s;
        std::cin>>s;
        vS.push_back(s);
        score_c.push_back(s.c);
        score_m.push_back(s.m);
        score_e.push_back(s.e);
        score_a.push_back(s.a);
    }
    std::sort(score_c.rbegin(),score_c.rend());
    std::sort(score_m.rbegin(),score_m.rend());
    std::sort(score_e.rbegin(),score_e.rend());
    std::sort(score_a.rbegin(),score_a.rend());
    for(int i=0;i<m;++i){
        int check;
        std::cin>>check;
        auto it = std::find_if(vS.begin(),vS.end(),[check](Student &s){return s.id == check;});
        if(it == vS.end()){
            puts("N/A");
        }else{
            auto res = std::find(score_e.begin(),score_e.end(),it->e);  //#2 相同分数名次要并列
            int best_rank = res-score_e.begin()+1;
            char best_course = 'E';
            res = std::find(score_m.begin(),score_m.end(),it->m);
            int rank_m = res-score_m.begin()+1;
            if(rank_m <= best_rank){
                best_rank = rank_m;
                best_course = 'M';
            }
            res = std::find(score_c.begin(),score_c.end(),it->c);
            int rank_c = res-score_c.begin()+1;
            if(rank_c <= best_rank){
                best_rank = rank_c;
                best_course = 'C';
            }
            res = std::find(score_a.begin(),score_a.end(),it->a);
            int rank_a = res-score_a.begin()+1;
            if(rank_a <= best_rank){
                best_rank = rank_a;
                best_course = 'A';
            }
            std::cout<<best_rank<<" "<<best_course<<std::endl;
        }
    }
    return 0;
}