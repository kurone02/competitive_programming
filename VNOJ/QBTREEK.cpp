#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)
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

const int maxn=1e5+7;
const int maxk=1e6;
const int maxa=1e8+7;
const ull mod=9901;
const int inf=1e9+7;
const ll linf=1e16+9;
const double pi=4*atan(1);
const double esp=1e-7;

int n,k;
int f[1002][502];

inline void Enter(){
    cin>>n>>k;
}

inline void Solve(){
    f[1][1]=1;
    if((n&1)==0){
        cout<<0;
        return;
    }
    up(i,1,k) f[1][i]=1;
    up(i,2,k){
        for(int j=1;j<=n;j+=2){
            for(int u=1;u<=n;u+=2) if(j-u-1>=1){
                f[j][i]=(f[j][i]+f[u][i-1]*f[j-u-1][i-1])%mod;
            }
        }
    }
    cout<<(f[n][k]-f[n][k-1]+mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifdef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif // Kamisama

    Enter();
    Solve();

    return 0;
}
