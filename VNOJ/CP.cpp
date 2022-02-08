#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

typedef long long ll;

using namespace std;

const int maxn=1e5+7;
const ll inf=1e15+7;

int NTest;
bool c[maxn];
ll p[20];
vector<ll> Prime;
set<ll> qr[20];
string s;
ll f[200];

inline void Sieve(){
    fill(c+2,c+maxn,1);
    rep(i,2,maxn) if(c[i]){
        Prime.pb(i);
        for(ll j=1ll*i*i;j<maxn;j+=i) c[j]=false;
    }
    rep(i,0,20){
        int id=rand()%(40-2+1)+2;
        p[i]=Prime[id];
        //cerr<<p[i]<<' '<<Prime.size()<<'\n';
    }
}

inline void Quadratic_Reciprocity(){
    rep(i,0,20) up(j,0,p[i]) qr[i].insert((1ll*j*j)%p[i]);
}

inline bool PerfectSquare(const string &a){
    rep(i,0,20){
        int num=0;
        int mod=p[i];
        rep(j,0,a.size()) num=(num*10+a[j]-'0')%mod;
        //cerr<<num<<' '<<mod<<'\n';
        if(qr[i].find(num)==qr[i].end()) return false;
    }
    return true;
}

inline void Solve(){
    cin>>s;
    int n=s.size();
    s=' '+s;
    fill(f,f+200,0);
    f[0]=1;
    up(i,1,n){
        string a="";
        down(j,i,1){
            a=s[j]+a;
            if(s[j]=='0') continue;
            if(PerfectSquare(a)) f[i]+=f[j-1];
        }
    }
    cout<<f[n]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>NTest;

    Sieve();
    Quadratic_Reciprocity();

    while(NTest--){
        Solve();
    }

    return 0;
}
