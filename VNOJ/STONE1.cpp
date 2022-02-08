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
const int maxn=4e2+7;
const int maxm=3e5+7;
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
int f[maxn];

inline void enter(){
    cin>>n;
    int u;
    while(cin>>u){
        int m,v;
        cin>>m; up(i,1,m) cin>>v, a[u].pb(v);
    }
}

inline void dfs(int u){
    if(!a[u].size()){
        f[u]=1;
        return;
    }
    vi child;
    rep(i,0,a[u].size()){
        int v=a[u][i];
        dfs(v);
        child.pb(f[v]);
    }
    sort(child.begin(),child.end(),greater<int>());
    int carry=0;
    rep(i,0,child.size()){
        if(carry<child[i]){
            f[u]+=child[i]-carry;
            carry=child[i]-1;
        } else carry--;
    }
}

inline void prepare(){
    dfs(1);
}

inline void solve(){
    cout<<f[1];
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
