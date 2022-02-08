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
 
int n;
struct Neko{
    int val,id;
}a[maxn];
int kq;
int d[maxn];
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
    cin>>n;
    up(i,1,n) cin>>a[i].val,a[i].id=i;
}
 
inline bool ss(Neko x,Neko y){
    return (x.val==y.val)? x.id<y.id : x.val>y.val;
}
 
inline void prepare(){
    sort(a+1,a+n+1,ss);
    up(i,1,n){
        kq+=get(a[i].id)-d[a[i].val];
        d[a[i].val]++;
        update(a[i].id);
        //cerr<<kq<<'\n';
    }
}
 
inline void solve(){
    cout<<kq;
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