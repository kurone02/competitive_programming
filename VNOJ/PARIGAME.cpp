#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a);i>int(b);i--)
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
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=5e2+7;
const int maxm=3e6;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n;
int a[maxn][maxn];
ll b[maxn][maxn];
bool f[maxn][maxn];

inline void enter(){
    cin>>n;
    up(i,1,n) up(j,1,n) cin>>a[i][j],b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
}

inline ll vertical(const int &i,const int &j){
    return b[i][j]-b[i-1][j];
}

inline ll horizontal(const int &i,const int &j){
    return b[i][j]-b[i][j-1];
}

inline void init(){
    up(i,1,n)
        f[i][1]=(vertical(i,1)%2==0),
        f[1][i]=(horizontal(1,i)%2==0);
    up(i,1,n){
        up(j,1,n){
            bool x=(!f[i-1][j])&&(vertical(i,j)%2==0),
                 y=(!f[i][j-1])&&(horizontal(i,j)%2==0);
            f[i][j]=x||y;
        }
    }
}

inline void solve(){
    if(f[n][n]) cout<<"YES\n";
    else cout<<"NO\n";
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
    int t;cin>>t;
    while(t--)
    enter(),
    init(),
    solve();
    return 0;
}
