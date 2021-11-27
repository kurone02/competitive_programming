#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 7;

int n, nObjects;
vector<string> res;
vector<int> adj[MAXN];
map<string, int> encode;
string decode[MAXN];
bool visited[MAXN];

void hashing(const string &s){
    auto it = encode.find(s);
    if(it == encode.end()){
        encode[s] = ++nObjects;
        decode[nObjects] = s;
    }
}

void Dfs(const int &u){
    visited[u] = true;
    for(int v: adj[u]) if(!visited[v]){
        res.push_back(decode[v]);
        Dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        string p, token, q;
        cin >> p >> token >> q;
        hashing(p); hashing(q);
        adj[encode[p]].push_back(encode[q]);
    }
    hashing("Baba");
    Dfs(encode["Baba"]);
    sort(res.begin(), res.end());
    for(string x: res) cout << x << '\n';
    
    return 0;
}