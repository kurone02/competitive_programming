#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e6+3;
const int mod=1e9+9;

int n,m,k;
int p[maxn],q[maxn],spf[maxn];
int numP[maxn],numQ[maxn];

inline void Enter(){
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>q[i];
}

inline void Sieve(){
    for(int i=0;i<maxn;i++) spf[i]=i;
    for(int i=2;i*i<maxn;i++) if(spf[i]==i)
        for(int j=i*i;j<maxn;j+=i) spf[j]=i;
}

inline void Factor(){
    for(int i=1;i<=n;i++)
        for(int x=p[i];x>1;x/=spf[x]) numP[spf[x]]++;
    for(int i=1;i<=n;i++)
        for(int x=q[i];x>1;x/=spf[x]) numQ[spf[x]]++;
}

inline int Pow(const int &x, const int &y){
    if(y==0) return 1;
    int res=Pow(x,y>>1);
    res=1ll*res*res%mod;
    if(y&1) return 1ll*res*x%mod;
    return res;
}

inline int NWays(const int &x, const int &y){
    if(y-x+1<0) return 0;
    return Pow(y-x+1,k);
}

inline int Calc(const int &x, const int &y){
    return (((NWays(x,y)-NWays(x,y-1)+mod)%mod-NWays(x+1,y)+mod)%mod+NWays(x+1,y-1))%mod;
}

inline void Solve(){
    int res=1;
    for(int i=2;i<maxn;i++) if(spf[i]==i)
        res=1ll*res*Calc(numP[i],numQ[i])%mod;
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Enter();
    Sieve();
    Factor();
    Solve();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
