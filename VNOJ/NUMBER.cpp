#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
const int maxn=1e4+7;
const int inf=1e9+7;

int n,m,t,res,cntSCC;
int *num,*low,*deg,*scc;
vector<int> *adj;
stack<int> st;

inline void Enter(){
    cin>>n>>m>>t;
    adj=new vector<int>[n];
    for(int i=0,u,v;i<m;i++)
        cin>>u>>v, u--,v--,
        adj[u].push_back(v);
}

inline void Minimize(int &target, const int &value){target=(target>value)? value : target;}

inline void Tarjan(const int &u){
    static int nVisit=0;
    low[u]=num[u]=nVisit++;
    st.push(u);
    for(int v: adj[u])
        if(num[v]!=-1) Minimize(low[u],num[v]);
        else Tarjan(v),Minimize(low[u],low[v]);
    if(low[u]==num[u]) for(int v=-1;v!=u;){
        v=st.top(); st.pop();
        num[v]=low[v]=inf;
        scc[v]=cntSCC++;
    }
}

inline void Solve(){
    num=new int[n]; low=new int[n];
    scc=new int[n]; deg=new int[n]; 
    fill(deg,deg+n,0); fill(num,num+n,-1);
    for(int i=0;i<n;i++) if(num[i]==-1) Tarjan(i);
    for(int u=0;u<n;u++) for(int v: adj[u]) deg[scc[u]]+=(scc[u]!=scc[v]);
    for(int i=0;i<cntSCC;i++) res+=!deg[i];
    cout<<res-(deg[scc[t-1]]==0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Enter();
    Solve();
    return 0;
}