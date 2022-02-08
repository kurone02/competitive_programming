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
const int maxn=1e6+7;
const int maxm=1e6+7;
const int maxalpha=26;
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

int n;
int a[maxn];
bool c[maxn],rc[maxn],scc[maxn];
int f[maxn];
stack<int> s;

inline void enter(){
    cin>>n;
    up(i,1,n) cin>>a[i];
}

inline void rdfs(int u){
    rc[u]=true; s.push(u); //cerr<<u<<'\n';
    int v=a[u];
    if(!rc[v] && c[v]) rdfs(v);
    //cerr<<'\n';
}

inline void dfs(int u){
    c[u]=true;
    int v=a[u];
    if(c[v] && !f[v]){
        rdfs(v);
        int length=s.size(); //cerr<<"length= "<<length<<'\n';
        while(s.size()) scc[s.top()]=true,f[s.top()]=length,s.pop();
    } else{
        if(!c[v]) dfs(v);
        if(!scc[u]) f[u]=f[v]+1;
    }
}

inline void prepare(){
    up(i,1,n) if(!c[i]) dfs(i);
}

inline void solve(){
    up(i,1,n) cout<<f[i]<<'\n';
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
    return 0;
}
