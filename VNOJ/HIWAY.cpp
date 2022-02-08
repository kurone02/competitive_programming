#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#include <limits>
#include <queue>
#define Kami
#define taskname "TEST"
using namespace std;

template<typename FlowType, typename CostType> class MinCostMaxFlow{
public:
    struct TEdges{
        int x,y;
        FlowType cap,flow;
        CostType cost;
        inline TEdges(int _x=0, int _y=0, FlowType _cap=0, CostType _cost=0, FlowType _flow=0){
            x=_x; y=_y; cap=_cap; cost=_cost; flow=_flow;
        }
    };
    struct TPQ{
        int vertex; CostType w;
        inline TPQ(int _vertex, CostType _w){vertex=_vertex; w=_w;}
        inline bool operator <(const TPQ &other) const{return w>other.w;}
    };
    int n,source,sink;
    bool aldreadyUsedMaxFlow,aldreadyUsedMinCost;
    FlowType flowVal;
    CostType costVal;
    vector<TEdges> e;
    vector<int> trace;
    vector<bool> inQueue;
    vector<CostType> d;
    vector<vector<int> >adj;
 
    inline MinCostMaxFlow(int _n, int _source, int _sink){
        n=_n; source=_source; sink=_sink;
        aldreadyUsedMaxFlow=aldreadyUsedMinCost=false;
        flowVal=0; costVal=0; inQueue.resize(n);
        trace.resize(n); adj.resize(n); d.resize(n);
    }
 
    inline void AddEdge(const int &u, const int &v, const FlowType &cap, const CostType &cost){
        adj[u].push_back(e.size());
        e.push_back(TEdges(u,v,cap,cost));
        adj[v].push_back(e.size());
        e.push_back(TEdges(v,u,0,-cost));
    }
 
    inline bool FindPath(){
        fill(trace.begin(),trace.end(),-1);
        fill(d.begin(),d.end(),numeric_limits<CostType>::max());
        fill(inQueue.begin(),inQueue.end(),false);
        queue<int> q;
        q.push(source); inQueue[source]=true; d[source]=0; trace[source]=-2;
        while(q.size()){
            int u=q.front(); inQueue[u]=false;
            q.pop();
            for(int i: adj[u]) if(e[i].cap>0){
                int v=e[i].y;
                int w=e[i].cost;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    trace[v]=i;
                    if(!inQueue[v]){
                        q.push(v);
                        inQueue[v]=true;
                    }
                }
            }
        }
        return trace[sink]!=-1;
    }
 
    inline void AugmentFlow(){
        FlowType delta=numeric_limits<FlowType>::max();
        for(int u=sink,i;(i=trace[u])>=0;u=e[i].x) delta=min(delta,e[i].cap);
        for(int u=sink,i;(i=trace[u])>=0;u=e[i].x){
            e[i].cap-=delta;
            e[i^1].cap+=delta;
            e[i].flow+=delta;
            e[i^1].flow-=delta;
        }
        flowVal+=delta;
        costVal+=d[sink]*delta;
    }
 
    inline FlowType MaxFlow(){
        if(aldreadyUsedMaxFlow) return flowVal;
        aldreadyUsedMaxFlow=true;
        while(FindPath()) AugmentFlow();
        return flowVal;
    }
 
    inline CostType MinCost(){
        if(aldreadyUsedMinCost) return costVal;
        aldreadyUsedMinCost=true; MaxFlow();
        return costVal;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    int n,m,source,sink; cin>>n>>m>>source>>sink;
    MinCostMaxFlow<int,int> edmond(n+1,0,sink);
    edmond.AddEdge(0,source,2,0);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edmond.AddEdge(u,v,1,w);
        edmond.AddEdge(v,u,1,w);
    }
    if(edmond.MaxFlow()!=2) return cout<<-1,0;
    cout<<edmond.MinCost()<<'\n';
    vector<int> adj[n+1];
    for(int i=2;i<edmond.e.size();i+=2){
        int flow=max(edmond.e[i].flow,edmond.e[i^1].flow);
        if(flow==0) continue;
        adj[edmond.e[i].x].push_back(edmond.e[i].y);
        adj[edmond.e[i].y].push_back(edmond.e[i].x);
    }
    vector<int> path; vector<bool> visisted(n+1);
    path.push_back(source); visisted[source]=true;
    int u=adj[source][0];
    for(;u!=sink;){
        visisted[u]=true;
        path.push_back(u);
        for(int v: adj[u]) if(!visisted[v]){
            u=v;
            break;
        }
    }
    path.push_back(sink);
    cout<<path.size()<<' '; for(int x: path) cout<<x<<' '; cout<<'\n';
    path.clear(); path.push_back(source);
    for(u=adj[source][1];u!=sink;){
        visisted[u]=true;
        path.push_back(u);
        for(int v: adj[u]) if(!visisted[v]){
            u=v;
            break;
        }
    }
    path.push_back(sink);
    cout<<path.size()<<' '; for(int x: path) cout<<x<<' '; cout<<'\n';

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
