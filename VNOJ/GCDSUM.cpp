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
const int maxn=1e6+7;
const int maxm=1e6+7;
const int maxalpha=26;
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

int n;
int phi[maxn];
ll f[maxn];

inline void enter(){

}

inline void prepare(){
    rep(i,1,maxn) phi[i]=i;
    rep(i,2,maxn){
        if(phi[i]==i){
            for(int j=i;j<maxn;j+=i) phi[j]-=phi[j]/i;
        }
    }
    up(i,1,10) cerr<<phi[i]<<'\n';
    rep(i,1,maxn) for(int j=2;i*j<maxn;j++) f[i*j]+=i*phi[j];
    rep(i,2,maxn) f[i]+=f[i-1];
}

inline void solve(){
    while(cin>>n){
        if(n==0) return;
        cout<<f[n]<<'\n';
    }
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
