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

const int maxn=2e3+7;
const int maxm=1e4+7;
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

int n,cnt,l;
struct Neko{int k,w,v;}a[maxn];
ll f[maxn][maxm];

inline void Enter(){
    cin>>n>>l;
    up(i,1,n) cin>>a[i].w>>a[i].v>>a[i].k;
}

inline void Init(){
    cnt=n;
    up(i,1,n){
        int x=0;
        int p=1;
        while(x+p<=a[i].k){
                x+=p;
//                cerr<<x<<' '<<cnt<<'\n';
                a[++cnt]={p,p*a[i].w,p*a[i].v};
                p*=2;
            }
            p=a[i].k-x;
            a[++cnt]={p,p*a[i].w,p*a[i].v};
        a[i]={0,0};
    }
    n=cnt;
//    up(i,1,n) cout<<a[i].w<<' '<<a[i].v<<' '<<a[i].k<<'\n';
}

inline void Solve(){
    up(i,1,n){
        up(j,0,l){
            f[i][j]=f[i-1][j];
            if(a[i].w>j) continue;
            f[i][j]=max(f[i][j],f[i-1][j-a[i].w]+a[i].v);
        }
    }
//    up(i,1,n){
//        up(j,0,l) cout<<f[i][j]<<' ';
//        cout<<'\n';
//    }
    ll Q=0,P=0;
    up(i,0,l) if(Q<f[n][i]) Q=f[n][i],P=i;
    cout<<Q<<'\n';
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

    Enter();
    Init();
    Solve();

    return 0;
}
