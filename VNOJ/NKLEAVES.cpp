#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <algorithm>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e5+3;

struct TLines{
    long long a; long long b;
    inline TLines(long long _a=0, long long _b=0){a=_a;b=_b;}
    inline long long Value(const int &x){return a*x+b;}
    friend inline bool isBad(const TLines &d1, const TLines &d2, const TLines &d3){
        return (d2.b-d1.b)*(d1.a-d3.a)>=(d3.b-d1.b)*(d1.a-d2.a);
    }
};

int n,k,a[maxn];
long long s[maxn],sid[maxn],f[maxn],g[maxn];
TLines convex[maxn];

inline void Enter(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
}

inline void Init(){
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        sid[i]=sid[i-1]+1ll*i*a[i];
    }
}

inline void Solve(){ // f[i] = i*s[i] - sid[i] +  min{-s[j-1]*i + f[j-1] + sid[j-1]}
    for(int i=1;i<=n;i++) f[i]=1000000000000000000ll;
    for(int t=1;t<=k;t++){
        int best=0;
        int nConvex=0;
        swap(f,g);
        for(int i=1;i<=n;i++){
            long long x=i;
            while(best<nConvex && convex[best].Value(x)>=convex[best+1].Value(x)) best++;
            f[i]=i*s[i]-sid[i]+convex[best].Value(x);
            TLines newline(-s[i-1],g[i-1]+sid[i-1]);
            while(nConvex>1 && isBad(convex[nConvex-1],convex[nConvex],newline)){
                best-=(nConvex==best);
                nConvex--;
            } convex[++nConvex]=newline;
        } 
    }
    cout<<f[n];
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
    Init();
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
