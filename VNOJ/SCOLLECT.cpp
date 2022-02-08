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

const int maxn=5e3+7;
const int maxm=5e4+7;
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

int n,m,f[128][128][255];
int dx[]={0,1},
    dy[]={1,0};
char a[128][128];
bool reachable[128][128];

inline void Enter(){
    cin>>n>>m;
    rep(i,0,m) rep(j,0,n) cin>>a[i][j];
}

inline bool Valid(const int &i, const int &j){
    return i>=0 && j>=0 && i<m && j<n && a[i][j]!='#';
}

inline void Bfs(){
    queue<pii> q;
    q.push(pii(0,0));
    reachable[0][0]=true;
    while(q.size()){
        int x=q.front().x, y=q.front().y;
        q.pop();
        rep(i,0,2){
            int px=x+dx[i], py=y+dy[i];
            if(reachable[px][py]) continue;
            if(!Valid(px,py)) continue;
            q.push(pii(px,py));
            reachable[px][py]=true;
        }
    }
}

inline int Dp(const int &i, const int &j, const int &step){
    int &res=f[i][j][step];
    if(res!=-1) return res;
    if(step==m+n-2) return res=0;
    res=0;
    rep(di,0,2) rep(dj,0,2){
        int hi=i+di, hj=j+dj;
        int ci=step-hi+1, cj=step-hj+1;
        if(hi>hj || !Valid(hi,ci) || !Valid(hj,cj)) continue;
        int tmp=Dp(hi,hj,step+1);
        if(a[hi][ci]=='*') tmp++;
        if(hi!=hj && a[hj][cj]=='*') tmp++;
        res=max(res,tmp);
    }
    return res;
}

inline void Init(){
    Bfs();
    memset(f,-1,sizeof(f));
}

inline void Solve(){
    if(!reachable[m-1][n-1] || a[0][0]=='#') cout<<0;
    else cout<<(a[0][0]=='*'? 1 : 0)+Dp(0,0,0);
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

    Enter();
    Init();
    Solve();

    return 0;
}
