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
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef vector<pii> vii;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=3e5+7;
const int maxm=3e5+7;
const ll linf=1e16; const int inf=2e9;
const ll MOD=1e9+7;
const double esp=1e-7;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
template<typename T> inline void read(T &x){
    char ch; x=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
}
/*----------------------------------------------*/
 
int n,Q;
struct Neko{
    int l,r,k,id,type;
}q[maxn];
int kq[maxm];
int bit[maxn];
 
inline void update(int x){
    for(;x<=n;x+=x&(-x)) bit[x]++;
}
inline int get(int x){
    int tmp=0;
    for(;x;x-=x&(-x)) tmp+=bit[x];
    return tmp;
}
 
inline void enter(){
    read(n);
    up(i,1,n) read(q[i].k),q[i].l=q[i].r=i,q[i].type=0;
    read(Q);
    up(i,n+1,Q+n) read(q[i].l),read(q[i].r),read(q[i].k),q[i].id=i-n,q[i].type=1;
}
 
inline bool ss(Neko x,Neko y){
    return (x.k==y.k)? x.type>y.type : x.k>y.k;
}
 
inline void prepare(){
    sort(q+1,q+Q+n+1,ss);
    up(i,1,n+Q){
        if(!q[i].type) update(q[i].l);
        else kq[q[i].id]=get(q[i].r)-get(q[i].l-1);
    }
}
 
inline void solve(){
    up(i,1,Q) cout<<kq[i]<<'\n';
}
 
inline void file(){
    #define task "TEST"
    //#define task1 "TEST"
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
    prepare();
    solve();
    return 0;
}