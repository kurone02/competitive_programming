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
const int maxn=1e6+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n;
struct Vector{
    int x,y;
}a[maxn];
int f[maxn];
int kq;

inline void enter(){
    cin>>n;
    up(i,1,n) cin>>a[i].x>>a[i].y;
}

inline Vector operator -(Vector A,Vector B){
    Vector res; res.x=B.x-A.x,res.y=B.y-A.y;
    return res;
}

inline ll operator *(Vector A,Vector B){
    return (ll)A.x*B.y-(ll)A.y*B.x;
}

inline bool Line(Vector A,Vector B, Vector C){
    Vector AB=A-B;
    Vector AC=A-C;
    return AB*AC==0;
}

inline void solve(){
    up(i,1,n) up(j,i+1,n) up(k,j+1,n) if(!Line(a[i],a[j],a[k])) kq++;
    up(i,1,n)
        up(j,1,n) if(i!=j)
            up(k,1,n) if(i!=k&&j!=k&&!Line(a[i],a[j],a[k])) f[i]++;
    int cs=0,tmp=inf;
    up(i,1,n) if(tmp>f[i]) cs=i,tmp=f[i];
    cout<<kq<<' '<<cs;
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
