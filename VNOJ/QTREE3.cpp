#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
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
const int maxm=5e3+7;
const int hashTableMod=4074004;
const ll mod=1e9+7;
const int inf=1e9+7;
const ll linf=1e17+7;
const double esp=1e-7;
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

int n,q,nChain,nPos;
int par[maxn],chainHead[maxn],nChild[maxn],pos[maxn],inPos[maxn];
int L[4*maxn],R[4*maxn],it[4*maxn],a[maxn];
vector<int> adj[maxn];

inline void Enter(){
    cin>>n>>q;
    rep(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

inline void Dfs(const int &u, const int &p){
    par[u]=p;
    for(int v: adj[u]){
        if(v==p) continue;
        Dfs(v,u);
        nChild[u]+=nChild[v]+1;
    }
}

inline void Hld(const int &u){
    if(!chainHead[u]) chainHead[u]=u;
    pos[++nPos]=u;
    inPos[u]=nPos;
    int specV=-1;
    for(int v: adj[u])
        if(v!=par[u] && (specV==-1 || nChild[v]>nChild[specV])) specV=v;
    if(specV!=-1){
        chainHead[specV]=chainHead[u];
        Hld(specV);
    }
    for(int v: adj[u]) if(v!=par[u] && v!=specV){
        nChain++;
        Hld(v);
    }
}

inline void Build(const int &x, const int &low, const int &high){
    if(low>high) return;
    L[x]=low,R[x]=high;
    if(low==high){
        it[x]=a[low];
        return;
    }
    int mid=(low+high)>>1;
    Build(CL(x),low,mid);
    Build(CR(x),mid+1,high);
    it[x]=min(it[CL(x)],it[CR(x)]);
}

inline void Update(const int &x, const int &pos, const int &val){
    if(L[x]>pos || R[x]<pos) return;
    if(L[x]==R[x]){
        it[x]=val;
        a[pos]=val;
        return;
    }
    Update(CL(x),pos,val);
    Update(CR(x),pos,val);
    it[x]=min(it[CL(x)],it[CR(x)]);
}

inline int Query(const int &x, const int &low, const int &high){
    if(L[x]>high || R[x]<low) return inf;
    if(low<=L[x] && R[x]<=high) return it[x];
    return min(Query(CL(x),low,high),Query(CR(x),low,high));
}

inline void Init(){
    Dfs(1,-1);
    Hld(1);
    up(i,1,n) a[i]=inf;
    Build(1,1,n);
}

inline void Update(const int &u){
    if(a[inPos[u]]!=inf) Update(1,inPos[u],inf);
    else Update(1,inPos[u],inPos[u]);
}

inline int Query(int u){
    int res=inf;
    int head=chainHead[u];
    while(head!=1){
        res=min(res,Query(1,inPos[head],inPos[u]));
        u=par[head];
        head=chainHead[u];
    }
    res=min(res,Query(1,1,inPos[u]));
    return (res==inf)? -1 : pos[res];
}

inline void Solve(){
    while(q--){
        bool type;
        int x;
        cin>>type>>x;
        if(type) cout<<Query(x)<<'\n';
        else Update(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}
