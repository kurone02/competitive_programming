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
const int maxm=1e6+7;
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
int n,m,q;
int lab[maxn];
struct Neko{int x,y,w;}e[maxm],unchanged[maxm];

inline void Enter(){
    cin>>n>>m>>q;
    up(i,1,m){
        cin>>e[i].x>>e[i].y>>e[i].w;
        unchanged[i]=e[i];
    }
}

inline void MakeSet(){
    fill(lab,lab+n+1,-1);
}

inline int FindSet(const int &x){
    return (lab[x]<0)? x : lab[x]=FindSet(lab[x]);
}

inline void Union(int x,int y){
    x=FindSet(x); y=FindSet(y);
    if(x==y) return;
    if(lab[x]>lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
}

inline void Reset(){
    fill(lab,lab+n+1,-1);
    up(i,1,m) e[i]=unchanged[i];
}

inline void Solve(){
    MakeSet();
    while(q--){
        int s,k;
        cin>>k>>s;
        up(i,1,s){
            int t,c;
            cin>>t>>c;
            e[t].w=c;
        }
        up(i,1,m) if(e[i].w<e[k].w) Union(e[i].x,e[i].y);
        if(FindSet(e[k].x)==FindSet(e[k].y)) cout<<"YES\n";
        else cout<<"NO\n";
        Reset();
    }
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
        Solve();
    }

    return 0;
}
