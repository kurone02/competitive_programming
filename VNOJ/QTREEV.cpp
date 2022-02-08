#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

typedef unsigned long long ull;

using namespace std;

const int maxn=1e5+7;

int n;
ull m;
vector<int> adj[maxn];
bool c[maxn];
ull a[maxn];
double f[maxn];
int g[maxn];
ull kq=1;

inline void dfs(int u){
    c[u]=true;
    bool leaf=true;
    double maxU=0;
    rep(i,0,(int)adj[u].size()){
        int v=adj[u][i];
        if(c[v]) continue;
        leaf=false;
        dfs(v);
        if(f[v]>maxU){
        	g[u]=v;
            maxU=f[v];
        }
    }
    if(leaf) f[u]=log10(a[u]);
    else f[u]=maxU+log10(a[u]);
}

inline ull mul(ull x,ull y){
    if(y==0) return 0;
    if(y==1) return x;
    ull tmp=mul(x,y>>1);
    tmp=(tmp+tmp)%m;
    if(y&1) return (tmp+x)%m;
    else return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>n>>m;
    up(i,1,n) cin>>a[i];
    while(n-->1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    int v=1;
    while(v){
        kq=mul(kq,a[v]);
        //cerr<<v<<' '<<kq<<'\n';
        v=g[v];
    }

    cout<<kq;

    return 0;
}
