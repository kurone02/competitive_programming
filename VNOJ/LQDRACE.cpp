#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <map>
#include <vector>
#include <functional>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=2e5+7;

struct Edges{
    int x,y,w;
};

int n,k;
int f[maxn][20],dis[maxn],lv[maxn],par[maxn];
bool isCentroid[maxn];
vector<int> adj[maxn],cen_child[maxn];
Edges e[maxn];

inline void Input(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>e[i].x>>e[i].y>>e[i].w;
        e[i].x++; e[i].y++;
        adj[e[i].x].push_back(i);
        adj[e[i].y].push_back(i);
    }
}

inline int Find_Centroid(const int &root){
    static vector<int> sz(n+1);
    function<void(int,int)> GetSize=[&](const int &u, const int &p){
        sz[u]=1;
        for(int i: adj[u]){
            int v=e[i].x+e[i].y-u;
            if(v!=p && !isCentroid[v]){
                GetSize(v,u);
                sz[u]+=sz[v];
            }
        }
    };
    GetSize(root,-1);
    int nChild=sz[root];
    function<int(int,int)> Dfs=[&](const int &u, const int &p){
        for(int i: adj[u]){
            int v=e[i].x+e[i].y-u;
            if(v!=p && !isCentroid[v] && sz[v]>nChild/2) return Dfs(v,u);
        }
        return u;
    };
    return Dfs(root,-1);
}

inline void Centroid_Decomposition(){
    function<void(int,int)> Dfs=[&](const int &u, const int &p){
        int centroid=Find_Centroid(u);
        isCentroid[centroid]=true;
        par[centroid]=p;
        if(p!=-1) cen_child[p].push_back(centroid);
        for(int i: adj[centroid]){
            int v=e[i].x+e[i].y-centroid;
            if(!isCentroid[v]) Dfs(v,centroid);
        }
        isCentroid[centroid]=false;
    };
    Dfs(1,-1);
}

inline void LCA_Prep(const int &u, const int &p){
    f[u][0]=p;
    for(int i=1;i<20;i++){
        int v=f[u][i-1];
        if(v!=-1) f[u][i]=f[v][i-1];
        else f[u][i]=-1;
    }
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(v==p) continue;
        dis[v]=dis[u]+e[i].w;
        lv[v]=lv[u]+1;
        LCA_Prep(v,u);
    }
}

inline int Jump(int u, int k){
    for(int cur=0;k;k>>=1){
        if(k&1) u=f[u][cur];
        cur++;
    }
    return u;
}

inline int Lca(int u, int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=Jump(v,lv[v]-lv[u]);
    if(u==v) return u;
    for(int i=19;i>=0;i--) if(f[u][i]!=f[v][i]){
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}

inline int Distance(const int &u, const int &v){
    return dis[u]+dis[v]-2*dis[Lca(u,v)];
}

inline int NumEdges(const int &u, const int &v){
    return lv[u]+lv[v]-2*lv[Lca(u,v)];
}

inline int Solve(){
    int res=1e9+7;
    for(int root=1;root<=n;root++){
        map<int,int> dp,local;
        dp.insert(make_pair(0,0));
        function<void(int)> Dfs=[&](const int &u){
            int D=Distance(root,u);
            int E=NumEdges(root,u);
            if(dp.find(k-D)!=dp.end()) res=min(res,E+dp[k-D]);
            if(local.find(D)==local.end()) local[D]=E;
            else local[D]=min(local[D],E);
            for(int v: cen_child[u]) Dfs(v);
        };
        for(int u: cen_child[root]){
            local.clear();
            Dfs(u);
            for(auto it: local){
                if(dp.find(it.first)==dp.end()) dp[it.first]=it.second;
                else dp[it.first]=min(dp[it.first],it.second);
            }
        }
    }
    if(res!=1e9+7) return res;
    return -1;
}

inline int best_path(int N, int K, int H[][2], int L[]){
    n=N; k=K;
    for(int i=0;i<N;i++){
        e[i]={H[i][0]+1,H[i][1]+1,L[i]};
        adj[e[i].x].push_back(i);
        adj[e[i].y].push_back(i);
    }
    Centroid_Decomposition();
    LCA_Prep(1,-1);
    return Solve();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Input();
    Centroid_Decomposition();
    LCA_Prep(1,-1);
    cout<<Solve();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
