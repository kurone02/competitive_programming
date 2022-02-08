#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e5+3;
const int logn=19;
 
int n,m,lv[maxn],par[maxn],f[maxn][logn];
int timeIn[maxn],timeOut[maxn];
long long dp[maxn],bit[maxn];
vector<int> adj[maxn],road[maxn];
struct Query{int a,b,c;}q[maxn];
 
inline void Dfs(const int &u, const int &p){
	static int nVisits=0;
	f[u][0]=p; par[u]=p;
	timeIn[u]=++nVisits;
	for(int i=1;i<logn;i++){
		int v=f[u][i-1];
		if(v==-1) f[u][i]=-1;
		else f[u][i]=f[v][i-1];
	}
	for(int v: adj[u]) if(v!=p){
		lv[v]=lv[u]+1;
		Dfs(v,u);
	}
	timeOut[u]=nVisits;
}
 
inline int Jump(int u, int k){
	int cur=0;
	for(;k;k>>=1){
		if(k&1) u=f[u][cur];
		cur++;
	}
	return u;
}
 
inline int Lca(int u, int v){
	if(lv[v]<lv[u]) swap(u,v);
	v=Jump(v,lv[v]-lv[u]);
	if(u==v) return u;
	for(int i=logn-1;i>=0;i--) if(f[u][i]!=f[v][i]){
		u=f[u][i]; v=f[v][i];
	}
	return par[u];
}
 
inline void Update(int x, const int &val){
	for(;x<=n;x+=x&-x) bit[x]+=val;
}
 
inline int Get(int x){
	long long res=0;
	for(;x;x-=x&-x) res+=bit[x];
	return res;
}
 
inline void Solve(const int &u, const int &p){
	long long sumChild=0;
	for(int v: adj[u]) if(v!=p){
		Solve(v,u);
		sumChild+=dp[v];
	}
	dp[u]=sumChild;
	for(int i: road[u]){
		dp[u]=max(dp[u],sumChild-Get(timeIn[q[i].a])-Get(timeIn[q[i].b])+q[i].c);
	}
	Update(timeIn[u],dp[u]-sumChild);
	Update(timeOut[u]+1,sumChild-dp[u]);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Dfs(1,-1);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].a>>q[i].b>>q[i].c;
		road[Lca(q[i].a,q[i].b)].push_back(i);
	}
	Solve(1,-1);
	cout<<dp[1];
	return 0;
}