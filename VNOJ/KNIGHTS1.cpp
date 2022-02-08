#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define self (*this)
 
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
 
const int maxn=3e3+7;
const int maxm=1e5+7;
 
int n,m,q,logn,MaxDis;
int lv[maxn],f[15][maxn],g[15][maxn],lab[maxn];
bool c[maxn];
struct Neko{int x,y,w;Neko(){};Neko(int x,int y,int w){self.x=x;self.y=y;self.w=w;}}e[maxm];
vector<pii> a[maxn];
pii p[maxn];
 
inline void Enter(){
    cin>>n>>m;
    up(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]=Neko(u,v,w);
    }
}
 
inline bool ss(Neko x,Neko y){return x.w<y.w;}
 
inline void MakeSet(){fill(lab,lab+n+1,-1);}
 
inline int FindSet(int x){return (lab[x]<0)? x : lab[x]=FindSet(lab[x]);}
 
inline void Union(int x,int y){
    x=FindSet(x),y=FindSet(y);
    if(lab[y]<lab[x]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
}
 
inline void FindMinTree(){
    MakeSet();
    sort(e+1,e+m+1,ss);
    up(i,1,m){
        int x=FindSet(e[i].x),
            y=FindSet(e[i].y);
        if(x!=y){
            Union(x,y);
            a[e[i].x].pb(pii(e[i].y,e[i].w));
            a[e[i].y].pb(pii(e[i].x,e[i].w));
        }
    }
}
 
inline int Log2(int x){int res=0;for(;x;x/=2) res++;return res;}
 
inline void Dfs(int u){
    c[u]=true;
    for(auto v: a[u]){
        if(c[v.x]) continue;
        p[v.x]=pii(u,v.y); lv[v.x]=lv[u]+1;
        Dfs(v.x);
    }
}
 
inline void PrepareLCA(){
    lv[1]=0; up(i,1,n) p[i]=pii(-1,0);
    Dfs(1);
    logn=Log2(n);
    up(i,1,n) f[0][i]=p[i].x,g[0][i]=p[i].y;
    up(k,1,logn) up(u,1,n){
        int v=f[k-1][u];
        if(v==-1) f[k][u]=-1,g[k][u]=0;
        else f[k][u]=f[k-1][v],g[k][u]=max(g[k-1][u],g[k-1][v]);
    }
}
 
inline int Jump(int u,int k){
    int cur=0;
    for(;k;k/=2){
        if(k&1) MaxDis=max(MaxDis,g[cur][u]),u=f[cur][u];
        cur++;
    }
    return u;
}
 
inline int LCA(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=Jump(v,lv[v]-lv[u]);
    if(u==v) return MaxDis;
    down(k,logn,0) if(f[k][u]!=f[k][v]) MaxDis=max(MaxDis,max(g[k][u],g[k][v])),u=f[k][u],v=f[k][v];
    return max(MaxDis,max(p[u].y,p[v].y));
}
 
inline void Solve(){
	#define Kamisama
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        MaxDis=0;
        cout<<LCA(u,v)<<'\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifndef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif // Kamisama
 
    Enter();
    FindMinTree();
    PrepareLCA();
    Solve();
 
    return 0;
}