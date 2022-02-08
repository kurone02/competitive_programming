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
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;typedef vector<vi> vvi;typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;typedef map<bool, int> mbi;typedef map<string, int> msi;
typedef vl big;
/*----------------------------------------------*/
const int maxn=2e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int t;
int u,v;
const int f[]={1,2,3,5,1,6,0,6,6,5,4,2,6,1,0,1};

inline int solve(int l,int h){
    l--,h--;
    int k=(h-l+1)/16;
    if(k>=2) return 16*k;
    int limit=min(l+20,h);
    up(i,l+1,limit)
        if(f[i%16]==f[(i+15)%16]) return 2;
    return -1;
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
   // #define OfflineJudge
    #ifdef OfflineJudge
    file();
    #endif
    cin>>t;
    while(t--) cin>>u>>v,cout<<solve(u,v)<<'\n';
    return 0;
}
