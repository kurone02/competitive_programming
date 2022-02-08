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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<bool, int> mbi;
typedef vl big;
/*----------------------------------------------*/
const int maxn=17;
const int maxm=17;
const ll linf=1e16;
const int inf=2e9;
const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
struct cord{
    ll x,y;
};
struct line{
    ll a,b,c;
};
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
/*----------------------------------------------*/

int n,m,t;
int f[1<<6][31];
ll kq;

inline void enter(){
    cin>>m>>n;
}

inline bool check(int a,int b,int state) {
    int x=a&b;
    int y=(~a&~b)&state-1;
    return !(x&x>>1)&&!(y&y>>1);
}

inline void solve(int a,int b){
    int maxstate=pow2(b)-1;
    up(state,0,maxstate) f[state][1]=1;
    up(i,2,a){
        up(state,0,maxstate){
            f[state][i]=0;
            up(prestate,0,maxstate){
                if(check(state,prestate,pow2(b))) f[state][i]+=f[prestate][i-1];
            }
        }
    }
    kq=0;
    up(state,0,maxstate) kq+=f[state][a];//cout<<state<<' ';
    cout<<kq<<'\n';
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
    cin>>t;
    while(t--){
        enter();
        solve(max(n,m),min(n,m));
    }
    return 0;
}
