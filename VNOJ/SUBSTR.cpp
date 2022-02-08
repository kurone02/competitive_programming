#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a);i>int(b);i--)
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=1e6+7;
const int maxm=3e6;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

const ull BaseH=31;ull hashpow[maxn];
inline void HashPower(){
    hashpow[0]=1;
    up(i,1,1000000) hashpow[i]=hashpow[i-1]*BaseH;
}
inline void BuildHash(ull Hash[],string s){
    Hash[0]=0;
    up(i,1,s.length()-1) Hash[i]=Hash[i-1]*BaseH+(ull)(s[i]-'a'+1);
}
inline ull gethash(ull Hash[],int i,int j){
    return (j>=i)? Hash[j]-Hash[i-1]*hashpow[abs(j-i)+1]+ULLONG_MAX+1:
                   Hash[j]-Hash[i+1]*hashpow[abs(j-i)+1]+ULLONG_MAX+1;
}

int n,m;
string a,b;
ull ha[maxn],hb[maxn];

inline void enter(){
    cin>>a>>b;
    n=a.size(); a=' '+a;
    m=b.size(); b=' '+b;
}

inline void init(){
    HashPower();
    BuildHash(ha,a);
    BuildHash(hb,b);
    //cout<<gethash(ha,1,n)<<'\n'<<gethash(hb,1,m);
}

inline void solve(){
    up(i,1,n-m+1)
        if(gethash(ha,i,i+m-1)==gethash(hb,1,m)) cout<<i<<' ';
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    #define OnlineJudge
    #ifndef OnlineJudge
    file();
    #endif
    enter();
    init();
    solve();
    return 0;
}
