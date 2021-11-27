#include <iostream>
#include <cstdlib>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;
const int MAXL = 5 + 1;
const string acronym = "UNIST";

int n, f[MAXN][MAXL];
string w[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];

	for(int i = 0; i <= n; i++) f[i][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			f[i][j] = f[i - 1][j];
			for(int k = 1; k <= min(j, (int)w[i].size()); k++){
				if(w[i].substr(0, k) == acronym.substr(j - k, k)){
					f[i][j] += f[i - 1][j - k];
					if(f[i][j] >= MOD) f[i][j] -= MOD;
				}
			}
		}
	}
	cout << f[n][5];
    
    return 0;
}