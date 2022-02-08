#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef vector<pii> vii;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=5e4+7;
const int maxm=1e6+7;
const int base=653;
const ll linf=1e16; const int inf=1e9;
const ll mod=1e9+7;
const double esp=1e-9;
const double pi=4*atan((double)1);
/*----------------------------------------------*/
template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
/*----------------------------------------------*/

int Test;
ll n,k;
ll a[maxn];

inline void enter(){
    cin>>Test;
}

inline vl PrimeFactor(ll x){
    vl res;
    ll d=2;
    while(d*d<=x){
        ll tmp=1;
        if(x%d==0){
            while(x%d==0) x/=d,tmp*=d;
            res.pb(tmp);
            //cerr<<tmp<<'\n';
        }
        d++;
    }
    if(res.empty() || x>1) res.pb(x);
    return res;
}

inline ll gcd(ll a,ll b){
    if(a<b) swap(a,b);
    return (b==0)? a : gcd(b,a%b);
}

inline void solve(){
    cin>>n;
    up(i,1,n) cin>>a[i];
    cin>>k;
    vl prime=PrimeFactor(k);prime.pb(0);
    vl res; res.resize(prime.size()-1);
    //rep(i,0,prime.size()) cerr<<prime[i]<<' '; cerr<<'\n';
    for(int i=0;int p=prime[i];i++){
        //cerr<<p<<'\n';
        up(j,1,n) if(a[j]%p==0) res[i]=gcd(res[i],a[j]);
    }
    bool chk=true;
    rep(i,0,res.size()) chk&=(res[i] && k%res[i]==0);//cerr<<res[i]<<'\n'; cerr<<'\n';
    if(chk) cout<<"YES\n";
    else cout<<"NO\n";
    fill(a+1,a+n+1,0);
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
    while(Test--) solve();
    return 0;
}
