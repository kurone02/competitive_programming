#include<bits/stdc++.h>
#define task "TEST"
#define f first
#define s second
#define pli pair<long long,int>
#define pii pair<int,int>
#define pb push_back

const int maxn=5e2+5;
const int inf=1e9;
const int mod=1e9+7;

using namespace std;

int t;
long long x,y;
unsigned long long a,b,m;
unsigned long long fib[maxn];
unsigned long long f[maxn][maxn];

inline void init(){
    cin>>t;
}

inline void prepare(){
}

inline unsigned long long mul(unsigned long long X, unsigned long long Y){
    if(Y==0) return 0;
    if(Y==1) return X;
    if(Y%2==0) return (mul(X,Y/2)*2)%m;
    else return (mul(X,Y/2)*2+X)%m;
}

inline void solve(){
    cin>>x>>y>>a>>b>>m;
    a%=m;
    b%=m;
    fib[1]=fib[2]=1;
    memset(f,sizeof(f),0);
    for(int i=3;i<=500;i++) fib[i]=(fib[i-1]%m+fib[i-2]%m)%m;
    for(int i=0;i<=x;i++) f[i][0]=i%m;
    for(int i=0;i<=y;i++) f[0][i]=i%m;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++)
            f[i][j]=(mul(a,f[i-1][j])+mul(b,f[i][j-1])+fib[__gcd(i,j)])%m;
    }
    cout<<f[x][y]%m<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    init();
    prepare();
    while(t--)
    solve();
    return 0;
}
