#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#include <algorithm>
#define salary first
#define id second
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e5+3;

int n,l[maxn],r[maxn],bit[maxn];
long long result;
pair<int,int> staff[maxn];
vector<int> adj[maxn];

inline void Dfs(const int &u){
    static int num=0;
    l[u]=++num;
    for(int v: adj[u]) Dfs(v);
    r[u]=num;
}

inline void Update(int x){
    for(;x<=n;x+=x&-x) bit[x]++;
}

inline int Get(int x){
    int res=0;
    for(;x;x-=x&-x) res+=bit[x];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    cin>>n; staff[1].id=1; cin>>staff[1].salary;
    for(int p,i=2;i<=n;i++){
        cin>>p>>staff[i].salary;
        adj[p].push_back(staff[i].id=i);
    }
    Dfs(1); sort(staff+1,staff+n+1);
    for(int i=1,j=1;i<=n;i++){
        while(j<i && staff[j].salary<staff[i].salary) Update(l[staff[j++].id]);
        int total=Get(r[staff[i].id])-Get(l[staff[i].id]-1);
        result+=1ll*total*(total-1)/2;
    }
    cout<<result;

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
