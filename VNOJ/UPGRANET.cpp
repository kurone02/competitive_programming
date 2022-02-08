#include<bits/stdc++.h>
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e5+7;
const int inf=1e9+7;

int n,m,logn;
struct Neko{
    int x,y,w;
}e[maxn];
vector< pair<int,int> > a[maxn];
#define X first
#define Y second
int lab[maxn],d[25][maxn];
bool c[maxn],tree[maxn];
int lv[maxn];
pair<int,int> p[maxn];
int f[25][maxn];
int mindis=inf;
ll kq;

inline void enter(){
    cin>>n>>m;
    up(i,1,m){
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
}

inline void MakeSet(){
    fill(lab,lab+n+1,-1);
}

inline int FindSet(int x){
    return (lab[x]<0)? x : lab[x]=FindSet(lab[x]);
}

inline void Combine(int x,int y){
    if(lab[x]>lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
}

inline bool ss(Neko x,Neko y){
    return x.w>y.w;
}

inline void FindMaxTree(){
    MakeSet();
    sort(e+1,e+m+1,ss);
    up(i,1,m){
        int x=FindSet(e[i].x),
            y=FindSet(e[i].y);
        if(x!=y){
            Combine(x,y);
            //cerr<<e[i].x<<' '<<e[i].y<<' '<<e[i].w<<'\n';
            tree[i]=true;
            a[e[i].x].pb(make_pair(e[i].y,e[i].w));
            a[e[i].y].pb(make_pair(e[i].x,e[i].w));
        }
    }
}

inline void dfs(int u){
    c[u]=true;
    //cerr<<u<<'\n';
    rep(i,0,a[u].size()){
        int v=a[u][i].X;
        if(!c[v]) lv[v]=lv[u]+1,p[v].X=u,p[v].Y=a[u][i].Y,dfs(v);
    }
}

inline int Log2(int x){
    int res=0;
    for(;x;x/=2) res++;
    return res;
}

inline void PrepareLCA(){
    lv[1]=0;
    logn=Log2(n);
    p[1].Y=inf;
    up(i,1,n) f[0][i]=p[i].X,d[0][i]=p[i].Y;
    up(k,1,logn) up(u,1,n){
        int v=f[k-1][u];
        if(v==-1) f[k][u]=-1,d[k][u]=inf;
        else f[k][u]=f[k-1][v],d[k][u]=min(d[k-1][u],d[k-1][v]);
    }
}

inline int jump(int u,int k){
    int cur=0;
    for(;k;k/=2){
        if(k&1) mindis=min(mindis,d[cur][u]),u=f[cur][u];
        cur++;
    }
    return u;
}

inline int lca(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=jump(v,lv[v]-lv[u]);
    //cerr<<mindis<<'\n';
    if(u==v) return mindis;
    down(k,logn,0) if(f[k][u]!=f[k][v]) mindis=min(mindis,min(d[k][u],d[k][v])),u=f[k][u],v=f[k][v];
    return min(mindis,min(p[u].Y,p[v].Y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //freopen("UPGRANET.INP","r",stdin);
    //freopen("UPGRANET.OUT","w",stdout);

    enter();

    FindMaxTree();
    up(i,1,n) p[i].X=-1;
    dfs(1);
    PrepareLCA();

    up(i,1,m) if(!tree[i]) mindis=inf,kq+=lca(e[i].x,e[i].y)-e[i].w;//cerr<<lca(e[i].x,e[i].y)<<'\n';

    cout<<kq;

    return 0;
}


















