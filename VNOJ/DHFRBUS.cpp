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
typedef pair<ll,int> pli;

const int maxn=1e5+7;
const ll mod=1e15+7;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;

int n,m,s,t,k;
vector<pli> a[maxn];
ll d[maxn][6];
struct Neko{
    int u,k;
    ll w;
    Neko(){};
    Neko(int u,int k,ll w){self.u=u,self.k=k,self.w=w;}
    friend inline bool operator <(const Neko &x,const Neko &y){
        return x.w>y.w;
    }
};

inline void Enter(){
    cin>>n>>m>>k>>s>>t;
    up(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(pli(w,v));
        a[v].pb(pli(w,u));
    }
}

inline void Dijkstra(){
    priority_queue<Neko> q;
    up(i,1,n) up(j,0,5) d[i][j]=linf;
    d[s][0]=0;
    q.push(Neko(s,0,0));
    while(q.size()){
        Neko node=q.top();
        q.pop();
        int u=node.u,t=node.k,w=node.w;
        if(w>d[u][t]) continue;
        for(auto Node: a[u]){
            int v=Node.second;
            ll c=Node.first;
            if(d[v][t]>d[u][t]+c){
                d[v][t]=d[u][t]+c;
                q.push(Neko(v,t,d[v][t]));
            }
            if(t<k && d[v][t+1]>d[u][t]){
                d[v][t+1]=d[u][t];
                q.push(Neko(v,t+1,d[v][t+1]));
            }
        }
    }
}

inline void Solve(){
    cout<<d[t][k];
}

inline void Main(){
    Enter();
    Dijkstra();
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
