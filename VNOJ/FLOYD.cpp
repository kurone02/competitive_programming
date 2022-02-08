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
typedef pair<ll,int> pli;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
#define READ(a,b,c) _read(a),_read(b),_read(c)

const int maxn=1e2+7;
const int Nblocks=400;
const int maxS=(1<<6);
const ll mod=1e9;
const int inf=1e9+7;
const ll linf=1e16+9;

int n,m,k,trace[maxn];
ll d[maxn];
vector<pli> a[maxn];
priority_queue< pli,vector<pli>,greater<pli> > q;

inline void Enter(){
    READ(n,m,k);
    up(i,1,m){
        int u,v,w;
        READ(u,v,w);
        a[u].pb(pli(w,v));
        a[v].pb(pli(w,u));
    }
}

inline ll Dijkstra(int s,int t){
    fill(d,d+n+1,linf);
    q.push(pli(0,s)); d[s]=0;
    while(q.size()){
        int u=q.top().second;
        ll w=q.top().first;
        q.pop();
        if(w>d[u]) continue;
        rep(i,0,a[u].size()){
            int v=a[u][i].second;
                w=a[u][i].first;
            if(d[u]+w<d[v]) d[v]=d[u]+w,q.push(pli(d[v],v)),trace[v]=u;
        }
    }
    return d[t];
}

inline void Trace(int s,int t){
    vector<int> res;
    fill(trace,trace+n+1,-1);
    Dijkstra(s,t);
    while(t!=-1) res.pb(t),t=trace[t];
    cout<<res.size()<<' '; repd(i,res.size(),0) cout<<res[i]<<' '; cout<<'\n';
}

inline void Solve(){
    while(k--){
        int type,u,v;
        READ(type,u,v);
        if(!type) cout<<Dijkstra(u,v)<<'\n';
        else Trace(u,v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Solve();

    return 0;
}
