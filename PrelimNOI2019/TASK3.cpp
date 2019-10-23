#include <iostream>
#include <cstdio>
#include <vector>
#define taskname "TEST"

using namespace std;
const int maxn=1e5+1;

int n,m,charge[maxn],lab[maxn];
struct Edge{
    int x,y,w;
}e[maxn];
struct Query{
    char type;
    int x,y;
};
vector<int> adj[maxn];
vector<Query> q;

inline void Enter(){
    cin>>n>>m;
    q.resize(m);
    for(int i=0;i<m;i++){
        cin>>q[i].type>>q[i].x>>q[i].y;
        adj[q[i].x].push_back(i);
        adj[q[i].y].push_back(i);
        if(q[i].type=='R') e[i]={q[i].x,q[i].y,0};
        if(q[i].type=='A') e[i]={q[i].x,q[i].y,1};
    }
}

inline void Dfs(const int &u){
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(charge[v]!=-1) continue;
        charge[v]=charge[u]^e[i].w;
        Dfs(v);
    }
}

inline void Init(){
    fill(charge+1,charge+n+1,-1);
    for(int i=1;i<=n;i++) if(charge[i]==-1) charge[i]=0,Dfs(i);
    fill(lab,lab+n+1,-1);
}

inline int Find(const int &x){
    return lab[x]<0? x : lab[x]=Find(lab[x]);
}

inline void Union(int x,int y){
    x=Find(x); y=Find(y);
    if(x==y) return;
    if(lab[x]>lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
}

inline void Solve(){
    for(int i=0;i<m;i++){
        if(q[i].type=='Q'){
            if(Find(q[i].x)!=Find(q[i].y)) cout<<"?\n";
            else{
                if(charge[q[i].x]!=charge[q[i].y]) cout<<"A\n";
                else cout<<"R\n";
            }
        } else Union(q[i].x,q[i].y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Enter();
    Init();
    Solve();
    return 0;
}
