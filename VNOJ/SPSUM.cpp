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

const int maxn=1e2+7;
const int maxS=(1<<6);
const ll mod=1234567890;
const ll inf=1e17+9;

const int len=18,nD=110/len;
const ll radix=1e18;
struct Bignum{
    array<ll,nD> d;
    Bignum(){}
    inline void operator +=(const Bignum &y)&{
        rep(i,0,nD){
            d[i]+=y.d[i];
            if(d[i]>=radix) d[i]-=radix,d[i+1]++;
        }
    }
};

inline ostream& operator <<(ostream& cout,const Bignum &x){
        int i=nD-1;
        while(i && x.d[i]==0) i--;
        cout<<x.d[i];
        for(--i;!(i<0);--i) cout<<setw(len)<<setfill('0')<<x.d[i];
        return cout;
    }

string n;
Bignum f[110][1000][2],num[1000];
bool c[110][1000][2];

inline void Enter(){
    cin>>n;
}

inline Bignum dp(int pos,int sum,bool pre){
    if(pos>=n.size()) return num[sum];
    Bignum &res=f[pos][sum][pre];
    if(c[pos][sum][pre]) return res;
    c[pos][sum][pre]=true;
    int lim= (pre)? (n[pos]-'0') : 9;
    up(d,0,lim) res+=dp(pos+1,sum+d,pre && d==lim);
    return res;
}

inline void Prepare(){
    up(i,0,990) num[i].d[0]=i;
}

inline void Solve(){
    cout<<dp(0,0,1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Prepare();
    Solve();

    return 0;
}
