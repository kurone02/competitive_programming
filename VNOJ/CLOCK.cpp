#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define UP(i,a,b) for(i=a;i<=b;i++)
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

const int maxn=5e4;
const int maxm=1e6+7;
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

int a[3][3],d[4194289];
bool c[9][3][3];

inline void Enter(){
    rep(i,0,3) rep(j,0,3){
        char x;
        cin>>x;
        a[i][j]=x-'0';
    }
}

inline void Init(){
    c[0][0][0]=1;c[0][0][1]=1;c[0][1][0]=1;c[0][1][1]=1;
    c[1][0][0]=1;c[1][0][1]=1;c[1][0][2]=1;
    c[2][0][1]=1;c[2][0][2]=1;c[2][1][1]=1;c[2][1][2]=1;
    c[3][0][0]=1;c[3][1][0]=1;c[3][2][0]=1;
    c[4][0][1]=1;c[4][1][0]=1;c[4][1][1]=1;c[4][1][2]=1;c[4][2][1]=1;
    c[5][0][2]=1;c[5][1][2]=1;c[5][2][2]=1;
    c[6][1][0]=1;c[6][1][1]=1;c[6][2][0]=1;c[6][2][1]=1;
    c[7][2][0]=1;c[7][2][1]=1;c[7][2][2]=1;
    c[8][1][1]=1;c[8][1][2]=1;c[8][2][1]=1;c[8][2][2]=1;
}

inline void Solve(){
    fill(d,d+4194289,-1);
    queue<int> q;
    int s=0;
    rep(i,0,3) rep(j,0,3) s=4*s+a[i][j];
    q.push(s);
    d[s]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        rep(t,0,9){
            int v=0;
            int _u=u;
            rep(i,0,3)rep(j,0,3){
                v=4*v+(_u%4+c[t][i][j])%4;
                _u/=4;
            }
            if(v==0){
                cout<<d[u]+1;
                return;
            }
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
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
