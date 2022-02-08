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
#define All(x) x.begin(),x.end()
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=2e5+7;
const int maxl=5e3+7;
const int base=237;
const ll mod=1e9+7;
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

int n,m,nBridges,nCC,C1,C2;
int low[maxn],num[maxn],nChild[maxn];
bool visited[maxn],isBridge[maxn];
struct Neko{int x,y;bool del;}e[maxn];
vector<int> adj[maxn];

inline void Enter(){
    cin>>n>>m;
    up(i,1,m){
        cin>>e[i].x>>e[i].y;
        e[i].del=false;
        adj[e[i].x].pb(i);
        adj[e[i].y].pb(i);
    }
}

inline void FindBridge(const int &u){
    static int nVisit=0;
    num[u]=++nVisit;
    low[u]=inf;
    nChild[u]=1;
    visited[u]=true;
    for(int i: adj[u]){
        if(e[i].del) continue;
        int v=e[i].x+e[i].y-u;
        e[i].del=true;
        if(visited[v]) low[u]=min(low[u],num[v]);
        else{
            FindBridge(v);
            low[u]=min(low[u],low[v]);
            nChild[u]+=nChild[v];
            nBridges+=low[v]>=num[v];
        }
    }
};

inline void Count_CC(const int &u){
    visited[u]=true;
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(!visited[v]) Count_CC(v);
    }
}

inline void Init(){
    up(i,1,n) if(!visited[i]) Count_CC(i),nCC++;
    if(nCC>2) cout<<0,exit(0);
    fill(visited,visited+n+1,false);
    up(i,1,n) if(!visited[i]) FindBridge(i);
}

inline ll Solve1(){
    /// Add edges then Delete edges -> (n*(n-1)/2 - m) * (m-nBridges)
    /// Delete edges then Add edges -> nBridges*sum(Cu*Cv-m,(u,v) in E)
    ll res=0;
    function<void(int)> Dfs=[&](const int &u){
        visited[u]=true;
        for(int i: adj[u]){
            int v=e[i].x+e[i].y-u;
            if(visited[v]) continue;
            Dfs(v);
            if(low[v]>=num[v]){
                res+=1ll*nChild[v]*(n-nChild[v])-1;
//                cerr<<u<<' '<<v<<' '<<nChild[v]<<' '<<nBridges<<'\n';
            }
        }
    };
    fill(visited,visited+n+1,false);
    Dfs(1);
    res+=(1ll*n*(n-1)/2-m)*(m-nBridges);
    return res;
}

inline ll Solve2(){
    fill(visited,visited+n+1,false);
    function<void(int)> Dfs=[&](const int &u){
        C1++;
        visited[u]=true;
        for(int i: adj[u]){
            int v=e[i].x+e[i].y-u;
            if(!visited[v]) Dfs(v);
        }
    };
    Dfs(1);
    C2=n-C1;
    return 1ll*C1*C2*(m-nBridges);
}

inline void Solve(){
    if(nCC==1) cout<<Solve1();
    else cout<<Solve2();
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
