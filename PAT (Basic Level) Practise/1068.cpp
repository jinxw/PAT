#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <array>
#include <cmath>

bool check_tol(std::pair<int,int> &,std::vector<std::vector<int>> &,int);

int main(){
    int m,n,tol;
    scanf("%d%d%d",&m,&n,&tol);
    std::vector<std::vector<int>> color(n,std::vector<int>(m));
    std::map<int,std::pair<int,int>> color2coor;    //快速通过颜色找到坐标
    std::map<int,int> color_cnt;    //记录颜色出现次数
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&color[i][j]);
            color2coor[color[i][j]] = std::make_pair(i,j);
            color_cnt[color[i][j]]++;
        }
    }
    std::vector<int> v;
    for(const auto &c:color_cnt){
        if(c.second == 1){
            if(check_tol(color2coor[c.first],color,tol)){
                v.push_back(c.first);
            }
        }
    }
    if(v.size()==0){
        puts("Not Exist");
    }else if(v.size()>1){
        puts("Not Unique");
    }else{
        printf("(%d, %d): %d\n",color2coor[v[0]].second+1,color2coor[v[0]].first+1,v[0]);
    }
    return 0;
}

bool check_tol(std::pair<int,int> &coor,std::vector<std::vector<int>> &color,int tol){
    const auto &x = coor.first;
    const auto &y = coor.second;
    //也可用一个[8][2]的数组来写
    if(x!=0 && y!=0 && abs(color[x][y]-color[x-1][y-1])<=tol){
        return false;
    }
    if(x!=0 && abs(color[x][y]-color[x-1][y])<=tol){
        return false;
    }
    if(x!=0 && y!=color[0].size()-1 && abs(color[x][y]-color[x-1][y+1])<=tol){
        return false;
    }
    if(y!=0 && abs(color[x][y]-color[x][y-1])<=tol){
        return false;
    }
    if(y!=color[0].size()-1 && abs(color[x][y]-color[x][y+1])<=tol){
        return false;
    }
    if(x!=color.size()-1 && y!=0 && abs(color[x][y]-color[x+1][y-1])<=tol){
        return false;
    }
    if(x!=color.size()-1 && abs(color[x][y]-color[x+1][y])<=tol){
        return false;
    }
    if(x!=color.size()-1 && y!=color[0].size()-1 && abs(color[x][y]-color[x+1][y+1])<=tol){
        return false;
    }
    return true;
}