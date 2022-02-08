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

int l,r,kq;
int p[maxn];

inline void Enter(){
    cin>>l>>r;
}

inline void Sieve(){
    fill(p,p+maxn,1);
    for(int i=2;i<maxn;i++)
        for(int j=i;j<maxn;j+=i) p[j]+=i;
}

inline void Solve(){
    up(i,l,r) if(p[i]>2*i) kq++;
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Sieve();
    Solve();

    return 0;
}
