#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=5e3+7;
int n,h[maxn],res;
vector<int> adj[maxn];
inline void Bfs(const int &root){
    queue<int> q;
    fill(h,h+n+1,0);
    h[root]=1;
    int sum=1,nEdges=0;
    q.push(root);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v: adj[u]){
            if(h[v]) continue;
            nEdges++;
            h[v]=h[u]+1;
            sum+=h[v];
            q.push(v);
        }
    }
    if(nEdges==n-1)res=min(res,sum);
}
inline void Read(int &x){
    register char c;
    for(c=getchar();c>'9'||c<'0';c=getchar());
    for(x=0;'0'<=c&&c<='9';c=getchar())x=10*x+c-'0';
}
inline void Write(const int &x){
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}
int main(){
    Read(n);
    for(int i=1,k=0;i<=n;i++){
        Read(k);
        for(int j=1,x=0;j<=k;j++) Read(x),adj[x].push_back(i);
    }
  	res=(int)1e9+7;
    for(int i=1;i<=n;i++) Bfs(i);
    Write(res);
    return 0;
}