#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+7;
const int inf=1e9+7;

int n,m,logn,mindis,maxdis;
vector<pii> a[maxn];
pii p[maxn];
#define fi first
#define se second
int lv[maxn];
bool c[maxn];
int f[25][maxn],maxd[25][maxn],mind[25][maxn];

inline void Enter(){
    cin>>n;
    up(i,1,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(pii(v,w));
        a[v].pb(pii(u,w));
    }
    up(i,1,n) a[i].pb(pii(0,0));
}

inline int log2(int x){
    int res=0;
    for(;x;x/=2) res++;
    return res;
}

inline void dfs(int u){
    c[u]=true;
    for(int i=0;int v=a[u][i].fi;i++)
        if(!c[v]) p[v].fi=u,p[v].se=a[u][i].se,lv[v]=lv[u]+1,dfs(v);
}

inline void PrepareLCA(){
    logn=log2(n);
    lv[1]=0,p[1]=pii(-1,inf);
    dfs(1);
    up(i,1,n) f[0][i]=p[i].fi,mind[0][i]=maxd[0][i]=p[i].se;

    up(k,1,logn) up(u,1,n){
        int v=f[k-1][u];
        if(v==-1) f[k][u]=-1,mind[k][u]=inf,maxd[k][u]=0;
        else mind[k][u]=min(mind[k-1][u],mind[k-1][v]),
             maxd[k][u]=max(maxd[k-1][u],maxd[k-1][v]),
             f[k][u]=f[k-1][v];
    }
}

inline int jump(int u,int k){
    int cur=0;
    for(;k;k/=2){
        if(k&1) mindis=min(mindis,mind[cur][u]),
                maxdis=max(maxdis,maxd[cur][u]),
                u=f[cur][u];
        cur++;
    }
    return u;
}

inline void lca(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=jump(v,lv[v]-lv[u]);
    if(u==v) return;
    down(k,logn,0) if(f[k][u]!=f[k][v])
        mindis=min(mindis,min(mind[k][u],mind[k][v])),
        maxdis=max(maxdis,max(maxd[k][u],maxd[k][v])),
        u=f[k][u],v=f[k][v];
    mindis=min(mindis,min(p[u].se,p[v].se));
    maxdis=max(maxdis,max(p[u].se,p[v].se));
    return;
}

inline void Query(){
    cin>>m;
    while(m--){
        mindis=inf,maxdis=0;
        int u,v;
        cin>>u>>v;
        lca(u,v);
        cout<<mindis<<' '<<maxdis<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    PrepareLCA();
    Query();

    return 0;
}
