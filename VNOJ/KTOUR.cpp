#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<char,int> pci;

const int maxn=1e5+7;
const double esp=1e-6;

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}
template<typename T> inline void Write(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int n,m,Y,csz,convexid[maxn];
ll result;
struct Neko{
    int x,y;
    Neko(){}
    Neko(int x,int y){self.x=x;self.y=y;}
    friend inline bool operator <(const Neko &A, const Neko &B){
        return A.x<B.x || (A.x==B.x && A.y<B.y);
    }
    friend inline bool operator ==(const Neko &A, const Neko &B){
        return A.x==B.x;
    }
    friend inline Neko operator -(const Neko &A, const Neko &B){
        return Neko(B.x-A.x,B.y-A.y);
    }
    friend inline Neko MidPoint(const Neko &A, const Neko &B){
        return Neko((A.x+B.x)>>1,(A.y+B.y)>>1);
    }
}a[maxn],b[maxn];
struct Chan{
    int a,b;
    ll c;
    Chan(const Neko &A, const Neko &B){
        a=B.y-A.y;
        b=A.x-B.x;
        c=1ll*a*A.x+1ll*b*A.y;
    }
    Chan(const int &x,const int &y, const Neko &P){
        a=x; b=y;
        c=1ll*a*P.x+1ll*b*P.y;
    }
    inline double Get() const{
        return (double)(c-b*Y)/a;
    }
};

inline void Enter(){
    cin>>n>>Y; Y<<=1;
    up(i,1,n) cin>>b[i].x,b[i].x<<=1,b[i].y=Y;
    cin>>m;
    up(i,1,m){
        cin>>a[i].x>>a[i].y,a[i].x<<=1,a[i].y<<=1;
        if(a[i].y<Y) a[i].y=2*Y-a[i].y;
    }
}

inline bool Check(const Neko &A, const Neko &B, const Neko &C){
    Neko mAB=MidPoint(A,B),
         mBC=MidPoint(B,C);
    Chan AB(A,B),
         BC(B,C);
    Chan pAB(-AB.b,AB.a,mAB),
         pBC(-BC.b,BC.a,mBC);
    double xAB=pAB.Get(),
           xBC=pBC.Get();
    return (xAB>xBC) || (fabs(xAB-xBC)<=esp);
}

inline void ConvexLine(){
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    m=unique(a+1,a+m+1)-a-1;
    up(i,1,m){
        while(csz>1 && Check(a[convexid[csz-1]],a[convexid[csz]],a[i])) csz--;
        convexid[++csz]=i;
    }
}

inline ll sqr(int x){return 1ll*x*x;}
inline ll f(const Neko &A, const Neko &B){Neko C=B-A;return sqr(C.x)+sqr(C.y);}

inline void Solve(){
    int j=1;
    up(i,1,n){
        while(j<csz && f(b[i],a[convexid[j]])>f(b[i],a[convexid[j+1]])) j++;
        result=max(result,f(b[i],a[convexid[j]]));
    }
    cout<<fixed<<setprecision(6);
    cout<<sqrt(result*0.25);
}

inline void Main(){
    Enter();
    ConvexLine();
    Solve();
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
    Execution_Time_Calculator(1);

    return 0;
}
