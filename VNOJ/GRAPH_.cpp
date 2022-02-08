#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
#define READ(a,b,c) _read(a),_read(b),_read(c)

const int maxn=1e5+7;
const int Nblocks=400;
const int maxS=(1<<6);
const ll mod=1e9;
const int inf=1e9+7;
const ll linf=1e16+9;

int n,m,low[maxn],num[maxn],nBridges,nCuts;
bool IsBridge[maxn],IsCut[maxn];
struct Neko{int x,y;bool del;}e[maxn];
vector<int> a[maxn];

inline void Enter(){
    Read(n,m);
    up(i,1,m){
        Read(e[i].x,e[i].y); e[i].del=false;
        a[e[i].x].pb(i);
        a[e[i].y].pb(i);
    }
}

inline void Minimize(int &Target, const int &Value){
    if(Target>Value) Target=Value;
}

inline void Dfs(int u){
    static int Visits=0;
    bool IsRoot=(num[u]==-2);
    num[u]=++Visits;
    low[u]=inf;
    int nBranches=0;
    rep(meow,0,a[u].size()){
        int i=a[u][meow];
        if(e[i].del) continue;
        e[i].del=true;
        int v=e[i].x+e[i].y-u;
        if(num[v]==-1){
            Dfs(v);
            Minimize(low[u],low[v]);
            IsBridge[i]=(low[v]>=num[v]);
            IsCut[u]|=(low[v]>=num[u]);
            nBranches++;
        } else Minimize(low[u],num[v]);
    }
    if(IsRoot && nBranches<2) IsCut[u]=false;
}

inline void Solve(){
    fill(num,num+n+1,-1);
    up(i,1,n) if(num[i]==-1) num[i]=-2,Dfs(i);
    up(i,1,n) nCuts+=IsCut[i];
    up(i,1,m) nBridges+=IsBridge[i];
    cout<<nCuts<<' '<<nBridges;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Solve();

    return 0;
}
