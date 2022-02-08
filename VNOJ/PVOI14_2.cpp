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

const int maxn=1e3+7;
const int maxs=1e6+7;
const ll mod=1e9+7;
const int inf=1e9+7;
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

int n;
int a[maxn][maxn],lab[maxs];
int dx[]={1,-1, 0,0},
    dy[]={0, 0,-1,1};
bool c[maxn][maxn];
struct Neko{int x,y,w;};
vector<Neko> edge;
vector<pii> blocks;
vector<int> adj[maxn][maxn];

inline void Enter(){
    Read(n);
    up(i,1,n) up(j,1,n) Read(a[i][j]);
}

inline bool Valid(const int &i, const int &j){
    return i<=n && j<=n && i>=1 && j>=1;
}

inline int Encode(const int &i, const int &j){
    return (i-1)*n+j;
}

inline void Init(){
    up(i,1,n) up(j,1,n){
        c[i][j]=true;
        rep(k,0,4){
            int x=i+dx[k];
            int y=j+dy[k];
            if(!Valid(x,y) || c[x][y]) continue;
            edge.pb({Encode(i,j),Encode(x,y),abs(a[i][j]-a[x][y])});
            adj[i][j].pb(edge.size());
            adj[x][y].pb(edge.size());
        }
    }
    sort(All(edge),[](const Neko &A, const Neko &B){return A.w<B.w;});
}

inline int FindSet(int x){
    return lab[x]<0? x : lab[x]=FindSet(lab[x]);
}

inline void Union(int x,int y){
    x=FindSet(x),y=FindSet(y);
    if(x==y) return;
    if(lab[x]<lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
}

inline void Solve(){
    edge.pb({-1,-1,-1});
    int l=0;
    rep(i,0,edge.size()-1){
        int r=i;
        if(edge[i].w!=edge[i+1].w) blocks.pb({l,r}),l=r+1;
    }
    int res=-1;
    fill(lab,lab+maxs,-1);
    for(auto block: blocks){
        up(i,block.x,block.y){
            Union(edge[i].x,edge[i].y);
            res=min(res,lab[FindSet(edge[i].x)]);
        }
        up(i,block.x,block.y) lab[edge[i].x]=lab[edge[i].y]=-1;
    }
    cout<<-res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "RSELECT"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}
