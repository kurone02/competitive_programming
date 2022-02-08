#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define All(x) x.begin(),x.end()
#define CntBit(x) __builtin_popcount(x)
#define GetBit(x,k) (((x)>>(k))&1)
#define OffBit(x,k) ((x)&(~(1<<(k))))
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e6+7;
const int maxm=1e3+7;
const int hashTableMod=4074004;
const ll mod=1e9+7;
const int inf=1e9+7;
const ll linf=1e17+7;
const double esp=1e-7;
const double pi=acos(-1);

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int nTest,cntTest;
int n,m,d[maxn];
bool p[maxn],inSet[maxn];
vector<int> s;

inline void Enter(){
    cin>>m>>n;
    if(m<n) swap(m,n);
}

inline void Init(){
    fill(p,p+maxn,true);
    p[0]=p[1]=false;
    for(int i=2;i*i<maxn;i++) if(p[i]) for(int j=i*i;j<maxn;j+=i) p[j]=false;
    fill(inSet,inSet+maxn,true);
    rep(i,2,maxn) if(p[i]){
        for(int j=i;j<maxn;j+=i) if((1ll*j)%(1ll*i*i)==0) inSet[j]=false; else d[j]++;
    }
    rep(i,1,maxn) if(inSet[i]) s.pb(i);
}

inline void Solve(){
    cntTest++;
    ll res=0;
    for(int x: s){
        if(x>n) break;
        if(d[x]&1) res-=1ll*(m/x)*(n/x);
        else res+=1ll*(m/x)*(n/x);
    }
    if(n==0) res+=(m!=0);
    else res+=2;
    cout<<"Case "<<cntTest<<": "<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif // Kamisama
//

    Init();
    for(cin>>nTest;nTest;nTest--){
        Enter();
        Solve();
    }

    return 0;
}
