#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const int maxm=1e4+7;
const ll mod=123456789;
const int inf=1e9;

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

struct Bignum{
    static const int radix=1e9;
    static const int length=9;
    static const int maxDigit=3e3+7;
    static const int nDigits=maxDigit/length;
    array<ll,nDigits> d;
    inline Bignum& operator =(const int &other){
        fill(d.begin(),d.end(),0);
        d[0]=other;
        return self;
    }
    inline Bignum& operator =(const Bignum &other){
        copy(other.d.begin(),other.d.end(),d.begin());
        return self;
    }
    inline Bignum& operator +=(const Bignum &x){
        rep(i,0,nDigits){
            d[i]+=x.d[i];
            if(d[i]>radix) d[i]-=radix,d[i+1]++;
        }
        return self;
    }
    friend inline Bignum operator +(Bignum x, const Bignum& y){x+=y; return x;}
    friend inline Bignum operator *(const Bignum &x, const ll &y){
        Bignum res;
        ll carry=0;
        rep(i,0,nDigits){
            carry+=x.d[i]*y;
            res.d[i]=carry%radix;
            carry/=radix;
        }
        return res;
    }
    friend inline ostream& operator <<(ostream &cout,const Bignum &x){
        int i=nDigits-1;
        while(i>0 && x.d[i]==0) i--;
        cout<<x.d[i];
        for(--i;i>=0;i--) cout<<setw(length)<<setfill('0')<<x.d[i];
        return cout;
    }
};

int n;
Bignum res,one;

inline void Enter(){
    cin>>n;
}

inline void Init(){
    res=1;
    one=1;
    up(i,1,n-2) res=res*i+one;
}

inline void Solve(){
    cout<<res;
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
//

    Enter();
    Init();
    Solve();

    return 0;
}