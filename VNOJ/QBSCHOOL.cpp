#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii; typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=1e5+7;
const int maxm=1e6+6;
const ll linf=1e16; const int inf=2e9;
const ll mod=20122007;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return (x>>k)&1;}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n,m;
vli a[maxn];
ll d[maxn],f[maxn];

inline void enter(){
    cin>>n>>m;
    up(i,1,m){
        int k,u,v,l;
        cin>>k>>u>>v>>l;
        a[u].pb({l,v});
        if(k==2) a[v].pb({l,u});
    }
}

inline void dij(){
    priority_queue<pli,vector<pli>,greater<pli> > q;
    fill(d,d+n+1,inf);
    d[1]=0;f[1]=1;
    q.push({0,1});
    while(!q.empty()){
        long long dt=q.top().X;
        int u=q.top().Y;
        q.pop();
        if(dt>d[u]) continue;
        for(auto tmp: a[u]){
            long long w=tmp.X;
            int v=tmp.Y;
            if(d[v]==d[u]+w) f[v]+=f[u];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
                f[v]=f[u];
            }
        }
    }
}


inline void solve(){
    dij();
    cout<<d[n]<<' '<<f[n];
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    #define OnlineJudge
    #ifndef OnlineJudge
    file();
    #endif
    enter();
    solve();
    return 0;
}
