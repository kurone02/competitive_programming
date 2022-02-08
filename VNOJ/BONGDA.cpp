#include <iostream>
#include <vector>
#include <queue>
#define taskname "BONGDA"

using namespace std;
const int maxn=50;
const int maxm=2600;
const int inf=1e9+7;

int n,m,s,t,maxFlow,res[maxn][maxn];
int best[maxn],now[maxn],countMatch;
int h[maxn];
struct Edge{int x,y,cf;}e[maxm];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];

inline void Enter(){
    cin>>n; s=0,t=n+1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>res[i][j];
}

inline void Init(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        now[i]+=res[i][j]&1,
        best[i]+=res[i][j]>>1;
    }
    for(int i=1;i<=n;i++) best[i]+=now[i];
    for(int i=1;i<=n;i++) countMatch+=best[i]-now[i];
    countMatch>>=1;
}

inline void AddEdge(const int &u, const int &v,const int &w){
    e[2*m]={u,v,w};
    adj[u].push_back(2*m);
    e[2*m+1]={v,u,0};
    adj[v].push_back(2*m+1);
    m++;
}

inline void ConstructGraph(const int &team){
    int nMatchLeft[maxn]={};
    for(int i=1;i<=n;i++) if(i!=team)
        for(int j=i+1;j<=n;j++) if(j!=team)
            if(res[i][j]==2) AddEdge(i,j,1),nMatchLeft[i]++;
    for(int i=1;i<=n;i++) if(i!=team && nMatchLeft[i])
        AddEdge(s,i,nMatchLeft[i]);
    for(int i=1;i<=n;i++) if(i!=team && best[team]-now[i]>0)
        AddEdge(i,t,best[team]-now[i]);
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
    for(int u=s;u<=t;u++) current[u]=adj[u].begin();
    maxFlow+=Dfs(s,inf);
}

inline void FindMaxFlow(){
    maxFlow=0;
    while(Bfs(),h[s]!=-1) BlockingFlow();
}

inline void DestructGraph(){
    for(int i=0;i<2*m;i++) e[i]={0,0,0};
    for(int u=s;u<=t;u++) adj[u].clear();
    m=0;
}

inline bool CanWin(const int &team){
    for(int i=1;i<=n;i++) if(now[i]>best[team]) return false;
    ConstructGraph(team);
    FindMaxFlow();
    DestructGraph();
    return maxFlow>=countMatch-(best[team]-now[team]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Enter();
    Init();
    for(int team=1;team<=n;team++) cout<<CanWin(team);
    return 0;
}
