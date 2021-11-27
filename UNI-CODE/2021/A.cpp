#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 1e5 + 7;

int n, m;
int correct[MAXN], guess[MAXN];
int res[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> correct[i];
    for(int i = 1; i <= m; i++) cin >> guess[i];

    fill(res + 1, res + n + 2, -1);
    for(int i = 1; i <= m; i++){
        res[guess[i]] = correct[guess[i]];
    }

    for(int i = 1; i <= n; i++){
        if(res[i] != -1) cout << res[i] << ' ';
        else{
            bool notavail[6] = {};
            notavail[res[i - 1]] = true;
            notavail[correct[i]] = true;
            if(res[i + 1] != -1) notavail[res[i + 1]] = true;
            for(int j = 1; j <= 5; j++){
                if(notavail[j] == false){
                    res[i] = j;
                    cout << j << ' ';
                    break;
                }
            }
        }
    }
    
    return 0;
}