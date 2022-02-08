#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=5e3+7;

int n,res,a[maxn],s[maxn];

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;'0'<=c&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}template<typename T,typename... Args> inline void Read(T &x,Args&... args){
    Read(x);
    Read(args...);
}template<typename T> inline void Write(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}template<typename T> inline void Write(T x, const char &c){
    if(x<0) putchar('-'),x=-x;
    Write(x);
    putchar(c);
}template <typename T,typename... Args> inline void Write(const T &a, const char &c, Args... args){
    Write(a,c);
    Write(args...);
}

inline void Input(){
    Read(n);
    for(int i=1;i<=n;i++) Read(a[i]), s[i]=s[i-1]+a[i];
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        int k=0;
        int sumL=0,sumR=s[i];
        for(int j=1;j<i;j++){
            while(k+1<i && sumL<sumR){
                k++;
                sumL+=a[k]; sumR-=a[k];
            }
            if(sumL==sumR) res=max(res,i-j+1);
            sumL-=a[j];
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
