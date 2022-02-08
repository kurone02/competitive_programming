#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <unordered_map>
#define Kami02
#define taskname "TEST"
using namespace std;
const int maxn=2e6+3;

int n,low,high,a[maxn];
long long res;
unordered_map<int,int> cntLow,cntHigh;

inline void Enter(){
    cin>>n>>low>>high;
    for(int i=1;i<=n;i++) cin>>a[i];
}

inline void Solve(){
    int l=1,r=1,cntl=0,cntr=0; n++;
    for(int i=1;i<=n;i++){
        while(cntl<low && l<=n){
            cntl+=!(cntLow[a[l]]++);
            l++;
        }
        while(cntr<=high && r<=n){
            cntr+=!(cntHigh[a[r]]++);
            r++;
        }
        res+=r-l;
        cntl-=!(--cntLow[a[i]]);
        cntr-=!(--cntHigh[a[i]]);
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
