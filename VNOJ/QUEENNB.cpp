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
const int maxn=1e3+7;
const int maxm=1e6+6;
const ll linf=1e16; const int inf=2e9;
const ll mod=20122007;
const long double pi=4*atan((long double)1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return (x>>k)&1;}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int m,n;
bool a[maxn][maxn];
int f[maxn][maxn];
int c[maxn][maxn],r[maxn][maxn],d1[maxn][maxn],d2[maxn][maxn];

inline void enter(){
    cin>>m>>n;
    up(i,1,m) up(j,1,n){
        char ch; cin>>ch;
        a[i][j]=(ch=='.');
    }
}

inline void solve(){
    up(i,1,m) up(j,1,n){
        if(!a[i][j]) continue;
        c[i][j]=c[i-1][j]+1;
        r[i][j]=r[i][j-1]+1;
        d1[i][j]=d1[i-1][j-1]+1;
        d2[i][j]=d2[i-1][j+1]+1;
        f[i][j]=c[i][j]+r[i][j]+d1[i][j]+d2[i][j]-4;
    }
    memset(c,0,sizeof c);
    memset(r,0,sizeof r);
    memset(d1,0,sizeof d1);
    memset(d2,0,sizeof d2);
    down(i,m,1) down(j,n,1){
        if(!a[i][j]) continue;
        c[i][j]=c[i+1][j]+1;
        r[i][j]=r[i][j+1]+1;
        d1[i][j]=d1[i+1][j+1]+1;
        d2[i][j]=d2[i+1][j-1]+1;
        f[i][j]+=c[i][j]+r[i][j]+d1[i][j]+d2[i][j]-3;
    }
    for(int i=1;i<=m;i++,cout<<'\n') up(j,1,n) cout<<f[i][j]<<' ';
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
