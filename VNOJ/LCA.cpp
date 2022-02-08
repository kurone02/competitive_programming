#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define UP(i,a,b) for(i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define All(x) x.begin(),x.end()
#define CntBit(x) __builtin_popcount(x)
#define GetBit(x,k) (((x)>>(k))&1)
#define OffBit(x,k) ((x)&(~(1<<(k))))
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const int maxm=4e2+7;
const ll mod=76213;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;
const double pi=acos(-1);

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

int n,nChain;
int nChild[maxn],chainHead[maxn],chainInd[maxn],par[maxn],lv[maxn];
vector<int> adj[maxn];

inline void Enter(){
    cin>>n;
    up(u,1,n){
        int m,v;
        cin>>m;
        up(i,1,m) cin>>v,adj[u].pb(v);
    }
}

inline void Dfs(const int &u, const int &p){
    par[u]=p;
    for(int v: adj[u]) if(v!=p) lv[v]=lv[u]+1,Dfs(v,u),nChild[u]+=nChild[v]+1;
}

inline void Hld(const int &u){
    if(!chainHead[u]) chainHead[u]=u;
    chainInd[u]=nChain;
    int specV=-1;
    for(int v: adj[u]) if(v!=par[u]&&(specV==-1||nChild[v]>nChild[specV])) specV=v;
    if(specV!=-1) Hld(specV);
    for(int v: adj[u]) if(v!=par[u]&&v!=specV) nChain++,Hld(v);
}

inline int Lca(int u, int v){
    if(lv[u]>lv[v]) swap(u,v);
    if(chainHead[u]==chainHead[v]) return u;
    return Lca(u,par[chainHead[v]]);
}

inline void Init(){
    Dfs(1,-1);
    Hld(1);
}

inline void Solve(){
    int q;
    for(cin>>q;q;q--){
        int u,v;
        cin>>u>>v;
        cout<<Lca(u,v)<<'\n';
    }
}

inline void Reset(){
    fill(nChild,nChild+n+1,0);
    fill(chainHead,chainHead+n+1,0);
    fill(chainInd,chainInd+n+1,0);
    fill(par,par+n+1,0);
    fill(lv,lv+n+1,0);
    up(u,0,n+1) adj[u].clear();
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

    int nTest;
    cin>>nTest;
    up(t,1,nTest){
        fill(lv,lv+n+1,0);
        fill(lv,lv+n+1,0);
        Enter();
        Init();
        cout<<"Case "<<t<<":\n"; Solve();
        Reset();
    }

    return 0;
}

