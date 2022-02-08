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
#define Read(a,b) _read(a),_read(b)
 
const int maxn=1e5+7;
const int maxS=(1<<6);
const ll mod=1234567890;
const int inf=1e9+9;
 
int n;
int kq;
struct Neko{
    int x,y;
    Neko(){};
    Neko(int x,int y){
        this->x=x;
        this->y=y;
    }
    friend inline bool operator <(Neko tx,Neko ty){
        return (tx.x<ty.x || (tx.x==ty.x && tx.y<ty.y));
    }
}a[maxn];
set<Neko> S[maxn];
 
inline void Enter(){
    read(n);
    up(i,1,n) Read(a[i].x,a[i].y);
}
 
inline void Insert(int x,int len){
    set<Neko>::iterator it1 =S[len].lower_bound(a[x]);
    if(it1!=S[len].begin()){
        set<Neko>::iterator it2=it1;
        it2--;
        if(it2->x==a[x].x && it2->y<=a[x].y) return;
    }
    for(;it1!=S[len].end() && it1->y>=a[x].y;) S[len].erase(it1++);
    S[len].insert(a[x]);
}
 
inline bool chk(int x,int len){
    if(len==-1) return true;
    set<Neko>::iterator it=S[len].lower_bound(Neko(a[x].x,-inf));
    if(it==S[len].begin()) return false;
    it--;
    return it->y<a[x].y;
}
 
inline void Solve(){
    Insert(1,0);
    up(i,1,n){
        int l=-1,h=kq;
        while(h-l>1){
            int mid=(l+h)/2;
            if(chk(i,mid)) l=mid;
            else h=mid;
            //cerr<<l<<' '<<h<<'\n';
        }
        //cerr<<i<<'\n';
        kq=max(kq,l+2);
        //cerr<<"f["<<i<<"]= "<<l+2<<'\n';
        //cerr<<i<<' '<<kq<<' '<<f[i]<<'\n';
        //cerr<<i<<' '<<l+1<<'\n';
        Insert(i,l+1);
    }
    //up(i,1,n) kq=max(kq,f[i]);
    cout<<kq;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    Enter();
    Solve();
 
    return 0;
} 