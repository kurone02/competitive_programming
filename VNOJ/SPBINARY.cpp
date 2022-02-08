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

const int maxn=1e3+7;
const int maxS=(1<<6);
const ll mod=1234567890;
const int inf=1e9+9;

/*BIGNUM*/
const int base=1e9;
const int digit=9;
typedef vector<ll> big;
inline void remove0(big &s){while(s.size()>1&&s.back()==0) s.pop_back();}
inline big fix(string x){big s;if(x.size()==0){s.pb(0);return s;}while(x.size()%digit!=0) x='0'+x;for(int i=0;i<(int)x.size();i+=digit){long long val=0;up(j,0,digit-1) val=val*10+(x[i+j]-'0');s.insert(s.begin(),val);}remove0(s);return s;}
inline bool operator <(big a,big b){remove0(a);remove0(b);if(a.size()!=b.size()) return a.size()<b.size();down(i,a.size()-1,0)if(a[i]!=b[i]) return a[i]<b[i];return false;}inline bool operator >(const big &a,const big &b){return b<a;}
inline bool operator ==(const big &a,const big &b){return (!(a<b))&&(!(a>b));}inline bool operator !=(const big &a,const big &b){return !(a==b);}inline bool operator <=(const big &a,const big &b){return (a<b)||(a==b);}inline bool operator >=(const big &a,const big &b){return (a>b)||(a==b);}
inline big operator +(big a,big b){big s;long long nho=0;int sa=a.size(),sb=b.size();for(int i=0;i<(int)sa||i<(int)sb;i++){if(i<(int)sa) nho+=a[i];if(i<(int)sb) nho+=b[i];s.pb(nho%base);nho/=base;}if(nho) s.pb(nho);remove0(s);return s;}
inline big operator -(big a,big b){big s;int nho=0;up(i,0,a.size()-1){int tmp=a[i]-nho;if(i<(int)b.size()) tmp-=b[i];if(tmp<0) tmp+=base,nho=1;else nho=0;s.pb(tmp);}remove0(s);return s;}
inline big operator *(big a,big b){big s(a.size()+b.size()+digit+1,0);up(i,0,(int)a.size()-1){int nho=0;up(j,0,(int)b.size()-1){int k=i+j;s[k]+=a[i]*b[j]+nho;nho=s[k]/base;s[k]%=base;}if(nho) s[i+b.size()]+=nho;}remove0(s);return s;}
inline void divide(const big &a,int x,big &q,int &r){q.clear();r=0;down(i,a.size()-1,0){r=r*base+a[i];q.push_back(r/x);r%=x;}reverse(q.begin(),q.end());remove0(q);}
inline big operator /(big a,int x){big res;int r;divide(a,x,res,r);return res;}
inline istream& operator >>(istream& cin,big &a){string s; cin>>s;a=fix(s);return cin;}
inline ostream& operator <<(ostream& cout,const big &a){cout<<a.back();for(int i=(int)a.size()-2;i>=0;--i) cout<<setw(digit)<<setfill('0')<<a[i];return cout;}
/*----------------------------------------------*/

int n,k;
big f[maxn][maxn][2];
bool c[maxn][maxn][2];

inline void Enter(){
    cin>>n>>k;
}

inline big dp(int pos,int cnt,int pre){
    if(pos>=n) return fix("1");
    big &res=f[pos][cnt][pre];
    if(c[pos][cnt][pre]) return res;
    c[pos][cnt][pre]=true;
    up(d,0,1){
        int tmp=cnt;
        if(d==pre) tmp++;
        else tmp=1;
        if(pos==0) tmp=1;
        if(tmp<=k) res=res+dp(pos+1,tmp,d);
    }
    return res;
}

inline void Solve(){
    cout<<dp(0,0,0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Solve();

    return 0;
}
