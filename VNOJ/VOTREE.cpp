#include<bits/stdc++.h>
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const int maxn=4e5+7;

int n,logn,q;
vector<int> a[maxn];
int f[20][maxn],lv[maxn],p[maxn];
bool c[maxn];
int it[maxn];
int L[maxn],H[maxn];

inline void dfs(int u){
    c[u]=true;
    rep(i,0,a[u].size()){
        int v=a[u][i];
        if(!c[v]) p[v]=u,lv[v]=lv[u]+1,dfs(v);
    }
}

inline int log2(int x){
    int res=0;
    for(;x;x/=2) res++;
    return res;
}

inline void PreProcessLCA(){
    lv[1]=0;
    p[1]=-1;
    dfs(1);

    logn=log2(n);
    up(u,1,n) f[0][u]=p[u];
    up(k,1,logn) up(u,1,n){
        int v=f[k-1][u];
        if(v==-1) f[k][u]=-1;
        else f[k][u]=f[k-1][v];
    }
}

inline int jump(int u,int k){
    int cur=0;
    for(;k;k/=2){
        if(k&1) u=f[cur][u];
        cur++;
    }
    return u;
}

inline int lca(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=jump(v,lv[v]-lv[u]);
    if(u==v) return u;
    down(k,logn,0) if(f[k][u]!=f[k][v]) u=f[k][u], v=f[k][v];
    return p[u];
}

inline void build(const int &x,const int &low,const int &high){
    if(low>high) return;
    L[x]=low,H[x]=high;
    if(low==high){
        it[x]=low;
        return;
    }
    int mid=(low+high)>>1;
    build(CL(x),low,mid);
    build(CR(x),mid+1,high);
    it[x]=lca(it[CL(x)],it[CR(x)]);
    //it[x]=it[CL(x)]+it[CR(x)];
}

inline int query(int x,const int &low,const int &high){
    if(low>H[x] || L[x]>high) return low;
    if(low<=L[x] && H[x]<=high) return it[x];
    return lca(query(CL(x),low,high),query(CR(x),low,high));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>q;
    rep(i,1,n){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    PreProcessLCA();
    build(1,1,n);

    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<query(1,u,v)<<'\n';
    }

    return 0;
}
