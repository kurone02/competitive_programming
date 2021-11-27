#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 2e5 + 7;

int n, res, deg[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
    }

    for(int i = 0; i < n; i++) res += (deg[i] == 1);
    cout << (res + 1) / 2;
    
    return 0;
}