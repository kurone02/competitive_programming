#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<char,int> pci;

const int maxn=2e5+7;
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
    if(x<0) putchar('-'),x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int n,m,s,t,result,trace[maxn];
vector<int> adj[maxn];
struct Neko{int x,y,cf;}e[maxn];

inline void Enter(){
    cin>>n>>m>>s>>t;
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        e[2*i]={u,v,w};
        adj[u].pb(2*i);
        e[2*i+1]={v,u,0};
        adj[v].pb(2*i+1);
    }
}

inline bool FindPath(){
    fill(trace,trace+n+2,-1);
    trace[s]=-2;
    queue<int> q;
    q.push(s);
    do{
        int u=q.front();
        q.pop();
        for(int i: adj[u]){
            int v=e[i].y;
            if(e[i].cf>0 && trace[v]==-1){
                trace[v]=i;
                if(v==t) return true;
                q.push(v);
            }
        }
    } while(q.size());
    return false;
}

inline void IncrementFlow(){
    int u,i;
    int delta=inf;
    for(u=t;(i=trace[u])>=0;u=e[i].x) delta=min(delta,e[i].cf);
    for(u=t;(i=trace[u])>=0;u=e[i].x)
        e[i].cf-=delta,
        e[i^1].cf+=delta;
    result+=delta;
}

inline void Solve(){
    while(FindPath()) IncrementFlow();
    cout<<result;
}

inline void Main(){
    Enter();
    Solve();
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
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
    Execution_Time_Calculator(0);

    return 0;
}
