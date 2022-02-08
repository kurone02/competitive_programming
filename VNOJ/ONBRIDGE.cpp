#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#define rank rnk
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=5e4+7;

int n,m,bridges,iter;
int cc[maxn],bcc[maxn],rank[maxn],par[maxn];
int vis[maxn];

inline void Input(){
    cin>>n>>m;
}

inline void Init(){
    iter=bridges=0;
    for(int i=1;i<=n;i++){
        cc[i]=bcc[i]=i;
        rank[i]=vis[i]=0;
        par[i]=-1;
    }
}

inline int Find_CC(const int &x){
    return cc[x]==x? x : cc[x]=Find_CC(cc[x]);
}

inline int Find_BCC(const int &x){
    if(x==-1) return -1;
    return bcc[x]==x? x : bcc[x]=Find_BCC(bcc[x]);
}

inline void MakeRoot(int u){
    u=Find_BCC(u);
    int root=u;
    int child=-1;
    while(u!=-1){
        int p=Find_BCC(par[u]);
        par[u]=child;
        cc[u]=root;
        child=u;
        u=p;
    }
    rank[root]=rank[child];
}

inline void GoUp(int &u, vector<int> &path, int &lca){
    u=Find_BCC(u);
    path.push_back(u);
    if(vis[u]==iter){
        lca=u;
        return;
    }
    vis[u]=iter;
    u=par[u];
}

inline void Compress(int u, int v){
    iter++;
    vector<int> pathU,pathV;
    int lca=-1;
    while(lca==-1){
        if(u!=-1) GoUp(u,pathU,lca);
        if(lca!=-1) break;
        if(v!=-1) GoUp(v,pathV,lca);
    }
    for(int x: pathU){
        bcc[x]=lca;
        if(x==lca) break;
        bridges--;
    }
    for(int x: pathV){
        bcc[x]=lca;
        if(x==lca) break;
        bridges--;
    }
}

inline void AddEdge(int u, int v){
    u=Find_BCC(u);
    v=Find_BCC(v);
    if(u==v) return;
    int x=Find_CC(u);
    int y=Find_CC(v);
    if(x!=y){
        bridges++;
        if(rank[x]>rank[y]){
            swap(u,v);
            swap(x,y);
        }
        MakeRoot(u);
        cc[u]=par[u]=v;
        rank[y]+=rank[u];
    } else Compress(u,v);
}

inline void Solve(){
    for(int u,v;m--;cout<<bridges<<'\n'){
        cin>>u>>v;
        AddEdge(u+1,v+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    int nTest; cin>>nTest;
    while(nTest--){
        Input();
        Init();
        Solve();
    }

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
