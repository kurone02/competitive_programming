#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

const int maxn=1e5+7;
const ll mod=1e9+7;

int n,m,s,t;
vector<int> a[maxn];
bool c[maxn];
int trace[maxn],id[maxn];
vector<int> Path;
int kq,LastPos;

inline void Enter(){
    cin>>n>>m>>s>>t;
    while(m--){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
    }
}

inline void Bfs(){
    deque<int> q;
    q.pb(s); c[s]=true;
    while(q.size()){
        int u=q.front(); q.pop_front();
        rep(i,0,a[u].size()){
            int v=a[u][i];
            if(c[v]) continue;
            q.pb(v);
            c[v]=true;
            trace[v]=u;
        }
    }
    int p=t; while(p) Path.pb(p),p=trace[p];
    reverse(Path.begin(),Path.end());
    rep(i,0,Path.size()) id[Path[i]]=i;
}

inline int Find_Node(int x){
    deque<int> q; fill(c,c+n+1,false);
    q.pb(x); c[x]=true;
    while(q.size()){
        int u=q.front(); q.pop_front();
        rep(i,0,a[u].size()){
            int v=a[u][i];
            if(c[v] || id[v]) LastPos=max(LastPos,id[v]);
            else q.pb(v),c[v]=true;
        }
    }
}

inline void Solve(){
    LastPos=0;
    rep(i,0,Path.size()){
        int u=Path[i];
        if(u!=s && u!=t && LastPos<=id[u]) kq++;
        LastPos=max(LastPos,Find_Node(u));
    }
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Bfs();
    Solve();

    return 0;
}
