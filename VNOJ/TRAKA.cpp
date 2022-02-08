#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e5+7;

struct Points{
    long long x,y;
    inline Points(long long _x=0, long long _y=0){x=_x; y=_y;}
    inline Points operator -(Points other){
        return Points(x-other.x,y-other.y);
    }
    inline long long operator *(Points other)const{
        return x*other.y-y*other.x;
    }
    friend inline bool CW(Points A, Points B, Points C){
        return (B-A)*(C-B)<0;
    }
};

int n,m,nConvex,c[maxn];
long long totalWaitingTime,q[maxn];
Points a[maxn],b[maxn];

inline long long WaitingTime(const Points &u){
    int l=1, r=nConvex;
    while(l<=r){
        int mid=(l+r)>>1;
        Points v=b[mid]-b[mid-1];
        if(u*v>=0) l=mid+1;
        else r=mid-1;
    }
    return u*b[r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q[i], q[i]+=q[i-1];
        a[i]=Points(q[i-1],q[i]);
    }
    b[++nConvex]=Points(0,0);
    for(int i=1;i<=n;i++){
        while(nConvex>1 && !CW(b[nConvex-1],b[nConvex],a[i])) nConvex--;
        b[++nConvex]=a[i];
    }
    int preC=0,C=0;
    for(int i=1;i<=m;i++){
        cin>>C;
        totalWaitingTime+=WaitingTime(Points(preC,C));
        preC=C;
    }
    cout<<totalWaitingTime+q[n]*C;

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
