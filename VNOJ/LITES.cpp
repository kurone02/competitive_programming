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
const int maxm=1e3+6;
const ll linf=1e16; const int inf=2e9;
const ll mod=20122007;
const long double pi=4*atan((long double)1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return (x>>k)&1;}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n,q;
int a[maxn],L[maxn],H[maxn];
struct Neko{
    int tt;
    int on;
}it[4*maxn];

inline void build(int x,int low,int high){
    if(low>high) return;
    L[x]=low,H[x]=high;
    if(low==high){
        it[x].tt=0,it[x].on=0;
        return;
    }
    int mid=(low+high)>>1;
    build(CL(x),low,mid);
    build(CR(x),mid+1,high);
}

inline void pushdown(int x){
    it[CL(x)].tt^=it[x].tt;
    it[CR(x)].tt^=it[x].tt;
    if(it[x].tt) it[x].on=H[x]-L[x]+1-it[x].on;
    it[x].tt=0;
}

inline void update(const int x,const int u,const int v){
    if(L[x]>v||H[x]<u){
        pushdown(x);
        return;
    }
    if(L[x]>=u&&H[x]<=v){
        it[x].tt=1-it[x].tt;
        pushdown(x);
        return;
    }
    int mid=(L[x]+H[x])>>1;
    pushdown(x);
    update(CL(x),u,v);
    update(CR(x),u,v);
    it[x].on=it[CL(x)].on+it[CR(x)].on;
}

inline int query(int x,int u,int v){
    if(u>H[x]||v<L[x]) return 0;
    if(L[x]>=u&&H[x]<=v) return (it[x].tt)? H[x]-L[x]+1-it[x].on : it[x].on;
    int mid=(L[x]+H[x])>>1;
    pushdown(x);
    return query(CL(x),u,v)+query(CR(x),u,v);
}

inline void enter(){
    scanf("%d%d",&n,&q);
    build(1,1,n);
}

inline void solve(){
    int type,a,b;
    scanf("%d%d%d",&type,&a,&b);
    if(!type) update(1,a,b);
    else cout<<query(1,a,b)<<'\n';
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
    while(q--) solve();
    return 0;
}
