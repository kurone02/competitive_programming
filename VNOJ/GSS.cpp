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
const int maxn=1e5+10;
const int maxt=2e5+10;
const ll linf=1e16;
const int inf=2e9;
const int mod=111539786;
const double pi=4*atan(1);
const bool OnlineJudge=0;
const int as=2e2;
/*----------------------------------------------*/
struct cord{
    int x,y;
};
struct line{
    ll a,b,c;
};
template<typename Neko_chan>
inline bool maximize(Neko_chan &X,Neko_chan Y){
    if(X<Y){X=Y;return true;}
    return false;
}
/*----------------------------------------------*/

int n,t;
ll a[maxn];
ll b[maxn];
struct SegTree{
    struct Neko{
        ll sum,pre,suf,kq;
    } it[4*maxn];
    ll l[4*maxn],h[4*maxn];

    inline Neko combine(const Neko &L,const Neko &R){
        ll sum=L.sum+R.sum;
        ll pre=max(L.pre,L.sum+R.pre);
        ll suf=max(R.suf,R.sum+L.suf);
        ll ans=max(max(
                       max(L.suf+R.pre,
                           L.sum+R.sum),
                   max(L.kq,R.kq)),
                    L.suf+R.sum
                  );
        return {sum,pre,suf,ans};
    }

    inline void build(const int &x,int low,int high){
        if(low>high) return;
        l[x]=low,h[x]=high;
        if(low==high){
            it[x]={a[low],a[low],a[low],a[low]};
            return;
        }
        int mid=(low+high)/2;
        build(2*x,low,mid);
        build(2*x+1,mid+1,high);
        int L=2*x,R=2*x+1;
        it[x]=combine(it[L],it[R]);
    }

    inline void show(){
        up(i,1,4*n) cout<<it[i].sum<<' '<<it[i].pre<<' '<<it[i].suf<<' '<<it[i].kq<<'\n';
    }

    inline Neko getmax(int x,int u,int v){
        if(l[x]>v||h[x]<u) return {-inf,-inf,-inf,-inf};
        if(u<=l[x]&&h[x]<=v) return it[x];
        int L=2*x,R=2*x+1;
        return combine(getmax(L,u,v),getmax(R,u,v));
    }

}IT;

inline void init(){
    cin>>n;
    up(i,1,n) cin>>a[i],b[i]=b[i-1]+a[i];
    cin>>t;
}

inline void prepare(){
    IT.build(1,1,n);
    //IT.show();
}

inline void solve(){
    int x,y;
    cin>>x>>y;
    cout<<IT.getmax(1,x,y).kq<<'\n';
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
    while(t--)
    solve();
    return 0;
}
