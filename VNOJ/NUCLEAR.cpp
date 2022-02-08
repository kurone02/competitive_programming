#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
//#define Kamisama

typedef long long ll;

using namespace std;

const int maxn=2e5+7;

struct FenwickTree{
    int bit[maxn];
    inline void update(int x,int val){
        for(;x<maxn;x+=(x+1)&-(x+1)) bit[x]+=val;
    }
    inline int get(int x){
        int res=0;
        for(;x>=0;x-=(x+1)&-(x+1)) res+=bit[x];
        return res;
    }
}bit;

int n,q,cnt1[maxn],cnt2[maxn],kq[maxn];
struct Neko{int x,y,id;}m1,m2;
vector<Neko> a;

inline ll sqr(int x){
    return 1ll*x*x;
}

inline int dis(Neko A,Neko B){
    ll res=sqr(A.x-B.x)+sqr(A.y-B.y);
    return ceil(sqrt(res));
}

inline bool ss(Neko A,Neko B){
    return A.y<B.y || (A.y==B.y&&A.x<B.x) || (A.y==B.y&&A.x==B.x&&A.id<B.id);
}

inline istream& operator >>(istream& cin,Neko& x){
    cin>>x.x>>x.y;return cin;
}

inline void Enter(){
    cin>>n;
    up(i,1,n){
        Neko tmp; tmp.id=0;
        cin>>tmp;
        a.pb(tmp);
    }
    cin>>m1>>m2>>q;
}

inline void Prepare(){
    rep(i,0,a.size()){
        int dis1=dis(a[i],m1),
            dis2=dis(a[i],m2);
        a[i].x=dis1, a[i].y=dis2;
        if(dis1<maxn) cnt1[dis1]++;
        if(dis2<maxn) cnt2[dis2]++;
    }

    rep(i,0,maxn) cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];

    up(i,1,q){
        Neko tmp;
        cin>>tmp; tmp.id=i;
        a.pb(tmp);
    }
}

inline void Solve(){
    sort(a.begin(),a.end(),ss);
    rep(i,0,a.size())
        if(a[i].id) kq[a[i].id]=cnt1[a[i].x]+cnt2[a[i].y]-bit.get(a[i].x);
        else bit.update(a[i].x,1);
}

inline void Print(){
    up(i,1,q) cout<<kq[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifdef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif //Kamisama

    Enter();
    Prepare();
    Solve();
    Print();

    return 0;
}
