#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<bool, int> mbi;
/*----------------------------------------------*/
const int maxn=1e5+10;
const int maxt=2e5+10;
const ll linf=1e16;
const int inf=2e9;
const int mod=111539786;
const double pi=4*atan(1);
const bool OnlineJudge=1;
const int mxs=2;
const int as=2e2;
/*----------------------------------------------*/
struct cord{
    int x,y;
};
struct line{
    ll a,b,c;
};
/*----------------------------------------------*/

int n,m;
vi a[maxn];
bool c[maxn],chk[maxn];
stack<int> s;
vi res;
int kq;

inline void init(){
    cin>>n>>m;
    int u,v;
    up(i,1,m){
        cin>>u>>v;
        a[u].pb(v);
    }
}

inline void dfs(int u){
    c[u]=true;
    for(int v: a[u]){
        if(!c[v]) dfs(v);
    }
    s.push(u);
}

inline void Dfs(int u){
    chk[u]=true;
    for(int v: a[u]){
        if(!chk[v]) Dfs(v);
    }
}

inline void prepare(){
    up(i,1,n) if(!c[i]) dfs(i);
    while(s.size()){
        int v=s.top();s.pop();
        //cout<<v<<' ';
        if(chk[v]) continue;
        Dfs(v);
        res.pb(v);
        kq++;
    }
}

inline void solve(){
    cout<<kq;
}

inline void file(){
    #define task "MESSAGE"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    if(!OnlineJudge) file();
    init();
    prepare();
    //while(k--)
    solve();
    return 0;
}
