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
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return (x>>k)&1;}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n;
int a[maxn];
int f[maxn][maxn];
int kq=inf;

inline void enter(){
    cin>>n;
    int* q=a+n+1;
    for(int* p=a+1;p!=q;p++) cin>>*p;
}

inline void solve(){
    up(i,0,n+1) up(j,0,n+1) f[i][j]=inf;
    f[0][0]=0;
    rep(i,0,n) up(j,0,i) if(f[i][j]!=inf){
        if(j) f[i+1][j-1]=min(f[i+1][j-1],f[i][j]);
        f[i+1][j+(a[i+1]>100)]=min(f[i+1][j+(a[i+1]>100)],f[i][j]+a[i+1]);
    }
    up(i,0,n) kq=min(kq,f[n][i]),cerr<<f[n][i]<<'\n';
    cout<<kq;
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
