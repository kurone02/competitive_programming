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
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=3e6+7;
const int maxm=3e6;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int t,k;
ull n;
ull kq;
bool c[maxn];
vi p;

inline void enter(){
    cin>>t;
}

inline void eratos(){
    fill(c,c+maxn,true);
    c[0]=c[1]=false;
    for(int i=2;i<=maxm;i++)
        if(c[i])
            for(int j=2*i;j<=maxm;j+=i) c[j]=false;
}

inline void prepare(){
    eratos();
    up(i,1,maxm) if(c[i]) p.pb(i);
}

inline void solve(){
    cin>>n>>k;
    ull tmp=1;
    kq=0;
    up(pos,0,p.size()-k){
        tmp=1;
        up(i,pos,pos+k-1) tmp*=p[i];
        cerr<<tmp<<'\n';
        if(tmp<=n) kq=max(kq,tmp);
        else break;
    }
    if(!kq) cout<<-1<<'\n';
    else cout<<kq<<'\n';
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
    prepare();
    while(t--) solve();
    return 0;
}
