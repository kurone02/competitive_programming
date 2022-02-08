#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn = 5e3 + 7;

int n, m, a[maxn], b[maxn];
long long dp[maxn], f[maxn], res;

inline void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
}

inline long long Maximize(long long &target, const long long &value){
    return (target < value)? target = value : target;
}

inline void Solve(){
    fill(dp, dp + m + 1, -1);
    for(int i = 1; i <= n; i++){
        long long curMax = 0;
        fill(f, f + m + 1, -1);
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) Maximize(f[j], curMax);
            if(dp[j] != -1) Maximize(curMax, dp[j] + abs(a[i] - b[j]));
            Maximize(res, Maximize(dp[j], f[j]));
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Input();
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
