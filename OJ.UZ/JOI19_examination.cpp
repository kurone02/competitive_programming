#include <iostream>
#include <cstdio>
#include <algorithm>
#define taskname "JOI19_examination"
using namespace std;
const int maxn=1e5+1;
const int maxa=2e5+2;
 
struct Queries{
    int maths,cs,sum,id;
    inline bool operator <(const Queries &other){
        return sum>other.sum;
    }
};
 
struct DynamicSegTree{
    int l,r,sum;
    DynamicSegTree *cl,*cr;
    DynamicSegTree(int _l,int _r){
        l=_l; r=_r; sum=0;
        cl=nullptr; cr=nullptr;
    }
    inline void Update(const int &pos){
        if(l==r) sum++;
        else{
            int mid=(l+r)>>1;
            if(pos<=mid){
                if(cl==nullptr) cl=new DynamicSegTree(l,mid);
                cl->Update(pos);
            } else{
                if(cr==nullptr) cr=new DynamicSegTree(mid+1,r);
                cr->Update(pos);
            }
            sum=0;
            if(cl) sum+=cl->sum;
            if(cr) sum+=cr->sum;
        }
    }
    inline int Get(const int &low,const int &high){
        if(l>high || r<low) return 0;
        if(low<=l && r<=high) return sum;
        int res=0;
        if(cl) res+=cl->Get(low,high);
        if(cr) res+=cr->Get(low,high);
        return res;
    }
};
 
int n,q,sz;
int maths[maxa],cs[maxa],result[maxn];
Queries a[maxn],prof[maxn];
DynamicSegTree *bit[maxa];
 
template<typename T> inline void Read(T &x){
	register char c;
	bool neg=false;
	for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
	for(x=0;'0'<=c&&c<='9';c=getchar()) x=x*10+c-'0';
	if(neg) x=-x;
}template<typename T,typename... Args> inline void Read(T &x,Args&... args){
	Read(x);
	Read(args...);
}
template<typename T> inline void Write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
 
inline void Enter(){
    Read(n,q);
    for(int i=1;i<=n;i++){
        Read(a[i].maths,a[i].cs);
        a[i].sum=a[i].maths+a[i].cs;
        maths[i]=a[i].maths;
        cs[i]=a[i].cs;
    }
    for(int i=1;i<=q;i++){
        Read(prof[i].maths,prof[i].cs,prof[i].sum);
        prof[i].id=i;
        maths[n+i]=prof[i].maths;
        cs[n+i]=prof[i].cs;
    }
}
 
inline void Compress(){
    sz=n+q;
    sort(maths+1,maths+sz+1);
    sort(cs+1,cs+sz+1);
    for(int i=1;i<=n;i++){
        a[i].maths=lower_bound(maths+1,maths+sz+1,a[i].maths)-maths;
        a[i].cs=lower_bound(cs+1,cs+sz+1,a[i].cs)-cs;
    }
    for(int i=1;i<=q;i++){
        prof[i].maths=lower_bound(maths+1,maths+sz+1,prof[i].maths)-maths;
        prof[i].cs=lower_bound(cs+1,cs+sz+1,prof[i].cs)-cs;
    }
}
 
inline void Update(int x,const int &y){
    for(;x;x-=x&-x) bit[x]->Update(y);
}
 
inline int Get(int x,const int &y){
    int res=0;
    for(;x<=sz;x+=x&-x) res+=bit[x]->Get(y,sz);
    return res;
}
 
inline void Solve(){
    sort(a+1,a+n+1);
    sort(prof+1,prof+q+1);
    for(int i=1;i<maxa;i++) bit[i]=new DynamicSegTree(1,sz);
    for(int i=1,j=1;i<=q;i++){
        for(;j<=n && a[j].sum>=prof[i].sum;j++) Update(a[j].maths,a[j].cs);
        result[prof[i].id]=Get(prof[i].maths,prof[i].cs);
    }
    for(int i=1;i<=q;i++) Write(result[i]),putchar('\n');
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Enter();
    Compress();
    Solve();
    return 0;
}