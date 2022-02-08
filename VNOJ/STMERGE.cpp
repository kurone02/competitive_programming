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
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=2e3+7;
const int maxm=1e5+7;
const int base=237;
const ll mod=1e9+7;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;
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

int nTest;
int m,n,c[maxn][maxn];
ll f1[maxn][maxn],f2[maxn][maxn];

inline void Enter(){
    cin>>m>>n;
    up(i,1,m) up(j,1,n) cin>>c[i][j];
}

inline void Init(){
    up(i,0,m+n) up(j,0,m) f1[i][j]=linf;
    up(i,0,m+n) up(j,0,n) f2[i][j]=linf;
    f1[0][0]=f2[0][0]=0;
    up(i,1,m+n){
        up(j,1,m){
            f1[i][j]=f1[i-1][j-1];
            if(i-j>=0 && i-j<=n) f1[i][j]=min(f1[i][j],f2[i-1][i-j]+c[j][i-j]);
        }
        up(j,1,n){
            f2[i][j]=f2[i-1][j-1];
            if(i-j>=0 && i-j<=m) f2[i][j]=min(f2[i][j],f1[i-1][i-j]+c[i-j][j]);
        }
    }
}

inline void Solve(){
    cout<<min(f1[m+n][m],f2[m+n][n])<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    for(cin>>nTest;nTest;nTest--){
        Enter();
        Init();
        Solve();
    }


    return 0;
}
