#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <queue>
#define x first
#define y second
#define Kami
#define taskname "TEST"
using namespace std;
typedef pair<int,int> pii;
const int maxn=5e2+7;
const int inf=1e9+7;
const int dx[]={+1,-1,+0,+0};
const int dy[]={+0,+0,-1,+1};

struct TPQ{
    int x,y,w;
    inline TPQ(int _x=0, int _y=0, int _w=0){
        x=_x; y=_y; w=_w;
    }
    inline bool operator <(const TPQ &other) const{
        return w<other.w;
    }
};

int n,m,disTree[maxn][maxn],res[maxn][maxn];
char a[maxn][maxn];
pii s,t;

inline void Enter(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='V') s=pii(i,j);
            if(a[i][j]=='J') t=pii(i,j);
        }
    }
}

inline bool Valid(const pii &P){
    return P.x>0 && P.y>0 && P.x<=n && P.y<=m;
}

inline void Init(){
    queue<pii> q; fill(&disTree[0][0],&disTree[0][0]+maxn*maxn,-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(a[i][j]=='+'){
            q.push(pii(i,j));
            disTree[i][j]=0;
        }
    }
    while(q.size()){
        pii u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pii v=pii(u.x+dx[i],u.y+dy[i]);
            if(!Valid(v)) continue;
            if(disTree[v.x][v.y]!=-1) continue;
            q.push(v);
            disTree[v.x][v.y]=disTree[u.x][u.y]+1;
        }
    }
}

inline void Solve(){
    priority_queue<TPQ> pq;
    fill(&res[0][0],&res[0][0]+maxn*maxn,0);
    pq.push(TPQ(s.x,s.y,disTree[s.x][s.y])); 
    res[s.x][s.y]=disTree[s.x][s.y];
    while(pq.size()){
        TPQ top=pq.top();
        pq.pop();
        pii u=pii(top.x,top.y);
        int du=top.w;
        if(du!=res[u.x][u.y]) continue;
        for(int i=0;i<4;i++){
            pii v=pii(u.x+dx[i],u.y+dy[i]);
            if(!Valid(v)) continue;
            if(a[v.x][v.y]=='+') continue;
            if(res[v.x][v.y]<min(res[u.x][u.y],disTree[v.x][v.y])){
                res[v.x][v.y]=min(res[u.x][u.y],disTree[v.x][v.y]);
                pq.push(TPQ(v.x,v.y,res[v.x][v.y]));
            }
        }
    }
    cout<<res[t.x][t.y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Enter();
    Init();
    Solve();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
