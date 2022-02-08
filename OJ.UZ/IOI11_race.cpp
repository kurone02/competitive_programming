#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
using namespace std;
const int maxn=2e5+7;
const int maxk=1e6+7;
const int inf=1e9+7;
 
struct Edges{
    int x,y,w;
};
 
int n,k,currentLab,res;
int subSize[maxn],lab[maxn],d[maxn],lv[maxn],f[maxk];
bool disabled[maxn];
vector<int> adj[maxn],tobeProcessed,depthList;
Edges e[maxn];
 
inline void CalcSize(const int &u){
    lab[u]=currentLab;
    subSize[u]=1;
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(disabled[v] || lab[v]==currentLab) continue;
        CalcSize(v);
        subSize[u]+=subSize[v];
    }
}
 
inline int FindCentroid(int u){
    int halfSize=subSize[u]/2;
    while(true){
        int heavyVertex=-1;
        for(int i: adj[u]){
            int v=e[i].x+e[i].y-u;
            if(disabled[v] || subSize[v]>subSize[u]) continue;
            if(subSize[v]>halfSize){
                heavyVertex=v;
                break;
            }
        }
        if(heavyVertex==-1) break;
        u=heavyVertex;
    }
    return u;
}
 
inline void CalcDepth(const int &u){
    lab[u]=currentLab;
    if(d[u]>k) return;
    depthList.push_back(d[u]);
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(disabled[v] || lab[v]==currentLab) continue;
        d[v]=d[u]+e[i].w;
        lv[v]=lv[u]+1;
        CalcDepth(v);
    }
}
 
inline void Query(const int &u){
    lab[u]=currentLab;
    if(d[u]>k) return;
    res=min(res,f[k-d[u]]+lv[u]);
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(disabled[v] || lab[v]==currentLab) continue;
        Query(v);
    }
}
 
inline void Update(const int &u){
    lab[u]=currentLab;
    if(d[u]>k) return;
    f[d[u]]=min(f[d[u]],lv[u]);
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(disabled[v] || lab[v]==currentLab) continue;
        Update(v);
    }
}
 
inline void ProcessTree(int u){
    currentLab++;
    CalcSize(u);
    u=FindCentroid(u);
    disabled[u]=true;
    for(int x: depthList) f[x]=inf;
    depthList.resize(0);
    lv[u]=d[u]=0;
    currentLab++;
    CalcDepth(u);
    f[0]=0;
    for(int i: adj[u]){
        int v=e[i].x+e[i].y-u;
        if(disabled[v]) continue;
        currentLab++; Query(v);
        currentLab++; Update(v);
        tobeProcessed.push_back(v);
    }
}
 
int best_path(int N, int K, int H[][2], int L[]){
    tie(n,k)=tie(N,K);
    for(int i=0;i<n-1;i++){
        e[i]={H[i][0]+1,H[i][1]+1,L[i]};
        adj[e[i].x].push_back(i);
        adj[e[i].y].push_back(i);
    }
  	fill(f,f+maxk+1,inf);
    res=inf; tobeProcessed.push_back(1);
    while(tobeProcessed.size()){
        int u=tobeProcessed.back();
        tobeProcessed.pop_back();
        ProcessTree(u);
    }
    return (res==inf)? -1 : res;
}