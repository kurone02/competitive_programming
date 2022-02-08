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
const int maxn=5e4+7;
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
 
int n,i;
ll t,k;
string kq;
 
inline void enter(){
    cin>>n>>t;
}
 
inline void prepare(){
    i=1;
    ll p=1;
    while(t>9*p*i){
        t-=9*p*i;
        p*=10;
        i++;
    }
    k=p+(t-1)/i;
    t%=i;
}
 
inline string nts(ll x){
    if(x==0) return "0";
    string res;
    while(x){
        res.pb(x%10+'0');
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
 
inline void solve(){
    prepare();
    while(kq.size()<n&&k){
        kq=nts(k)+kq;
        if(t) kq.erase(t,i-t),t=0;
        k--;
    }
    while(kq.size()>n) kq.erase(0,1);
    while(kq.size()<n) kq=' '+kq;
    cout<<kq;
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