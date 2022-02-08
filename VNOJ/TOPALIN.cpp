#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e4+7;
const int maxm=1e4+7;
const ll mod=123456789;
const int inf=1e9;

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

int n,mx,sum,res,sz[225];
bool c[225];
vector<int> adj[225];
string s;

inline void Enter(){
    cin>>s;
    n=s.size();
    s=' '+s;
}

inline void Init(){
    up(i,1,n) sz[s[i]]++;
    for(int i=1;2*i<=n;i++)
        if(s[i]!=s[n-i+1])
            adj[s[i]].pb(s[n-i+1]),
            adj[s[n-i+1]].pb(s[i]);
}

inline void Dfs(const int &u){
    c[u]=true;
    mx=max(mx,sz[u]);
    sum+=sz[u];
    for(int v: adj[u]) if(!c[v]) Dfs(v);
}

inline void Solve(){
    up(i,1,n) if(!c[s[i]]) mx=sum=0,Dfs(s[i]),res+=sum-mx;
    cout<<res;
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
//

    Enter();
    Init();
    Solve();

    return 0;
}
