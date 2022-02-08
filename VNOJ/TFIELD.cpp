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
const int maxn=1e3+7;
const int maxm=30;
const ll linf=1e16; const int inf=2e9;
const ll MOD=1e9+7;
const double esp=1e-7;
const long double pi=4*atan((long double)1);
const int as=6e3;
/*----------------------------------------------*/
template<typename T> inline void read(T &x){
    char ch; x=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
}
/*----------------------------------------------*/

int m,k,n;
pli a[maxn];
int x[maxn],y[maxn];
int d[maxn];
ll kq;

inline ll area(){
    ll res=0;
    x[n+1]=x[1],y[n+1]=y[1];
    up(i,1,n) res+=(ll)((ll)x[i]-x[i+1])*(y[i]+y[i+1]);
    return (res>0)? res : -res;
}

inline void enter(){
    cin>>m>>k;
    up(i,1,m){
        int c;
        cin>>n>>c;
        up(i,1,n) cin>>x[i]>>y[i];
        a[i]=make_pair(area(),c);
    }
    sort(a+1,a+m+1);
}

inline void solve(){
    up(i,1,m){
        int mx=0;
        fill(d,d+m+1,0);
        up(j,i,m){
            d[a[j].Y]++;
            mx=max(mx,d[a[j].Y]);
            if(j-i+1-mx<=k) kq=max(kq,a[j].X-a[i-1].X);
        }
    }
    cout<<fixed<<setprecision(1)<<(double)kq/2;
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
    solve();
    return 0;
}
