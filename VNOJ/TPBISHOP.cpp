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

const int maxn=3e3+7;
const int maxm=4e2+7;
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

int n;
int match[maxn],h[maxn],inSet[maxn];
int dx[]={1,-1, 1,-1},
    dy[]={1,-1,-1, 1};
char a[maxm][maxm];
bool found;
vector<int> adj[maxn],S,X,Y;

inline void Enter(){
    cin>>n;
    up(i,1,n) up(j,1,n) cin>>a[i][j];
}

inline int Encode(const int &i, const int &j){
    return (i-1)*n+j;
}

inline bool Valid(const int &i, const int &j){
    return i<=n && j<=n && i>=1 && j>=1 && a[i][j]=='.';
}

inline void DivideIntoSets(const int &i, const int &j, const int &nSet){
    inSet[Encode(i,j)]=nSet;
    rep(k,0,4){
        int x=i+dx[k], y=j+dy[k];
        if(!Valid(x,y) || inSet[Encode(x,y)]) continue;
        DivideIntoSets(x,y,3-nSet);
    }
}

inline void ConstructGraph(){
    up(i,1,n) up(j,1,n)
        if(!inSet[Encode(i,j)] && a[i][j]=='.') DivideIntoSets(i,j,1);
    up(i,1,n) up(j,1,n) if(a[i][j]=='.')
        if(inSet[Encode(i,j)]==1) X.pb(Encode(i,j));
        else Y.pb(Encode(i,j));
    up(i,1,n) up(j,1,n) if(inSet[Encode(i,j)]==1){
        rep(k,0,4){
            int x=i+dx[k],y=j+dy[k];
            if(!Valid(x,y) || inSet[Encode(x,y)]==1) continue;
            adj[Encode(i,j)].pb(Encode(x,y));
        }
    }
}

inline void Init(){
    ConstructGraph();
    for(int y: Y) match[y]=-1;
    S.reserve(X.size());
    for(int x: X) S.pb(x);
}

inline bool Bfs(){
    queue<int> q;
    for(int y: Y) h[y]=0;
    for(int x: S) for(int y: adj[x])
        if(!h[y]) h[y]=1,q.push(y);
    while(q.size()){
        int ypop=q.front();
        q.pop();
        int x=match[ypop];
        if(x==-1) return true;
        for(int y: adj[x]){
            if(!h[y]) h[y]=h[ypop]+1,q.push(y);
        }
    }
    return false;
}

inline void Dfs(const int &x, const int &lv){
    for(int y: adj[x]) if(h[y]==lv+1){
        h[y]=0;
        if(match[y]==-1) found=true;
        else Dfs(match[y],lv+1);
        if(found){
            match[y]=x;
            return;
        }
    }
}

inline void Solve(){
    while(Bfs()){
        repd(i,S.size(),0){
            found=false;
            Dfs(S[i],0);
            if(found) S[i]=S.back(),S.pop_back();
        }
    }
    cout<<Y.size()+S.size()<<'\n';
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
