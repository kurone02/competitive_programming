#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const int maxm=1e4+7;
const ll mod=123456789;
const int inf=1e9;

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int n;
int num[maxn],lv[maxn],par[maxn],f[maxn][18];
vector<int> adj[maxn];

inline void Enter(){
    cin>>n;
    rep(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

inline void Init(){
    function<void(int,int)> Dfs=[&](const int &u, const int &p){
        static int nVisit=0;
        num[u]=++nVisit;
        par[u]=p;
        for(int v: adj[u]) if(v!=p) lv[v]=lv[u]+1,Dfs(v,u);
    };
    Dfs(1,-1);
    up(u,1,n) f[u][0]=par[u];
    rep(k,1,17) up(u,1,n){
        int v=f[u][k-1];
        if(v==-1) f[u][k]=-1;
        else f[u][k]=f[v][k-1];
    }
}

inline int Lca(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    function<int(int,int)> Jump=[&](int u, int k){
        int cur=0;
        for(;k;k>>=1){
            if(k&1) u=f[u][cur];
            cur++;
        }
        return u;
    };
    v=Jump(v,lv[v]-lv[u]);
    if(v==u) return u;
    repd(k,17,0) if(f[u][k]!=f[v][k]) u=f[u][k],v=f[v][k];
    return par[u];
}

inline void Solve(){
    up(u,1,n){
        vector<int> d;
        d.pb(1);
        for(int v=u;v<=n;v+=u) d.pb(v);
        sort(d.begin(),d.end(),[](const int &u, const int &v){
            return num[u]<num[v];
        });
        d.pb(1);
        int res=0;
        rep(i,1,(int)d.size()) res+=lv[d[i]]+lv[d[i-1]]-2*lv[Lca(d[i],d[i-1])];
        cout<<res<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}