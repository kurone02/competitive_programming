#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) (x<<1)
#define CR(x) (x<<1|1)
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
 
int n,m,q;
int in[maxn],out[maxn],pos[maxn];
int L[4*maxn],R[4*maxn],it[4*maxn];
int res[maxn],last[maxn];
bitset<maxn> avail;
struct Neko{int x,y;}e[maxn];
vector<int> adj[maxn];
 
inline void Enter(){
    Read(n); Read(m); Read(q);
    rep(i,1,n){
        Read(e[i].x); Read(e[i].y);
        adj[e[i].x].pb(e[i].y);
        adj[e[i].y].pb(e[i].x);
    }
}
 
inline void Build(const int &x, const int &low, const int &high){
    if(low>high) return;
    L[x]=low; R[x]=high;
    if(low==high){
        it[x]=out[pos[low]];
        return;
    }
    int mid=(low+high)>>1;
    Build(CL(x),low,mid);
    Build(CR(x),mid+1,high);
    it[x]=max(it[CL(x)],it[CR(x)]);
}
 
inline void Update(const int &x, const int &p, const int &v){
    if(L[x]>p || R[x]<p) return;
    if(L[x]==R[x]){
        it[x]=v;
        return;
    }
    Update(CL(x),p,v);
    Update(CR(x),p,v);
    it[x]=max(it[CL(x)],it[CR(x)]);
}
 
inline int Get(const int &x, const int &p, const int &v){
    if(L[x]>p || it[x]<v) return -1;
    if(L[x]==R[x]) return pos[L[x]];
    int childRight=Get(CR(x),p,v);
    if(childRight!=-1) return childRight;
    return Get(CL(x),p,v);
}
 
inline void Init(){
    function<void(int)> Dfs=[&](const int &u){
        static int nVisit=0;
        in[u]=++nVisit;
        pos[nVisit]=u;
        for(int v: adj[u]) if(!in[v]) Dfs(v);
        out[u]=nVisit;
    };
    Dfs(1);
    Build(1,1,n);
    fill(res,res+n+1,1);
}
 
inline void ChangeState(const int &eid, int u, int v){
    if(!avail[eid]){
        if(in[u]>in[v]) swap(u,v);
        int root=Get(1,in[u],out[u]);
        res[root]+=res[v]-last[v];
        Update(1,in[v],0);
        avail.flip(eid);
    } else{
        if(in[u]>in[v]) swap(u,v);
        int root=Get(1,in[u],out[u]);
        res[v]=last[v]=res[root];
        Update(1,in[v],out[v]);
        avail.flip(eid);
    }
}
 
inline void Solve(){
    for(int x;m;m--) Read(x),ChangeState(x,e[x].x,e[x].y);
    for(int x;q;q--) Read(x),Write(res[Get(1,in[x],out[x])]),putchar('\n');
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "SYNCHRONIZATION"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//
 
    Enter();
    Init();
    Solve();
 
    return 0;
}