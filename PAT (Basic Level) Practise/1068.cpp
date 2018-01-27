#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <math.h>

int main(){
    int m,n,tol;
    std::cin>>m>>n>>tol;
    std::vector<std::vector<std::pair<int,bool>>> color(n,std::vector<std::pair<int,bool>>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            std::cin>>color[i][j].first;
            color[i][j].second = true;
            if(i!=0 && j!=0 && fabs(color[i-1][j-1].first-color[i][j].first)<=tol){
                color[i-1][j-1].second = false;
                color[i][j].second = false;
            }
            if(i!=0 && fabs(color[i-1][j].first-color[i][j].first)<=tol){
                color[i-1][j].second = false;
                color[i][j].second = false;
            }
            if(j!=0 && fabs(color[i][j-1].first-color[i][j].first)<=tol){
                color[i][j-1].second = false;
                color[i][j].second = false;
            }
            if(i!=0 && j!=m-1 && fabs(color[i-1][j+1].first-color[i][j].first)<=tol){
                color[i-1][j+1].second = false;
                color[i][j].second = false;
            }
        }
    }
    std::map<int,int> big_point;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(color[i][j].second){
                big_point[color[i][j].first]++;
            }
        }
    }
    int unique_color_cnt = 0;
    int last_unique_color;
    for(auto &p:big_point){
        if(p.second == 1){
            unique_color_cnt++;
            last_unique_color = p.first;
        }
    }
    if(unique_color_cnt == 0){
        puts("Not Exist");
    }else if(unique_color_cnt > 1){
        puts("Not Unique");
    }else{
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(color[i][j].first == last_unique_color){
                    printf("(%d, %d): %d\n",j+1,i+1,last_unique_color);
                }
            }
        }
    }
    return 0;
}