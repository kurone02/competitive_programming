#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<vi> vvi;typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;typedef map<bool, int> mbi;typedef map<string, int> msi;
typedef vl big;
/*----------------------------------------------*/
const int maxn=20;
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
int f[maxm];

inline void enter(){
    cin>>n;
    up(i,0,n-1) up(j,0,n-1) cin>>a[i][j];
}

inline void solve(){
    int maxS=(1<<n)-1;
    up(state,0,maxS){
        //cerr<<state<<' ';
        up(i,0,n-1)if(offbit(state,i)<state){
            int k=__builtin_popcount(state)-1;
            f[state]=max(f[state],f[offbit(state,i)]+a[i][k]);
            //cerr<<' '<<offbit(state,i)<<' ';
        }
        //cerr<<'\n';
        //cerr<<"f["<<state<<"]= "<<f[state]<<'\n';
    }
    cout<<f[maxS]<<' '<<1;
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
