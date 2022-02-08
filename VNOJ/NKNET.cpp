#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define taskname "TEST"
using namespace std;
const int maxn=1e2+1;
const int maxm=5e3+1;
const int inf=1e9+1;

struct Edge{
    int x,y,cf;
    Edge(int x=0,int y=0,int cf=0){this->x=x,this->y=y,this->cf=cf;}
};

int n,m,s,t,maxTime,maxFlow;
int cost[maxn][maxn],h[maxn];
bool visited[maxn];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];
Edge e[2*maxm];

inline void Enter(){
    cin>>n>>m;
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        cost[u][v]=w;
        cost[v][u]=w;
        maxTime=max(maxTime,w);
        adj[u].push_back(i<<1);
        adj[v].push_back((i<<1)|1);
        e[i<<1]=Edge(u,v,0);
        e[(i<<1)|1]=Edge(v,u,0);
    }
    cin>>s>>t;
}

inline void Bfs(){
    fill(h,h+n+1,-1);
    queue<int> q;
    q.push(t);
    h[t]=0;
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

inline int Dfs(const int &u,int flowIn){
    if(u==t) return flowIn;
    int flowOut=0;
    for(;current[u]!=adj[u].end();current[u]++){
        int i=*current[u];
        int v=e[i].y;
        if(e[i].cf==0 || h[v]!=h[u]-1) continue;
        int q=Dfs(v,min(flowIn,e[i].cf));
        flowIn-=q;
        flowOut+=q;
        e[i].cf-=q;
        e[i^1].cf+=q;
        if(flowIn==0) break;
    }
    return flowOut;
}

inline void BlockingFlow(){
    for(int i=1;i<=n;i++) current[i]=adj[i].begin();
    maxFlow+=Dfs(s,inf);
}

inline bool F(const int &x){
    for(int i=0;i<2*m;i++){
        int u=e[i].x,v=e[i].y;
        if(cost[u][v]>x) e[i].cf=1;
        else e[i].cf=0;
    }
    maxFlow=0;
    while(Bfs(),h[s]!=-1) BlockingFlow();
    return maxFlow==0;
}

inline void FindMinCut(const int &u){
    visited[u]=true;
    for(int i: adj[u]){
        if(e[i].cf==0) continue;
        int v=e[i].y;
        if(visited[v]) continue;
        FindMinCut(v);
    }
}

inline void Trace(const int &x){
    for(int i=0;i<2*m;i++){
        int u=e[i].x,v=e[i].y;
        if(cost[u][v]>x) e[i].cf=inf;
        else e[i].cf=1;
    }
    maxFlow=0;
    while(Bfs(),h[s]!=-1) BlockingFlow();
    cout<<maxFlow<<'\n';
    FindMinCut(s);
    for(int i=0;i<2*m;i+=2)
        if(visited[e[i].x]^visited[e[i].y]) cout<<e[i].x<<' '<<e[i].y<<'\n';
}

inline void Solve(){
    int l=0,r=maxTime;
    while(l<=r){
        int mid=(l+r)>>1;
        if(F(mid)) r=mid-1;
        else l=mid+1;
    }
    Trace(l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Enter();
    Solve();
    return 0;
}
