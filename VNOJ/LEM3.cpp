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
const int maxn=17;
const int maxm=1<<maxn;
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
int f[maxm][maxn];
int kq=inf;

inline void enter(){
    cin>>n;
    rep(i,0,n) rep(j,0,n) cin>>a[i][j];
}

inline void solve(){
    int maxS=(1<<n)-1;
    up(state,0,maxS) if(__builtin_popcount(maxS)>1){
        rep(i,0,n) if(getbit(state,i)){
            int NewState=offbit(state,i);
            f[state][i]=inf;
            rep(j,0,n) if(getbit(state,j)&&i!=j)
                    f[state][i]=min(f[state][i],f[NewState][j]+a[j][i]);
                    //cout<<state<<' '<<NewState<<'\n';
            if(f[state][i]==inf) f[state][i]=0;
            //cerr<<"f["<<NewState<<"]["<<j<<"]= "<<f[NewState][j]+a[j][i]<<'\n';
        }
    }
    rep(i,0,n) kq=min(kq,f[maxS][i]);
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
