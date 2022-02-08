#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)
#define self (*this)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
#define READ(a,b,c) _read(a),_read(b),_read(c)

const int maxn=1e5+7;
const int Nblocks=400;
const int maxk=1e3+7;
const ll mod=1e9;
const int inf=1e9+7;
const ll linf=1e16+9;
const ll Radix=1e9;
const int Length=9;
const int MaxDigit=2e4+1;
const int nDigits=MaxDigit/Length+1;

int n;
string s;

struct Bignum{
    array<ll,nDigits> d;
    inline Bignum& operator =(int x){
        fill(d.begin(),d.end(),0);
        for(int i=0;x;i++,x/=Radix) d[i]=x%Radix;
        return self;
    }
    friend inline void operator +=(Bignum &x,const Bignum &y){
        rep(i,0,nDigits){
            x.d[i]+=y.d[i];
            if(x.d[i]>Radix) x.d[i+1]++,x.d[i]-=Radix;
        }
    }
    friend inline Bignum operator +(Bignum x,const Bignum &y){
        x+=y;
        return x;
    }
    inline Bignum& operator *=(const int &y){
        ll carry=0;
        rep(i,0,nDigits){
            carry+=d[i]*y;
            d[i]=carry%Radix;
            carry/=Radix;
        }
        int i=nDigits;
        for(i--;carry;carry/=Radix) d[i++]=carry%Radix;
    }
    friend inline Bignum operator *(Bignum &x,const int &y){
        x*=y;
        return x;
    }
    inline void Print(){
        int i=nDigits;
        for(i--;i && self.d[i]==0;i--);
        cout<<self.d[i];
        for(i--;i>=0;i--) cout<<setw(Length)<<setfill('0')<<self.d[i];
    }

}res,cnt;

inline void Enter(){
    cin>>s; n=s.size();
    s=' '+s;
}

inline void Solve(){
    #define Kamisama
    res=1,cnt=1;
    up(i,1,n){
        if(s[i]=='L') res=res*2;
        if(s[i]=='R') res=res*2+cnt;
        if(s[i]=='*') res=res*5+cnt,cnt*=3;
    }
    res.Print();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifndef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif // Kamisama

    Enter();
    Solve();

    return 0;
}
