#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define val first
#define id second
#define taskname "VNEMPIRE"
using namespace std;
typedef pair<int,int> pii;
const int maxN=1e5+3;

struct TPQ{
    pii *u,*v;
    int val;
    inline TPQ(){}
    inline TPQ(pii *u, pii *v){
        this->u=u;
        this->v=v;
        this->val=abs(u->val-v->val);
    }
    friend inline bool operator <(const TPQ &x, const TPQ &y){
        return x.val>y.val;
    }
};

int n,lab[maxN];
pii x[maxN],y[maxN],z[maxN];
priority_queue<TPQ> pq;

inline void Enter(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].val>>y[i].val>>z[i].val;
        x[i].id=y[i].id=z[i].id=i;
    }
}

inline void Init(){
    x[n+1].id=y[n+1].id=z[n+1].id=-1;
    sort(x+1,x+n+1);sort(y+1,y+n+1);sort(z+1,z+n+1);
    for(int i=1;i<n;i++) pq.push(TPQ(x+i,x+i+1));
    for(int i=1;i<n;i++) pq.push(TPQ(y+i,y+i+1));
    for(int i=1;i<n;i++) pq.push(TPQ(z+i,z+i+1));
    fill(lab,lab+n+1,-1);
}

inline int FindSet(const int &x){
    return lab[x]<0? x : lab[x]=FindSet(lab[x]);
}

inline bool Union(int x, int y){
    if(x==y) return false;
    if(lab[x]>lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
    return true;
}

inline void Solve(){
    long long res=0;
    for(int cnt=0;pq.size() && cnt!=n-1;){
        auto top=pq.top();
        pq.pop();
        int r=FindSet(top.u->id);
        int s=FindSet(top.v->id);
        if(Union(r,s)){
            res+=top.val;
            cnt++;
        }
        pii *nxt=top.v+1;
        if(nxt->id!=-1) pq.push(TPQ(top.u,nxt));
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Enter();
    Init();
    Solve();
    return 0;
}
