#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)

using namespace std;

typedef long long ll;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)

const int maxn=1e5+7;
const int maxS=(1<<6);
const ll mod=1234567890;
const int inf=1e9+9;
const ll linf=1e16+9;

int n,bit[maxn],kq;
struct Neko{
    int x,y,z;
    friend inline bool operator <(Neko A,Neko B){
        return (A.x<B.x) || (A.x==B.x&&A.y<B.y) || (A.x==B.x&&A.y==B.y&&A.z<B.z);
    }
}a[maxn];

inline void Enter(){
    read(n);
    int tmp;
    up(i,1,n) read(tmp),a[tmp].x=i;
    up(i,1,n) read(tmp),a[tmp].y=i;
    up(i,1,n) read(tmp),a[tmp].z=i;
    sort(a+1,a+n+1);
}

inline void Init(){
    fill(bit,bit+n+1,inf);
}

inline void Update(int x,int val){
    for(;x<=n;x+=x&-x) bit[x]=min(val,bit[x]);
}

inline int Get(int x){
    int res=inf;
    for(;x;x-=x&-x) res=min(res,bit[x]);
    return res;
}

inline void Solve(){
    Init();
    up(i,1,n){
        kq+=(Get(a[i].z)>a[i].y);
        //cerr<<a[i].z<<' '<<Get(a[i].z)<<' '<<a[i].y<<'\n';
        Update(a[i].z,a[i].y);
    }
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Solve();

    return 0;
}
