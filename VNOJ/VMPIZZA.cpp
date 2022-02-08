#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <algorithm>
#define CL(x) (x<<1)
#define CR(x) (x<<1|1)
#define a first
#define b second
#define Kami
#define taskname "TEST"
using namespace std;
typedef pair<long long,long long> TLine;
const int maxn=1e5+7;

struct TPizza{
    int t,a,b;
    inline bool operator <(const TPizza &other) const{
        return t<other.t;
    }
};

int n,walkingEnergy;
long long sA[maxn],sB[maxn],sumB[maxn],res;
TLine it[4*maxn];
TPizza pizza[maxn];

inline void Enter(){
    cin>>n>>walkingEnergy;
    for(int i=1;i<=n;i++) cin>>pizza[i].t>>pizza[i].a>>pizza[i].b;
}

inline void Init(){
    sort(pizza+1,pizza+n+1);
    for(int i=1;i<=n;i++){
        sA[i]=sA[i-1]+pizza[i].a;
        sB[i]=sB[i-1]+pizza[i].b;
        sumB[i]=sumB[i-1]+1ll*pizza[i].b*pizza[i].t;
    }
}

inline long long F(const TLine &d, const int &x){
    return d.a*x+d.b;
}

inline void Insert(TLine newLine, int x=1, int l=1, int r=maxn-1){
    int m=l+r>>1;
    int left=(F(newLine,l)>F(it[x],l));
    int mid=(F(newLine,m+1)>F(it[x],m+1));
    if(mid) swap(it[x],newLine);
    if(l==r) return;
    if(left==mid) Insert(newLine,CR(x),m+1,r);
    else Insert(newLine,CL(x),l,m);
}

inline long long Get(const int &pos, int x=1, int l=1, int r=maxn-1){
    int m=l+r>>1;
    if(l==r) return F(it[x],pos);
    if(pos<=m) return max(F(it[x],pos),Get(pos,CL(x),l,m));
    return max(F(it[x],pos),Get(pos,CR(x),m+1,r));
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        res=sA[i]-sB[i]*pizza[i].t+sumB[i]-walkingEnergy+Get(pizza[i].t);
        Insert(TLine(sB[i],res-sA[i]-sumB[i]));
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
