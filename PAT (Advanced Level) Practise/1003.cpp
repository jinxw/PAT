#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>

std::vector<int> d;
std::vector<int> pi;
std::vector<int> cnt;   //the number of different shortest paths
std::vector<int> sum;   //the maximum amount of rescue teams
std::vector<int> teams;

void initialize_single_source(std::vector<std::vector<int>> &G,std::size_t s){
    d.resize(G.size());
    std::fill(d.begin(),d.end(),INT_MAX);
    pi.resize(G.size());
    std::fill(pi.begin(),pi.end(),-1);
    d[s] = 0;
    cnt.resize(G.size());
    std::fill(cnt.begin(),cnt.end(),1);
    sum.resize(G.size());
    sum = teams;
}

void relax(int u,int v,std::vector<std::vector<int>> &G){
    if(d[v] > d[u]+G[u][v]){
        d[v] = d[u]+G[u][v];
        pi[v] = u;
        cnt[v] = cnt[u];
        sum[v] = sum[u]+teams[v];
    }else if(d[v] == d[u]+G[u][v]){
        cnt[v] += cnt[u];   //#2
        if(sum[v] < sum[u]+teams[v]){
            sum[v] = sum[u]+teams[v];
            pi[v] = u;
        }
    }
}

std::pair<std::vector<int>,std::vector<int>> Dijkstra(std::vector<std::vector<int>> &G,std::size_t s){
    initialize_single_source(G,s);
    std::set<std::size_t> S;
    std::set<std::size_t> Q;
    for(std::size_t i=0;i<G.size();++i){
        Q.insert(i);
    }
    while(!Q.empty()){
        std::size_t u = *Q.begin();
        for(auto v:Q){
            if(d[v] < d[u]){
                u = v;
            }
        }
        Q.erase(u);
        S.insert(u);
        for(int i=0;i<G.size();++i){
            if(i!=u && G[u][i]!=INT_MAX){
                relax(u,i,G);
            }
        }
    }
    return std::make_pair(cnt,sum);
}

int main(){
    int n;  //the number of cities
    int m;  //the number of roads
    int c1,c2;
    std::cin>>n>>m>>c1>>c2;
    std::vector<std::vector<int>> G(n,std::vector<int>(n,INT_MAX));
    //std::vector<int> teams(n);
    teams.resize(n);
    for(int i=0;i<n;++i){
        std::cin>>teams[i];
    }
    for(int i=0;i<m;++i){
        int u,v,l;
        std::cin>>u>>v>>l;
        G[u][v] = l;
        G[v][u] = l;
    }
    auto res = Dijkstra(G,c1);
    auto &cnt = std::get<0>(res);
    auto &sum = std::get<1>(res);
    std::cout<<cnt[c2]<<" "<<sum[c2]<<std::endl;
    return 0;
}