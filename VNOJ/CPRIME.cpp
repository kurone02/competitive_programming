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
const int maxn=1e8+7;
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

int x;
bool c[maxn];
int p[maxn];

inline void enter(){

}

inline void prepare(){
    fill(c+1,c+maxn,true); c[0]=c[1]=false;
    for(int i=2;i<maxn;i++)
        if(c[i]) for(ll j=(ll)i*i;j<maxn;j+=i) c[j]=false;
    rep(i,2,maxn) p[i]=p[i-1]+c[i];
    //up(i,1,11) cerr<<p[i]<<'\n';
}

inline void solve(){
    while(true){
        read(x);
        if(!x) return;
        long double k=(long double)x/log((long double)x); //cerr<<p[x]<<' '<<x/log(x)<<'\n';
        k=p[x]-k; if(k<0) k=-k; k*=100; k/=p[x];
        cout<<fixed<<setprecision(1)<<k<<'\n';
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
