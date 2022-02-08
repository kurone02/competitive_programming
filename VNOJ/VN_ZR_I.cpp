#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <cstring>
#include <algorithm>
#define Kami
#define taskname "TEST"
using namespace std;

int n,k;
string s;
long long f[40][40][2][2];

inline long long Dp(const int &pos, const int &cnt, const bool greater0, const bool &pre){
    if(pos>=(int)s.size()) return cnt==0? 0 : (cnt-1)/k+1;
    long long &res=f[pos][cnt][greater0][pre];
    if(res!=-1) return res;
    res=0;
    int lim=pre? s[pos] : 1;
    for(int x=0;x<=lim;x++){
        int newCnt=cnt+(x==0 && greater0);
        res+=Dp(pos+1,newCnt,greater0||x>0,pre&&(x==lim));
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

    while(cin>>n>>k){
        s.clear();
        for(;n;n>>=1) s.push_back(n&1);
        reverse(s.begin(),s.end());
        memset(f,-1,sizeof(f));
        cout<<Dp(0,0,0,1)<<'\n';
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
