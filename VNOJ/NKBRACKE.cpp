#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=1e6+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n,m;
int a[maxn];
char s[maxn];
struct Neko{
    int prefix,sum;
};
struct SegTree{
    Neko it[4*maxn];
    int L[4*maxn],H[4*maxn];
    inline Neko combine(const Neko &x,const Neko &y){
        Neko res={0,0};
        res.sum=x.sum + y.sum;
        res.prefix=min(res.sum,min(x.prefix,x.sum+y.prefix));
        return res;
    }
    inline void build(const int &x,const int &low,const int &high){
        if(low>high) return;
        L[x]=low,H[x]=high;
        if(low==high){
            it[x].sum=it[x].prefix=a[low];
            return;
        }
        int mid=(low+high)/2;
        build(CL(x),low,mid);
        build(CR(x),mid+1,high);
        it[x]=combine(it[CL(x)],it[CR(x)]);
    }
    inline void update(const int &x,const int &pos,const int &val){
        if(L[x]>pos||pos>H[x]) return;
        if(L[x]==H[x]){
            it[x].sum=it[x].prefix=val;
            return;
        }
        update(CL(x),pos,val);
        update(CR(x),pos,val);
        it[x]=combine(it[CL(x)],it[CR(x)]);
    }
    inline Neko querry(const int &x,const int &u,const int &v){
        Neko tmp;
        tmp.sum=tmp.prefix=0;
        if(L[x]>v||H[x]<u) return tmp;
        if(u<=L[x]&&H[x]<=v) return it[x];
        return combine(querry(CL(x),u,v),querry(CR(x),u,v));
    }
    //inline void show(int x){up(i,1,4*x) cout<<it[i]<<' '<<L[i]<<' '<<H[i]<<'\n';}
}it;
int type,x,y;
char ch;

inline void enter(){
    scanf("%d%d\n",&n,&m);
    scanf("%s",&s);
    up(i,1,n){
        if(s[i-1]=='(') a[i]=1;
        else a[i]=-1;
        //cout<<a[i]<<'\n';
    }
    it.build(1,1,n);
}

inline void solve(){
    scanf("%d",&type);
    if(type){
        scanf("%d%d",&x,&y);
        Neko check=it.querry(1,x,y);
        if(check.prefix>=0&&check.sum==0) cout<<1;
        else cout<<0;
        //cout<<it.querry(1,x,y)<<'\n';
        //cout<<d[y]-d[x-1]<<'\n';
        return;
    }
    scanf("%d %c",&x,&ch);
    if(ch=='(') it.update(1,x,1);
    else it.update(1,x,-1);
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
    while(m--) solve();
    return 0;
}
