#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+7;
const int inf=1e9+7;

int n,m;
int type,l,r;
struct Neko{
    int pre,suf,res;
    Neko(){}
    Neko(int pre,int suf,int res){
        this->pre=pre;
        this->suf=suf;
        this->res=res;
    }
}it[4*maxn];
int lazy[4*maxn];
int L[4*maxn],H[4*maxn];

inline Neko combine(int x,int y){
    Neko kq;
    kq.pre=it[x].pre+it[y].pre*(it[x].pre==H[x]-L[x]+1);
    kq.suf=it[y].suf+it[x].suf*(it[y].suf==H[y]-L[y]+1);
    kq.res=max(max(it[x].pre,max(it[y].suf,it[x].suf+it[y].pre)),max(it[x].res,it[y].res));
    return kq;
}

inline void Build(const int &x,const int &low,const int &high){
    if(low>high) return;
    L[x]=low,H[x]=high;
    if(low==high){
        it[x]=Neko(1,1,1);
        return;
    }
    int mid=(low+high)>>1;
    Build(CL(x),low,mid);
    Build(CR(x),mid+1,high);
    it[x]=combine(CL(x),CR(x));
}

inline void pushdown(int x){
    if(!lazy[x]) return;
    if(lazy[x]==1) it[x]=Neko(H[x]-L[x]+1,H[x]-L[x]+1,H[x]-L[x]+1);
    else it[x]=Neko(0,0,0);
    if(L[x]!=H[x]) lazy[CL(x)]=lazy[CR(x)]=lazy[x];
    lazy[x]=0;
}

inline void Update(const int &x){
    pushdown(x);
    if(L[x]>r || H[x]<l) return;
    if(l<=L[x] && H[x]<=r){
        lazy[x]=type;
        pushdown(x);
        return;
    }
    pushdown(x);
    Update(CL(x));
    Update(CR(x));
    it[x]=combine(CL(x),CR(x));
}

inline void Query(){
    cout<<it[1].res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>n>>m;

    Build(1,1,n);

    while(m--){
        cin>>type;
        if(type==3) Query();
        else cin>>l>>r, Update(1);
    }

    return 0;
}
