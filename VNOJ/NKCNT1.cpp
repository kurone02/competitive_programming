#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <algorithm>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=5e3+7;

int n,m,a[maxn][maxn],f[maxn][maxn];
long long res;

inline void Enter(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x; cin>>x;
            a[i][j]=x-'0';
        }
    }
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(!a[i][j]){
            f[i][j]=1;
            if(!(a[i-1][j] || a[i][j-1] || a[i-1][j-1])) 
                f[i][j]+=min({f[i-1][j],f[i][j-1],f[i-1][j-1]});
            res+=f[i][j];
        }
    }
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
