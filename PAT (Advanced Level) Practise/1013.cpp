#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>

int check(std::vector<std::vector<int>> G,std::size_t occupied);
std::vector<std::size_t> BFS(std::vector<std::vector<int>> &G,std::size_t s);

int main(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> G(n,std::vector<int>(n,INT_MAX));
    for(int i=0;i<m;++i){
        std::size_t u,v;
        std::cin>>u>>v;
        G[u-1][v-1] = 1;
        G[v-1][u-1] = 1;
    }
    for(int i=0;i<k;++i){
        std::size_t occupied;
        std::cin>>occupied;
        std::cout<<check(G,occupied-1)-1<<std::endl;
    }
    return 0;
}

int check(std::vector<std::vector<int>> G,std::size_t occupied){
    std::set<std::size_t> unvisited;
    for(std::size_t i=0;i<G.size();++i){
        G[i][occupied] = INT_MAX;
        G[occupied][i] = INT_MAX;
        if(i!=occupied)
            unvisited.insert(i);
    }
    std::size_t cnt = 0;
    while(!unvisited.empty()){
        ++cnt;
        auto s = *unvisited.begin();
        auto res = BFS(G,s);
        for(auto n:res){
            unvisited.erase(n);
        }
    }
    return cnt;
}

//返回BFS到的点的下标
std::vector<std::size_t> BFS(std::vector<std::vector<int>> &G,std::size_t s){
    std::vector<int> color(G.size());
    for(std::size_t i=0;i<color.size();++i){
        if(i == s){
            color[i] = 1;
        }else{
            color[i] = 0;
        }
    }
    std::queue<std::size_t> Q;
    Q.push(s);
    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        for(std::size_t v=0;v<G.size();++v){
            if(G[u][v] != INT_MAX){
                if(color[v] == 0){
                    color[v] = 1;
                    Q.push(v);
                }
            }
        }
        color[u] = 2;
    }
    std::vector<std::size_t> visited;
    for(std::size_t i=0;i<color.size();++i){
        if(color[i] == 2){
            visited.push_back(i);
        }
    }
    return visited;
}