#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#include <queue>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=4e2+7;
const int maxm=5e4+3;
const int inf=1e9+7;

struct TEdges{
    int x,y,cf;
    inline TEdges(int _x=0, int _y=0, int _cf=0){
        x=_x; y=_y; cf=_cf;
    }
};

int n,m,s,t,maxFlow,maxC;
int c[maxn][maxn],h[maxn];
TEdges e[2*maxm];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];

inline void Enter(){
    cin>>n; s=0; t=2*n+1;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) cin>>c[i][j], maxC=max(maxC,c[i][j]);
}

inline void AddEdge(const int &u, const int &v){
    adj[u].push_back(m<<1);
    e[m<<1]=TEdges(u,v,1);
    adj[v].push_back(m<<1|1);
    e[m<<1|1]=TEdges(v,u,0);
    m++;
}

inline void Bfs(){
    fill(h,h+t+1,-1);
    queue<int> q;
    q.push(t); h[t]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i: adj[u]){
            i^=1;
            int v=e[i].x;
            if(e[i].cf==0 || h[v]!=-1) continue;
            h[v]=h[u]+1;
            if(v==s) return;
            q.push(v);
        }
    }
}

inline int Dfs(const int &u, int flowIn){
    if(u==t) return flowIn;
    int flowOut=0;
    for(;current[u]!=adj[u].end();current[u]++){
        int i=*current[u];
        int v=e[i].y;
        if(e[i].cf==0 || h[v]!=h[u]-1) continue;
        int q=Dfs(v,min(e[i].cf,flowIn));
        flowIn-=q;
        flowOut+=q;
        e[i].cf-=q;
        e[i^1].cf+=q;
        if(flowIn==0) break;
    }
    return flowOut;
}

inline void BlockingFlow(){
    for(int i=s;i<=t;i++) current[i]=adj[i].begin();
    maxFlow+=Dfs(s,inf);
}

inline bool F(const int &mid){
    for(int i=s;i<=t;i++) adj[i].clear();
    maxFlow=0; m=0;
    for(int i=1;i<=n;i++) AddEdge(s,i);
    for(int i=1;i<=n;i++) AddEdge(n+i,t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(c[i][j]<=mid) AddEdge(i,n+j);
    while(Bfs(),h[s]!=-1) BlockingFlow();
    return maxFlow==n;
}

inline void Solve(){
    int l=0,r=maxC;
    while(l<=r){
        int mid=l+r>>1;
        if(F(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Enter();
    Solve();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
