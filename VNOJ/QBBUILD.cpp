#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)
#define self (*this)
#define Kamisama

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
#define READ(a,b,c) _read(a),_read(b),_read(c)

const int maxn=1e3+7;
const int Nblocks=400;
const int maxa=1e8+7;
const ll mod=9901;
const int inf=1e9+7;
const ll linf=1e16+9;
const ll Radix=1e9;
const int Length=9;
const int MaxDigit=2e4+1;
const int nDigits=MaxDigit/Length+1;

int n,city[5];
ll a[maxn][maxn],Res=linf;

inline void Enter(){
    cin>>n;
    up(i,1,4) cin>>city[i];
    up(i,1,n) up(j,1,n) if(i!=j) a[i][j]=linf; else a[i][j]=0;
    int u,v,w;
    while(cin>>u>>v>>w) a[u][v]=a[v][u]=w;
}

inline void Floyd(){
    up(k,1,n) up(u,1,n) up(v,1,n) a[u][v]=min(a[u][v],a[u][k]+a[k][v]);
}

inline void Solve(){
    up(u,1,n) up(v,1,n) rep(i,1,4) up(j,i+1,4){
        ll tmp=a[city[i]][u]+a[u][city[j]]+a[u][v];
        up(k,1,4) if(k!=i && k!=j) tmp+=a[city[k]][v];
        Res=min(Res,tmp);
    }
    cout<<Res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifndef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif // Kamisama

    Enter();
    Floyd();
    Solve();

    return 0;
}
