#include <iostream>
#include <queue>
#define taskname "TEST"

using namespace std;
typedef pair<int,int> pii;
const int inf=1e9+7;

int n,a[5000];
int f[50001];

inline void Enter(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
}

inline bool Minimize(int &target,const int &value){
    if(target>value) return target=value,true;
    return false;
}

inline void Bfs(){
    fill(f,f+50001,inf);
    priority_queue<pii> pq;
    pq.push(pii(0,0));
    f[0]=0;
    while(pq.size()){
        int u=pq.top().second;
        int w=-pq.top().first;
        pq.pop();
        if(w>f[u]) continue;
        for(int i=1;i<n;i++){
            int v=(u+a[i])%a[0];
            if(Minimize(f[v],w+a[i])) pq.push(pii(-f[v],v));
        }
    }
}

inline void Solve(){
    cin>>n;
    for(int x;n;n--){
        cin>>x;
        cout<<(f[x%a[0]]<=x? "TAK" : "NIE")<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Enter();
    Bfs();
    Solve();
    return 0;
}