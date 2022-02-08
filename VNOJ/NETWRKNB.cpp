#include <bits/stdc++.h>
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
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const int maxm=1e4+7;
const ll mod=123456789;
const ll base=257;
const int inf=1e9+7;
const double esp=1e-6;

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

int n,m,logn;
int L[maxn],R[maxn],edgesID[maxn],f[maxn][20],pa[maxn],lv[maxn],result[maxn];
vector<int> adj[maxn];
struct Neko{int x,y,w,id;}e[maxn];
struct Chan{char type;int a,b,c,i,id;}q[maxn];
struct FenwickTree{
    int bit[maxn];
    inline void Update(int x,const int &val){
        for(;x<=n;x+=x&-x) bit[x]+=val;
    }
    inline void Update(const int &i, const int &j, const int &val){
        Update(i,val); Update(j+1,-val);
    }
    inline int Get(int x){
        int res=0;
        for(;x;x-=x&-x) res+=bit[x];
        return res;
    }
}bit1,bit2;

inline void Enter(){
    Read(n); Read(m);
    rep(i,1,n){
        int u,v,w;
        Read(u);Read(v);Read(w);
        adj[u].pb(i);
        adj[v].pb(i);
        e[i]={u,v,w,i};
    }
    up(i,1,m){
        q[i].type=getchar();
        if(q[i].type=='P') Read(q[i].a),Read(q[i].b),Read(q[i].c);
        else Read(q[i].i),Read(q[i].c);
        q[i].id=i;
    }
}

inline void TreeDecomposition(const int &u, const int &par){
    static int nVisits=0;
    L[u]=++nVisits;
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(v==par) continue;
        TreeDecomposition(v,u);
    }
    R[u]=nVisits;
}

inline void DfsLca(const int &u, const int &par){
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(v==par) continue;
        pa[v]=u; lv[v]=lv[u]+1;
        DfsLca(v,u);
    }
}

inline int Log2(const int &x){
    int res=0;
    while((1<<res)<=x) res++;
    return res-1;
}

inline void Init(){
    TreeDecomposition(1,-1);
    pa[1]=-1;
    DfsLca(1,-1);
    up(u,1,n) f[u][0]=pa[u];
    logn=Log2(n);
    up(k,1,logn) up(u,1,n){
        int v=f[u][k-1];
        if(v==-1) f[u][k]=-1;
        else f[u][k]=f[v][k-1];
    }
    sort(e+1,e+n,[](const Neko &x, const Neko &y){return x.w<y.w;});
    sort(q+1,q+m+1,[](const Chan &x, const Chan &y){return x.c<y.c;});
    rep(i,1,n) edgesID[e[i].id]=i;
}

inline int Jump(int u, int k){
    int cur=0;
    for(;k;k/=2){
        if(k&1) u=f[u][cur];
        cur++;
    }
    return u;
}

inline int Lca(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    v=Jump(v,lv[v]-lv[u]);
    if(u==v) return u;
    down(k,logn,0) if(f[u][k]!=f[v][k]) u=f[u][k],v=f[v][k];
    return pa[u];
}

inline void ColorEdgesFromQuery1(int &id,const int &c){
    while(id<n && e[id].w<=c){
        int u=e[id].x,v=e[id].y;
        if(pa[v]==u) swap(u,v);
        bit1.Update(L[u],R[u],1);
        id++;
    }
}

inline void ColorEdgesFromQuery2(int &id,const int &c){
    while(id<n && e[id].w<=c){
        int u=e[id].x,v=e[id].y;
        if(pa[v]!=u) swap(u,v);
        bit2.Update(L[u],1);
        id++;
    }
}

inline void SolveQuery1(const int &qId, const int &a, const int &b, const int &c){
    static int edgeId=1;
    ColorEdgesFromQuery1(edgeId,c);
    result[qId]=bit1.Get(L[a])+bit1.Get(L[b])-2*bit1.Get(L[Lca(a,b)]);
}

inline int Calc(const int &u){
    return bit2.Get(R[u])-bit2.Get(L[u]-1);
}

inline void SolveQuery2(const int &qId, const int &eId, const int &c){
    static int edgeId=1;
    ColorEdgesFromQuery2(edgeId,c);
    int u=e[eId].x, v=e[eId].y;
    if(pa[v]==u) result[qId]=Calc(v);
    else result[qId]=Calc(1)-Calc(u)-1;
}

inline void Solve(){
    up(i,1,m){
        if(q[i].type=='P') SolveQuery1(q[i].id,q[i].a,q[i].b,q[i].c);
        else SolveQuery2(q[i].id,edgesID[q[i].i],q[i].c);
    }
    up(i,1,m) Write(result[i]),putchar('\n');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "NETWORK"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}
