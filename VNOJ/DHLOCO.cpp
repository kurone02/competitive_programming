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
const int maxn=1e3+10;
const int maxt=2e5+10;
const ll linf=1e16;
const int inf=2e9;
const int mod=1e9+7;
const ll lmod=((ll)1<<32);
const ull ulmod=((ull)1<<63);
const double pi=4*atan(1);
const bool OnlineJudge=1;
const int as=2e2;
/*----------------------------------------------*/
struct cord{
    int x,y;
};
struct line{
    ll a,b,c;
};
/*BIGNUM*/
const int base=1e9;
const int digit=9;
inline void remove0(big &s){while(s.size()>1&&s.back()==0) s.pop_back();}
inline big fix(string x){big s;if(x.size()==0){s.pb(0);return s;}while(x.size()%digit!=0) x='0'+x;for(int i=0;i<(int)x.size();i+=digit){long long val=0;up(j,0,digit-1) val=val*10+(x[i+j]-'0');s.insert(s.begin(),val);}remove0(s);return s;}
inline bool operator <(big a,big b){remove0(a);remove0(b);if(a.size()!=b.size()) return a.size()<b.size();down(i,a.size()-1,0)if(a[i]!=b[i]) return a[i]<b[i];return false;}
inline bool operator >(const big &a,const big &b){return b<a;}
inline bool operator ==(const big &a,const big &b){return (!(a<b))&&(!(a>b));}
inline bool operator !=(const big &a,const big &b){return !(a==b);}
inline bool operator <=(const big &a,const big &b){return (a<b)||(a==b);}
inline bool operator >=(const big &a,const big &b){return (a>b)||(a==b);}
inline big operator +(big a,big b){big s;long long nho=0;int sa=a.size(),sb=b.size();for(int i=0;i<(int)sa||i<(int)sb;i++){if(i<(int)sa) nho+=a[i];if(i<(int)sb) nho+=b[i];s.pb(nho%base);nho/=base;}if(nho) s.pb(nho);remove0(s);return s;}
inline big operator -(big a,big b){big s;int nho=0;up(i,0,a.size()-1){int tmp=a[i]-nho;if(i<(int)b.size()) tmp-=b[i];if(tmp<0) tmp+=base,nho=1;else nho=0;s.pb(tmp);}remove0(s);return s;}
inline big operator *(big a,big b){big s(a.size()+b.size()+digit+1,0);up(i,0,(int)a.size()-1){int nho=0;up(j,0,(int)b.size()-1){int k=i+j;s[k]+=a[i]*b[j]+nho;nho=s[k]/base;s[k]%=base;}if(nho) s[i+b.size()]+=nho;}remove0(s);return s;}
inline istream& operator >>(istream& cin,big &a){string s; cin>>s;a=fix(s);return cin;}
inline ostream& operator <<(ostream& cout,const big &a){cout<<a.back();for(int i=(int)a.size()-2;i>=0;--i) cout<<setw(digit)<<setfill('0')<<a[i];return cout;}
/*----------------------------------------------*/
/*MATRIX*/
int MOD;
const int mxs=3;
struct matrix{
    ll x[mxs][mxs];
    int row,col;
    matrix(){};
    void make(int a,int b){
        row=a;
        col=b;
        memset(x,0,sizeof(x));
    }
    matrix(ll a[mxs][mxs]){
        up(i,0,mxs-1) up(j,0,mxs-1) x[i][j]=a[i][j];
    }
    matrix(ll a[mxs][1]){
        up(i,0,mxs-1) up(j,0,0) x[i][j]=a[i][j];
    }
    friend matrix operator *(const matrix &a,const matrix &b){
        matrix c;
        up(i,0,mxs-1)
        up(j,0,mxs-1){
            c.x[i][j]=0;
            up(k,0,mxs-1) c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
        }
        return c;
    }
    friend matrix operator ^(const matrix &a,const ll &k){
        if(k==1) return a;
        matrix c=a^(k/2);
        if(k%2) return c*c*a;
        else return c*c;
    }
};
/*----------------------------------------------*/

ll n;
matrix tmp1,tmp2,kq;

inline void init(){
    cin>>n>>MOD;
}

inline void prepare(){
    ll a[mxs][mxs]={1,1,1,
                    1,0,0,
                    0,1,0};
    ll b[mxs][mxs]={1,1,1};
    tmp1=matrix(a);
    tmp2=matrix(b);
}

inline void solve(){
    if(n<=1){
        cout<<1%MOD<<'\n';
        return;
    }
    kq=tmp1^(n);
    kq=kq*tmp2;
    cout<<kq.x[0][0]%MOD<<'\n';
}

inline void file(){
    #define task "LOCO"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    if(!OnlineJudge) file();
    init();
    prepare();
    //while(t--)
    solve();
    return 0;
}
