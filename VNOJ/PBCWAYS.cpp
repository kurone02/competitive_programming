#include <iostream>
#include <vector>
#include <queue>
#define taskname "PBCWAYS"

using namespace std;
const int maxn=1002;
const int maxm=1e4+7;

int n,m,s,t,nEdge,maxFlow;
int h[maxn];
struct Edge{int x,y,cf;}e[2*maxm];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];

inline int Encode(const int &i, const int &j){
    return (i-1)*m+j;
}

inline void AddEdge(const int &u,const int &v){
    e[2*nEdge]={u,v,1};
    adj[u].push_back(2*nEdge);
    e[2*nEdge+1]={v,u,0};
    adj[v].push_back(2*nEdge+1);
    nEdge++;
}

inline void Enter(){
    cin>>n>>m; s=0,t=2*n*m+1;
//    cerr<<t<<'\n';
    for(int j=1;j<m;j++){
        for(int i=1,nn;i<=n;i++){
            cin>>nn;
            for(int k=1,x;k<=nn;k++){
                cin>>x;
                AddEdge(Encode(i,j),Encode(x,j+1)+m*n);
            }
        }
//        cerr<<j<<' '<<t<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            AddEdge(Encode(i,j)+m*n,Encode(i,j));
        }
    }
    for(int i=1;i<=n;i++) AddEdge(s,Encode(i,1)+m*n),AddEdge(Encode(i,m),t);
}

inline void Bfs(){
    fill(h,h+t+1,-1);
    queue<int> q;
    q.push(t);
    h[t]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
//        cerr<<u<<": ";
        for(int i: adj[u]){
            i^=1;
            int v=e[i].x;
//            cerr<<v<<' ';
            if(e[i].cf==0 || h[v]!=-1) continue;
            h[v]=h[u]+1;
            if(v==s) return;
            q.push(v);
        }
//        cerr<<'\n';
    }
}

inline int Dfs(const int &u, int flowIn){
    if(u==t) return flowIn;
    int flowOut=0;
//    cerr<<u<<' '<<flowIn<<'\n';
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
    for(int u=s;u<=t;u++) current[u]=adj[u].begin();
    maxFlow+=Dfs(s,n+1);
}

inline void Solve(){
    while(Bfs(),h[s]!=-1) BlockingFlow();
    cout<<maxFlow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Enter();
    Solve();
    return 0;
}
