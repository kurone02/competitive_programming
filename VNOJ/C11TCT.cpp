#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#define Kami
#define taskname "TEST"
using namespace std;
const int mod=1e5+3;

int f[mod];

inline int Pow(const int &x, const int &y){
    if(y==0) return 1;
    int res=Pow(x,y>>1);
    res=1ll*res*res%mod;
    if(y&1) return 1ll*res*x%mod;
    return res;
}

inline int C(const int &n, const int &k){
    if(n<k) return 0;
    return 1ll*f[n]*Pow(1ll*f[k]*f[n-k]%mod,mod-2)%mod;
}

inline int Solve(long long n, long long k){
    int res=1;
    for(int i=0;i<4;i++){
        int x=n%mod; n/=mod;
        int y=k%mod; k/=mod;
        if(x<y) return 0;
        res=1ll*res*C(x,y)%mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    f[0]=1; for(int i=1;i<mod;i++) f[i]=1ll*f[i-1]*i%mod;
    int nTest; cin>>nTest;
    while(nTest--){
        long long m,n; cin>>m>>n;
        cout<<Solve(m-n+1,n)<<'\n';
    }

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
