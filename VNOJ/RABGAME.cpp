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
#define All(x) x.begin(),x.end()
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const int maxm=1e4+7;
const ll mod=1e9+7;
const ll base=257;
const int inf=1e9+7;
const double esp=1e-7;
const double pi=acos(-1);

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

const ll Radix=1e9;
const int Length=9;
const int MaxDigit=2e3+1;
const int nDigits=MaxDigit/Length+1;

struct Bignum{
    array<ll,2*nDigits> d;

    inline Bignum& operator =(int x){
        fill(d.begin(),d.end(),0);
        for(int i=0;x;i++,x/=Radix) d[i]=x%Radix;
        return self;
    }

    inline Bignum& operator =(const Bignum &x){
        copy(x.d.begin(),x.d.end(),d.begin());
        return self;
    }

    inline Bignum& operator +=(const Bignum &x){
        rep(i,0,nDigits){
            d[i]+=x.d[i];
            if(d[i]>Radix) d[i]-=Radix,d[i+1]++;
        }
        return self;
    }

    inline Bignum& operator -=(const Bignum &x){
        rep(i,0,nDigits){
            d[i]-=x.d[i];
            if(d[i]<0) d[i]+=Radix,d[i+1]--;
        }
        return self;
    }

    inline Bignum& operator *=(const int &x){
        ll carry=0;
        rep(i,0,nDigits){
            carry+=d[i]*x;
            d[i]=carry%Radix;
            carry/=Radix;
        }
        int i=nDigits;
        for(;carry;carry/=Radix) d[i++]=carry%Radix;
        return self;
    }

    friend inline Bignum operator *(const Bignum &x,const Bignum &y){
        Bignum res; res=0;
        rep(i,0,nDigits){
            rep(j,0,nDigits){
                int k=i+j;
                res.d[k]+=x.d[i]*y.d[j];
                while(k<nDigits && res.d[k]>Radix){
                    res.d[k+1]=res.d[k+1]+res.d[k]/(1ll*Radix);
                    res.d[k]=res.d[k]%Radix;
                    k++;
                }
            }
        }
        return res;
    }

    friend bool operator <(const Bignum &x,const Bignum &y){
        repd(i,nDigits,0) if(x.d[i]!=y.d[i]) return x.d[i]<y.d[i];
        return false;
    }
    friend bool operator >(const Bignum &x,const Bignum &y){
        return y<x;
    }
    friend bool operator ==(const Bignum &x,const Bignum &y){return (!(x<y)) && (!(x>y));}
    friend bool operator !=(const Bignum &x,const Bignum &y){return !(y==x);}
    friend bool operator >=(const Bignum &x,const Bignum &y){return x>y || x==y;}
    friend bool operator <=(const Bignum &x,const Bignum &y){return x<y || x==y;}

    friend Bignum operator +(Bignum x,const Bignum &y){x+=y;return x;}
    friend Bignum operator -(Bignum x,const Bignum &y){x-=y;return x;}
    friend Bignum operator *(Bignum x,const int &y){x*=y;return x;}
    friend void operator *=(Bignum &x,const Bignum &y){x=x*y;}

    friend inline istream& operator >>(istream& cin,Bignum &x){
        string s;
        cin>>s; cerr<<s.size()<<'\n';
        if(s=="0"){x=0;return cin;}
        rep(i,0,s.size()){
            int pos=(s.size()-i-1)/Length;
            x.d[pos]=x.d[pos]*10+s[i]-'0';
        }
        return cin;
    }

    friend inline ostream& operator <<(ostream &cout,const Bignum &x){
        int i=2*nDigits-1;
        while(i>0 && x.d[i]==0) i--;
        cout<<x.d[i];
        for(--i;i>=0;--i) cout<<setw(Length)<<setfill('0')<<x.d[i];
        return cout;
    }
};

int n;
Bignum f[501];

inline void Enter(){
    cin>>n;
}

inline void Solve(){
    f[0]=1;
    f[1]=1;
    up(i,2,n) f[i]=f[i-1]+f[i-2]*(i-1);
    cout<<f[n];
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
    Solve();

    return 0;
}
