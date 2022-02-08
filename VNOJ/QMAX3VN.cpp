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

const int maxn=1e5+7;
const int maxm=1e4+7;
const ll mod=101;
const ll base=257;
const int inf=1e9+7;
const double esp=1e-6;

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

int n,m;
int bit[maxn],it[4*maxn],L[4*maxn],R[4*maxn];
struct Neko{char type;int x,y;}q[maxn];

inline void Enter(){
    cin>>m;
    up(i,1,m){
        cin>>q[i].type>>q[i].x>>q[i].y;
        n+=q[i].type=='A';
    }
}

inline void Update(int x,int val){
    for(;x<=n;x+=x&-x) bit[x]+=val;
}

inline int Get(int x){
    int res=0;
    for(;x;x-=x&-x) res+=bit[x];
    return res;
}

inline int Find(int t){
    int p=1;
    while(2*p<=n) p*=2;
    int x=0;
    for(;p;p/=2){
        int y=x+p;
        if(y<=n && bit[y]<t) t-=bit[y],x=y;
    }
    return x+1;
}

inline void Build(const int &x, const int &low, const int &high){
    if(low>high) return;
    L[x]=low,R[x]=high;
    if(low==high){
        it[x]=-inf;
        return;
    }
    int mid=(low+high)>>1;
    Build(CL(x),low,mid);
    Build(CR(x),mid+1,high);
    it[x]=max(it[CL(x)],it[CR(x)]);
}

inline void Update(const int &x, const int &pos, const int &val){
    if(L[x]>pos || R[x]<pos) return;
    if(L[x]==R[x]){
        it[x]=val;
        return;
    }
    Update(CL(x),pos,val);
    Update(CR(x),pos,val);
    it[x]=max(it[CL(x)],it[CR(x)]);
}

inline int Query(const int &x, const int &low, const int &high){
    if(L[x]>high || R[x]<low) return -inf;
    if(low<=L[x] && R[x]<=high) return it[x];
    return max(Query(CL(x),low,high),Query(CR(x),low,high));
}

inline void Init(){
    Build(1,1,n);
    up(i,1,n) Update(i,1);
    down(i,m,1){
        if(q[i].type=='A'){
            q[i].y=Find(q[i].y);
            Update(q[i].y,-1);

        } else{
            q[i].x=Find(q[i].x);
            q[i].y=Find(q[i].y);
        }
    }
}

inline void Solve(){
    up(i,1,m)
        if(q[i].type=='A') Update(1,q[i].y,q[i].x);
        else cout<<Query(1,q[i].x,q[i].y)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "QMAX3VN"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//
    Enter();
    Init();
    Solve();

    return 0;
}
