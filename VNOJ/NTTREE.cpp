#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef vector<pii> vii;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=2e5+7;
const int maxm=3e5+7;
const ll linf=1e16; const int inf=2e9;
const ll mod=1e9+7;
const double esp=1e-9;
const double pi=4*atan((double)1);
/*----------------------------------------------*/
template<typename T> inline void read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
/*----------------------------------------------*/

int n;
vii a[maxn];
ll f[maxn],g[maxn];
bool c[maxn];
ll kq;

inline void enter(){
    cin>>n;
    rep(i,1,n){
        int u,v,w;
        cin>>u>>v>>w;u++,v++;
        a[u].pb(pii(v,w));
        a[v].pb(pii(u,w));
    }
}

inline void dfs(int u){
    rep(i,0,a[u].size()){
        int v=a[u][i].first;
        if(!c[v]){
            c[v]=true;
            dfs(v);
            kq+=f[u]*(g[v]+1)+(f[v]+(g[v]+1)*a[u][i].second)*g[u];
            f[u]+=f[v]+(g[v]+1)*a[u][i].second;
            g[u]+=g[v]+1;
        }
    }
    kq+=f[u];
}

inline void solve(){
    c[1]=true;dfs(1);
}

inline void Print(){
    up(i,1,n) cerr<<"f["<<i<<"]= "<<f[i]<<'\n';
    cout<<kq;
}

inline void file(){
    #define task "TEST"
    //#define task1 "TEST"
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
    solve(),
    Print();
    return 0;
}
