#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=1e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n,m;
int a[maxn][maxn];
int f[maxn][maxn];
int kq;

inline void enter(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n;
    up(i,1,m) up(j,1,n) cin>>a[i][j],f[i][j]=1;
}

inline bool chk(int i,int j){
    return a[i][j]==a[i-1][j-1]&&a[i-1][j]==a[i][j]&&a[i][j-1]==a[i][j];
}

inline void solve(){
    up(i,1,m){
        up(j,1,n){
            if(chk(i,j)) f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
            kq=max(kq,f[i][j]);
        }
    }
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
    //#define OfflineJudge
    #ifdef OfflineJudge
    file();
    #endif
    enter();
    solve();
    return 0;
}
