#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define self (*this)
#define pb push_back
#define cntbit(x) __builtin_popcountll(x)
#define x first
#define y second
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+7;
const ll mod=1e15+7;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;
 
int n;
ll x[maxn],X[maxn],g[maxn],r[maxn],bit[maxn],res;
 
template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}
 
template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}
 
inline void Enter(){
    Read(n);
    up(i,1,n) Read(X[i]),Read(g[i]),Read(r[i]),g[i]+=g[i-1],r[i]+=r[i-1];
    up(i,1,n) x[i]=r[i-1]-X[i];
    up(i,n+1,2*n) x[i]=r[i-n]-X[i-n];
}
 
inline void Update(int x, const ll &val){
    for(;x<maxn;x+=x&-x) bit[x]=min(bit[x],val);
}
 
inline ll Get(int x){
    ll res=linf;
    for(;x;x-=x&-x) res=min(res,bit[x]);
    return res;
}
 
inline void Compress(){
    set<ll> Set;
    up(i,1,2*n) Set.insert(x[i]);
    vector<ll> Tmp(Set.begin(),Set.end());
    //up(i,1,2*n) cout<<"x["<<i<<"]= "<<x[i]<<'\n';
    up(i,1,2*n) x[i]=lower_bound(Tmp.begin(),Tmp.end(),x[i])-Tmp.begin()+1;
    //up(i,1,2*n) cout<<"x["<<i<<"]= "<<x[i]<<'\n';
}
 
inline void Solve(){
    fill(bit+1,bit+maxn,linf);
    up(i,1,n){
        Update(x[i],g[i-1]);
        ll Gold=Get(x[i+n]);
        res=max(res,g[i]-Gold);
        //cerr<<res<<' '<<Gold<<'\n';
    }
    Write(res);
}
 
inline void Main(){
    Enter();
    Compress();
    Solve();
}
 
inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds: "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds: "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
}
 
inline void Input_Output_From_File(const bool &Allow){
    if(not Allow) return;
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    Input_Output_From_File(0);
    Execution_Time_Calculator(0);
 
    return 0;
}