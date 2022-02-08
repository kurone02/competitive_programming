#include <bits/stdc++.h>
#include <unordered_map>
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

int nTest,cnt;
int m,n,k;
ll bit[maxm];
pii a[maxn];

inline void Enter(){
    cin>>m>>n>>k;
    up(i,1,k) cin>>a[i].x>>a[i].y;
}

inline void Init(){
    sort(a+1,a+k+1);
}

inline void Update(int x){
    for(;x;x-=x&-x) bit[x]++;
}

inline int Get(int x){
    int res=0;
    for(;x<=n;x+=x&-x) res+=bit[x];
    return res;
}

inline void Solve(){
    cnt++;
    ll res=0;
    up(i,1,k){
        res+=Get(a[i].y+1);
        Update(a[i].y);
    }
    cout<<"Test case "<<cnt<<": "<<res<<'\n';
}

inline void Reset(){
    fill(bit,bit+n+1,0);
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

    for(cin>>nTest;nTest;nTest--){
        Enter();
        Init();
        Solve();
        Reset();
    }

    return 0;
}
