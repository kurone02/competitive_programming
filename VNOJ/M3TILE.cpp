#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
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
const int mod=111539786;
const double pi=4*atan(1);
const bool OnlineJudge=0;
const int mxs=2;
const int as=2e2;
const int base=1e9;
const int digit=9;
/*----------------------------------------------*/
struct cord{
    int x,y;
};
struct line{
    ll a,b,c;
};
/*---------------------------------------------------|
 |                                                   |
 |    This code is the property of KAMISAMA          |
 |                                                   |
 |  Copyright 2018 Kamisama. All rights reserved.  |
 |                                                   |
 |---------------------------------------------------|*/
/*BIGNUM*/
inline void remove0(big &s){while(s.size()>1&&s.back()==0) s.pop_back();}
inline big fix(string x){big s;if(x.size()==0){s.pb(0);return s;}while(x.size()%digit!=0) x='0'+x;for(int i=0;i<(int)x.size();i+=digit){long long val=0;up(j,0,digit-1) val=val*10+(x[i+j]-'0');s.insert(s.begin(),val);}remove0(s);return s;}
inline bool operator <(big a,big b){remove0(a);remove0(b);if(a.size()!=b.size()) return a.size()<b.size();down(i,a.size()-1,0)if(a[i]!=b[i]) return a[i]<b[i];return false;}
inline bool operator >(const big &a,const big &b){return b<a;}
inline bool operator ==(const big &a,const big &b){return (!(a<b))&&(!(a>b));}
inline bool operator <=(const big &a,const big &b){return (a<b)||(a==b);}
inline bool operator >=(const big &a,const big &b){return (a>b)||(a==b);}
inline big operator +(big a,big b){big s;long long nho=0;int sa=a.size(),sb=b.size();for(int i=0;i<(int)sa||i<(int)sb;i++){if(i<(int)sa) nho+=a[i];if(i<(int)sb) nho+=b[i];s.pb(nho%base);nho/=base;}if(nho) s.pb(nho);remove0(s);return s;}
inline big operator -(big a,big b){big s;int nho=0;up(i,0,a.size()-1){int tmp=a[i]-nho;if(i<(int)b.size()) tmp-=b[i];if(tmp<0) tmp+=base,nho=1;else nho=0;s.pb(tmp);}remove0(s);return s;}
inline big operator *(big a,big b){big s(a.size()+b.size()+digit+1,0);up(i,0,(int)a.size()-1){int nho=0;up(j,0,(int)b.size()-1){int k=i+j;s[k]+=a[i]*b[j]+nho;nho=s[k]/base;s[k]%=base;}if(nho) s[i+b.size()]+=nho;}remove0(s);return s;}
inline istream& operator >>(istream& cin,big &a){string s; cin>>s;a=fix(s);return cin;}
inline ostream& operator <<(ostream& cout,const big &a){cout<<a.back();for(int i=(int)a.size()-2;i>=0;--i) cout<<setw(digit)<<setfill('0')<<a[i];return cout;}
/*----------------------------------------------*/

int n;
int f[31];

inline void init(){

}

inline void prepare(){
    f[0]=1,f[2]=3;
    for(int i=4;i<=30;i+=2) f[i]=4*f[i-2]-f[i-4];
}

inline void solve(){
    while(cin>>n){
        if(n==-1) break;
        cout<<f[n]<<'\n';
    }
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
    //while(t--)
    solve();
    return 0;
}
