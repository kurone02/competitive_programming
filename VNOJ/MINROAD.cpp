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

const int maxn=3e5+7;
const int maxS=(1<<6);
const ll mod=1234567890;
const int inf=1e9+9;
const ll linf=1e16+9;

int n,A,B;
struct Neko{int d,k;}a[maxn];
int cnt1[maxn],cnt2[maxn];
ll kq=inf;

inline bool ss(Neko x,Neko y){
    return x.d<y.d;
}

inline void Enter(){
    cin>>n>>A>>B;
    up(i,1,n) cin>>a[i].d>>a[i].k;
    sort(a+1,a+n+1,ss);
    up(i,1,n)
        if(a[i].k==1) cnt1[i]++;
        else cnt2[i]++;
    up(i,1,n) cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
}

inline void Solve(){
    if(cnt1[n]<A || cnt2[n]<B){cout<<-1;return;}
    int j=1;
    up(i,1,n){
        //cerr<<a[i].k<<' '<<cnt1[i]<<' '<<cnt2[i]<<'\n';
        bool change=false;
        while(j<=i && cnt1[i]-cnt1[j-1]>=A && cnt2[i]-cnt2[j-1]>=B){
            j++;
            change=true;
        }
        if(change) j--;
        if(cnt1[i]-cnt1[j-1]>=A && cnt2[i]-cnt2[j-1]>=B)
            kq=min(kq,1ll*a[i].d-a[j].d);
            //cerr<<i<<' '<<j<<'\n';
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
