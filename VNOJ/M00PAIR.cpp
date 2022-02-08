#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define cntbit(x) __builtin_popcountll(x)
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pli;

const int maxn=1e3+7;
const int maxb=5e3+7;
const ll mod=777777777;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;

const int radix=1e9;
const int length=9;
const int maxDigit=310;
const int nDigit=maxDigit/length+1;
struct Bignum{
    array<ll,nDigit> d;
    inline Bignum& operator =(int x){
        fill(d.begin(),d.end(),0);
        d[0]=x;
        return self;
    }
    inline Bignum& operator =(Bignum x){
        copy(x.d.begin(),x.d.end(),d.begin());
        return self;
    }
    inline Bignum& operator +=(const Bignum &x){
        rep(i,0,nDigit){
            d[i]+=x.d[i];
            if(d[i]>radix) d[i]-=radix,d[i+1]++;
        }
        return self;
    }
    inline Bignum& operator -=(const Bignum x){
        rep(i,0,nDigit){
            d[i]-=x.d[i];
            if(d[i]<0) d[i]+=radix,d[i+1]--;
        }
        return self;
    }
    friend inline Bignum operator +(Bignum x,Bignum y){
        x+=y; return x;
    }
    friend inline Bignum operator -(Bignum x,Bignum y){
        x-=y; return x;
    }
    friend inline ostream& operator <<(ostream &cout,const Bignum &x){
        int i=nDigit-1;
        while(i>0 && x.d[i]==0) i--;
        cout<<x.d[i];
        for(--i;i>=0;--i) cout<<setw(length)<<setfill('0')<<x.d[i];
        return cout;
    }
}f[maxn];

inline void Init(){
    Bignum one,t; one=1;
    f[1]=0;
    up(i,2,1000) t=2*(i&1),f[i]=f[i-1]+f[i-1]+one-t;
}

inline void Solve(){
    for(int n;cin>>n;) cout<<f[n]<<'\n';
}

inline void Main(){
    Init();
    Solve();
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds: "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds: "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
}

inline void Input_Output_From_File(const bool &Allow){
    if(not Allow) return;
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Input_Output_From_File(0);
    Execution_Time_Calculator(0);

    return 0;
}
