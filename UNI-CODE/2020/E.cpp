#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e3 + 7;
const int MAXM = 2e3 + 7;
const int MAXK = 1e2 + 7;
const long long INF = 1e16 + 7;

struct TEdge{
    int u, v;
};

struct TNode{
    int u, k;
    long long w;
    TNode(int u = 0, int k = 0, long long w = 0){
        this->u = u;
        this->k = k;
        this->w = w;
    }
    friend bool operator <(const TNode x, const TNode &y){
        return (x.w > y.w);
    }
};

int n, m, A, B, K;
int t[MAXK][MAXM];
long long d[MAXK][MAXN];
TEdge e[MAXM];
vector<int> adj[MAXN];

void dijkstra(){
    priority_queue<TNode> pq;
    for(int i = 0; i <= K; i++){
        for(int j = 1; j <= n; j++) d[i][j] = INF;
    }
    d[0][A] = 0;
    pq.push(TNode(A, 0, 0));
    while(!pq.empty()){
        TNode top = pq.top();
        pq.pop();
        int u = top.u;
        int k = top.k;
        long long w = top.w;
        if(w != d[k][u]) continue;
        for(int i: adj[u]){
            int v = e[i].u + e[i].v - u;
            if(t[k][i] + w < d[k][v]){
                d[k][v] = t[k][i] + w;
                pq.push(TNode(v, k, d[k][v]));
            }
        }
        if(k < K){
            d[k + 1][u] = min(w, d[k + 1][u]);
            pq.push(TNode(u, k + 1, w));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n >> m >> A >> B;
    for(int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v >> t[0][i];
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    cin >> K;
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= m; j++) cin >> t[i][j];
    }

    dijkstra();
    long long res = INF;
    for(int i = 0; i <= K; i++) res = min(res, d[i][B]);
    cout << res;
    
    return 0;
}