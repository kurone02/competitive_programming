#include <iostream>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define taskname "TEST"
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5+7;
const long long inf=1e17+7;

struct TLines{
    int a; long long b;
    inline TLines(int _a=0, long long _b=0){a=_a;b=_b;}
    inline long long Value(const int &x){return 1ll*a*x+b;}
    friend inline bool isBad(const TLines &d1, const TLines &d2, const TLines &d3){
        return (d2.b-d1.b)*(d1.a-d3.a)>=(d3.b-d1.b)*(d1.a-d2.a);
    }
};

int n,m,nConvex;
pii a[maxn],b[maxn];
TLines convex[maxn];

inline void Enter(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
}

inline void Refine(){
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        while(m && b[m].y<a[i].y) m--;
        b[++m]=a[i];
    }
    swap(a,b);
}

inline void Solve(){ /// f[i] = min{f[j-1] + a[i].x*a[j].y}
    int best=1;
    long long res=0;
    for(int i=1;i<=m;i++){
        TLines newLine(a[i].y,res);
        while(nConvex>1 && isBad(convex[nConvex-1],convex[nConvex],newLine)){
            best-=(best==nConvex);
            nConvex--;
        } convex[++nConvex]=newLine;
        int x=a[i].x;
        while(best<nConvex && convex[best].Value(x)>=convex[best+1].Value(x)) best++;
        res=convex[best].Value(x);
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Enter();
    Refine();
    Solve();
    return 0;
}
