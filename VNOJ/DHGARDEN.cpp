#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<bool, int> mbi;
typedef vl big;
/*----------------------------------------------*/
const int maxn=1e2+10;
const int maxt=2e5+10;
const ll linf=1e16;
const int inf=2e9;
const int mod=1e9+7;
const ll lmod=((ll)1<<32);
const ull ulmod=((ull)1<<63);
const ld pi=3.14159265358979323846264338327950288;
const bool OnlineJudge=0;
const int as=2e2;
/*----------------------------------------------*/
struct cord{
    ll x,y;
};
struct line{
    ll a,b,c;
};
template<typename Neko_chan>
inline bool maximize(Neko_chan &X,Neko_chan Y){
    if(X<Y){X=Y;return true;}
    return false;
}
/*----------------------------------------------*/


int t,d,n,r;
cord a[20],s[20];
cord O;
int kq;

inline ll sqr(const ll &x){
    return x*x;
}

inline ld dis(const cord &A,const cord &B){
    return (ld)sqrt((ld)(sqr(A.x-B.x)+sqr(A.y-B.y)));
}

inline void operator -=(cord &A,cord B){
    A.x-=B.x;A.y-=B.y;
}

inline bool ccw(cord A,cord B,cord C){
    B-=A,C-=A;
    return B.x*C.y>=B.y*C.x;
}

inline bool cmp(cord A,cord B){
    return (A.x==B.x)? A.y<B.y : A.x<B.x;
}

inline bool ss(cord A,cord B){
    return ccw(O,A,B);
}

inline void init(){
    cin>>t;
}

inline void prepare(){

}

inline int getbit(int x,int k){
    return x>>(k-1)&1;
}

inline void solve(){
    cin>>d>>n>>r;
    up(i,1,n) cin>>a[i].x>>a[i].y;
    kq=0;
    up(tt,1,(1<<(n))-1){
        int z=0;
        up(i,1,n) s[i].x=s[i].y=0;
        up(i,1,n) if(getbit(tt,i)) z++;
        cord f[2000]={};
        int tmp=0;
        up(i,1,n) if(getbit(tt,i)) f[++tmp]=a[i];
        sort(f+1,f+z+1,cmp);
        O=f[1];
        sort(f+2,f+z+1,ss);
        f[0]=f[z];f[z+1]=f[1];
        int j=1;
        up(i,1,z+1){
            while(j>2&&!ccw(f[j-2],f[j-1],f[i])) j--;
            f[j++]=f[i];
        }
        ld k=2*pi*r;
        up(i,1,j-3) k+=dis(f[i],f[i+1]);//cout<<k<<'\n';
        k+=dis(f[1],f[j-2]);
        if(k<=(ld)d) kq=max(kq,z);
    }
    cout<<kq<<'\n';
}


inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    //if(!OnlineJudge) file();
    init();
    prepare();
    while(t--)
    solve();
    return 0;
}
