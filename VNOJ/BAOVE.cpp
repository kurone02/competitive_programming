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

const int maxn=5e3+7;
const int maxm=2e4+7;
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

int n,m,s,t,minCut;
int h[maxn];
struct Neko{int x,y,cf;}e[maxm];
vector<int> adj[maxn];
vector<int>::iterator current[maxn];

inline void Enter(){
    cin>>n; s=n,t=1;
    int u,v,w;
    while(cin>>u>>v>>w){
        e[2*m]={u,v,w};
        adj[u].pb(2*m);
        e[2*m+1]={v,u,0};
        adj[v].pb(2*m+1);
        m++;
    }
}

inline void Init(){

}

inline void Bfs(){
    fill(h,h+n+1,-1);
    queue<int> q;
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

inline int Dfs(const int &u,int flowIn){
    if(u==t) return flowIn;
    int flowOut=0;
    for(;current[u]!=adj[u].end();current[u]++){
        int i=*current[u];
        int v=e[i].y;
        if(e[i].cf==0 || h[v]!=h[u]-1) continue;
        int q=Dfs(v,min(flowIn,e[i].cf));
        flowIn-=q;
        flowOut+=q;
        e[i].cf-=q;
        e[i^1].cf+=q;
        if(flowIn==0) break;
    }
    return flowOut;
}

inline void BlockingFlow(){
    up(i,1,n) current[i]=adj[i].begin();
    minCut+=Dfs(s,inf);
}

inline void Solve(){
    while(Bfs(),h[s]!=-1) BlockingFlow();
    cout<<minCut;
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
