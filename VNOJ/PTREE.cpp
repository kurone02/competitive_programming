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
const int maxn=2e2+7;
const int maxm=3e5+7;
const ll linf=1e16; const int inf=1e9;
const ll mod=1e9+7;
const double esp=1e-9;
const double pi=4*atan((double)1);
/*----------------------------------------------*/
template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
/*----------------------------------------------*/

int n,p;
int c[maxn];
vi a[maxn];
bool chk[maxn],adj[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn];
vi kq;

inline void enter(){
    Read(n,p);
    up(i,1,n) read(c[i]);
    up(i,1,n-1){
        int u,v;
        Read(u,v);
        a[u].pb(v);
        a[v].pb(u);
        adj[u][v]=adj[v][u]=true;
    }
}

inline void dfs(int u){
    chk[u]=true;
    f[u][1]=c[u];
    up(v,1,n){
        if(!adj[u][v]) continue;
        adj[v][u]=false;
        dfs(v);
        down(i,p,1){
            rep(j,1,i){
                if(f[u][i]<f[u][j]+f[v][i-j]){
                    f[u][i]=f[u][j]+f[v][i-j];
                    //cout<<f[u][i]<<'\n';
                    g[v][i]=i-j;
                }
            }
        }
    }
}

inline void trace(int u,int P){
    //cerr<<u<<' ';
    down(v,n,1)if(adj[u][v] && g[v][P]>0){
        trace(v,g[v][P]);
        P-=g[v][P];
    }
    kq.pb(u);
}

inline void prepare(){
    fill_n(&f[0][0],sizeof(f)/sizeof(f[0][0]),-inf);
    dfs(1);
    fill(chk,chk+n+1,false);
}

inline void solve(){
    int vertex=1,mx=f[1][p];
    up(i,2,n){
        //cerr<<f[i][p]<<'\n';
        if(f[vertex][p]<f[i][p]) vertex=i,mx=f[i][p];
    }
    //cerr<<vertex<<'\n';
    trace(vertex,p);
    //cout<<mx<<'\n';
}

inline void Print(){
    int tmp=0;
    fill(chk,chk+n+1,false);
    repd(i,kq.size(),0){
        /*if(chk[kq[i]]){
            cerr<<"wrong\n";
            break;
        }*/
        cout<<kq[i]<<' ',tmp+=c[kq[i]],chk[kq[i]]=true;
    }
    //cerr<<tmp<<'\n';
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
    prepare();
    solve();
    Print();
    return 0;
}
