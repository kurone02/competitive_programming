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

const int maxn=5e2+7;
const int maxm=2e4+7;
const ll mod=1e9+7;
const ll base=257;
const int inf=1e9+7;
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

int n,m,s,t,nEdges;
ll minCut,profit;
int h[maxn];
struct Neko{int x,y;ll cf;}e[2*maxm];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];

inline void AddEdge(const int &u, const int &v, const int &w){
    e[2*nEdges]={u,v,w};
    adj[u].pb(2*nEdges);
    e[2*nEdges+1]={v,u,0};
    adj[v].pb(2*nEdges+1);
    nEdges++;
}

inline void Enter(){
    Read(n);
    s=0,t=n+1;
    up(i,1,n){
        int x;
        Read(x);
        if(x>0) AddEdge(s,i,x),profit+=x;
        else AddEdge(i,t,-x);
    }
    Read(m);
    up(i,1,m){
        int u,v;
        Read(u); Read(v);
        AddEdge(u,v,inf);
    }
}

inline void Bfs(){
    queue<int> q;
    fill(h,h+n+2,-1);
    q.push(t);
    h[t]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i: adj[u]){
            i^=1;
            int v=e[i].x;
            if(e[i].cf==0 || h[v]!=-1) continue;
            h[v]=h[u]+1;
            if(v==s) return;
            q.push(v);
        }
    }
}

inline ll Dfs(const int &u, ll flowIn){
    if(u==t) return flowIn;
    ll flowOut=0;
    for(;current[u]!=adj[u].end();current[u]++){
        int i=*current[u];
        int v=e[i].y;
        if(e[i].cf==0 || h[v]!=h[u]-1) continue;
        ll q=Dfs(v,min(e[i].cf,flowIn));
        flowIn-=q;
        flowOut+=q;
        e[i].cf-=q;
        e[i^1].cf+=q;
        if(flowIn==0) break;
    }
    return flowOut;
}

inline void BlockingFlow(){
    up(u,0,n+1) current[u]=adj[u].begin();
    minCut+=Dfs(s,inf);
}

inline void Solve(){
    while(Bfs(),h[s]!=-1) BlockingFlow();
    profit-=minCut;
    cout<<profit;
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
    Solve();

    return 0;
}
