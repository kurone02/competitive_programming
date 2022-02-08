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
const int maxn=3e5+7;
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
struct Neko{int s,e;}a[maxn];
int f[maxn];

inline void enter(){
    cin>>n;
    Neko* q=a+n+1;
    for(Neko* p=a+1;p!=q;p++) cin>>p->s>>p->e;
}

inline bool ss(Neko x,Neko y){
    return x.e<y.e;
}

inline int bs(int l,int h,int x){
    while(l<=h){
        int mid=(l+h)/2;
        if(a[mid].e<=x) l=mid+1;
        else h=mid-1;
    }
    return h;
}

inline void solve(){
    sort(a+1,a+n+1,ss);
    f[1]=a[1].e-a[1].s;
    up(i,2,n){
        int j=bs(1,i-1,a[i].s);
        f[i]=max(f[i-1],a[i].e-a[i].s+f[j]*(j>0));
    }
    cout<<f[n];
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
