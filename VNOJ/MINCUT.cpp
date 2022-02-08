#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;typedef vector<vi> vvi;typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;typedef map<bool, int> mbi;typedef map<string, int> msi;
typedef vl big;
/*----------------------------------------------*/
const int maxn=1e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/
 
int m,n,t;
int a[maxn][maxn];
ll b[maxn][maxn];
ll kq=0;
ll tmp1,tmp2;
 
inline void enter(){
    cin>>m>>n>>t;
    up(i,1,m)
    up(j,1,n){
        cin>>a[i][j];
        b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
    }
}
 
inline ll getsum(int i,int j,int u,int v){
    return b[u][v]-b[u][j-1]-b[i-1][v]+b[i-1][j-1];
}
 
inline void sumver(int x,int y,int u,int v){
    int l=y,h=v;
    while(l<=h){
        int mid=(l+h)/2;
        //cerr<<mid<<'\n';
        if(getsum(x,y,u,mid)>=getsum(x,mid+1,u,v)) h=mid-1;
        else l=mid+1;
    }
    if(h<y) tmp1=tmp2=abs(getsum(x,y,u,y)-getsum(x,y+1,u,v));
    else tmp1=abs(getsum(x,y,u,h)-getsum(x,h+1,u,v)),
         tmp2=abs(getsum(x,y,u,min(l,v-1))-getsum(x,min(l,v-1)+1,u,v));
    //cout<<l<<' '<<tmp1<<' '<<tmp2<<'\n';
}
 
inline void sumhor(int x,int y,int u,int v){
    int l=x,h=u;
    while(l<=h){
        int mid=(l+h)/2;
        //cerr<<mid<<'\n';
        if(getsum(x,y,mid,v)>=getsum(mid+1,y,u,v)) h=mid-1;
        else l=mid+1;
    }
    if(h<x) tmp1=tmp2=abs(getsum(x,y,x,v)-getsum(x+1,y,u,v));
    else tmp1=abs(getsum(x,y,h,v)-getsum(h+1,y,u,v)),
         tmp2=abs(getsum(x,y,min(l,u-1),v)-getsum(min(l,u-1)+1,y,u,v));
    //cout<<l<<' '<<tmp1<<' '<<tmp2<<'\n';
}
 
inline void solve(){
    int x,y,u,v; cin>>x>>y>>u>>v;
    kq=LLONG_MAX;
    tmp1=0,tmp2=0;
    sumver(x,y,u,v);
    kq=min(tmp1,tmp2);
    //cout<<kq<<'\n';
    sumhor(x,y,u,v);
    kq=min(kq,min(tmp1,tmp2));
    cout<<kq<<'\n';
}
 
inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}
 
int main(){
    //#define OfflineJudge
    #ifdef OfflineJudge
    file();
    #endif
    enter();
    while(t--) solve();
    return 0;
} 