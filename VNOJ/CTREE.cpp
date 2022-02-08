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
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef vector<pii> vii;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=1e4+7;
const int maxm=2e5+7;
const ll linf=1e16; const int inf=2e9;
const ll MOD=1e9+7;
const double esp=1e-7;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
template<typename T> inline void read(T &x){
    char ch; x=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
}
/*----------------------------------------------*/
 
int n;
vi a[maxn];
bool c[maxn];
vi child[maxn];
int f[maxn][3];
int color[maxn],kq;
 
inline void enter(){
    read(n);
    rep(i,1,n){
        int u,v;
        read(u);read(v);
        a[u].pb(v);
        a[v].pb(u);
    }
}
 
inline void dfs(int u){
    c[u]=true;
    //cerr<<a[u].size()<<'\n';
    rep(cl,0,3) f[u][cl]=cl+1;
    rep(i,0,a[u].size()){
        int v=a[u][i];
        if(!c[v]){
            dfs(v);
            child[u].pb(v);
            rep(cl,0,3){
                int tmp=inf;
                if(cl==0) tmp=min(f[v][1],f[v][2]);
                if(cl==1) tmp=min(f[v][0],f[v][2]);
                if(cl==2) tmp=min(f[v][1],f[v][0]);
                f[u][cl]+=tmp; //cerr<<"f["<<u<<"]["<<cl<<"]= "<<f[u][cl]<<'\n';
            }
        }
    }
}
 
inline void trace(int u){
    c[u]=true;
    rep(i,0,a[u].size()){
        int v=a[u][i];
        if(!c[v]){
            int tmp=inf;
            rep(cl,0,3) if(cl!=color[u])
                if(tmp>f[v][cl]) tmp=f[v][cl],color[v]=cl;
            trace(v);
        }
    }
}
 
inline void solve(){
    dfs(1);
    kq=inf;
    rep(i,0,3)
        if(kq>f[1][i]) kq=f[1][i],color[1]=i;
    cout<<kq<<'\n';
    fill(c,c+n+1,false);
    trace(1); up(i,1,n) cout<<color[i]+1<<'\n';
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
    solve();
    return 0;
}