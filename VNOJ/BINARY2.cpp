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

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)

const int maxn=1e6+7;
const int maxS=(1<<6);
const ll mod=1e9;
const int inf=1e9+7;
const ll linf=1e16+9;

int n,k;
int f[maxn][2];

inline void Enter(){
    Read(n,k);
}

inline void Solve(){
    up(i,0,1) up(j,0,1) f[i][j]=1;
    up(i,2,k) up(j,0,1) f[i][j]=(f[i-1][j]+f[i-1][!j])%mod;
    up(i,k+1,n) up(j,0,1) f[i][j]=((f[i-1][j]+f[i-1][!j])%mod-f[i-k-1][!j]+mod)%mod;
    cout<<(f[n][0]+f[n][1])%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Solve();

    return 0;
}
