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
 
const int maxn=1e5+7;
const int maxm=3e5+7;
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
 
int n,m,p,s,t,nVertex,result;
int h[maxn];
vector<int>::iterator current[maxn];
vector<int> adj[maxn];
struct Neko{int x,y,cf;}e[2*maxm];
 
inline void Enter(){
    Read(m); Read(n); Read(p);
    s=0,t=n+m+1;
    nVertex=n+m+2;
    rep(i,0,m){
        e[2*i]={s,i+1,1};
        adj[s].pb(2*i);
        e[2*i+1]={i+1,s,0};
        adj[i+1].pb(2*i+1);
    }
    rep(i,m,m+p){
        int u,v;
        Read(u); Read(v);
        v+=m;
        e[2*i]={u,v,1};
        adj[u].pb(2*i);
        e[2*i+1]={v,u,0};
        adj[v].pb(2*i+1);
    }
    int cnt=1;
    rep(i,m+p,m+p+n){
        e[2*i]={m+cnt,t,1};
        adj[m+cnt].pb(2*i);
        e[2*i+1]={t,m+cnt,0};
        adj[t].pb(2*i+1);
        cnt++;
    }
}
 
inline void Bfs(){
    fill(h,h+nVertex+1,-1);
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
    up(u,0,nVertex+1) current[u]=adj[u].begin();
    result+=Dfs(s,inf);
//    c<<result<<'\n';
}
 
inline void Solve(){
    while(Bfs(),h[s]!=-1) BlockingFlow();
    Write(result);
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