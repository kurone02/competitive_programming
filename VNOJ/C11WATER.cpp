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
const int maxn=1e3+7;
const int maxm=1e6+7;
const int maxalpha=26;
const ll linf=1e16; const int inf=1e9;
const ll mod=14062008;
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

int n,m;
int a[maxn][maxn],b[maxn][maxn];
int dx[]={ 0,0,1,-1};
int dy[]={-1,1,0, 0};
bool c[maxn][maxn];
struct Neko{
    int x,y;
}; vector<Neko> d[maxm];
ll kq;

inline Neko neko(int x,int y){
    Neko tmp;
    tmp.x=x,tmp.y=y;
    return tmp;
}

inline void enter(){
    cin>>m>>n;
    memset(b,-1,sizeof(b));
    up(i,1,m) up(j,1,n) cin>>a[i][j],d[a[i][j]].pb(neko(i,j)),b[i][j]=0;
}

inline void bfs(Neko u){
    queue<Neko> q;
    b[u.x][u.y]=a[u.x][u.y];
    q.push(u);
    while(q.size()){
        int x=q.front().x,y=q.front().y;q.pop();
        rep(i,0,4){
            int nx=x+dx[i],
                ny=y+dy[i];
            if(!b[nx][ny] && a[nx][ny]<=a[u.x][u.y]){
                b[nx][ny]=a[u.x][u.y];
                q.push(neko(nx,ny));
            }
        }
    }
}

inline bool border(int x,int y){
    rep(i,0,4) if(b[x+dx[i]][y+dy[i]]) return true;
    return false;
}

inline void prepare(){
    up(i,1,1000000) rep(j,0,d[i].size()){
        int x=d[i][j].x,
            y=d[i][j].y;
        if(!b[x][y] && border(x,y)) bfs(d[i][j]);
    }
}

inline void solve(){
    rep(i,2,m) rep(j,2,n) kq+=max(0,b[i][j]-a[i][j]);
}

inline void Print(){
    cout<<kq;
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
    Print();
    return 0;
}
