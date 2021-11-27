#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 1e4 + 7;
const int MAXK = 1e3 + 7;

int n, k;
int important[MAXN], required_time[MAXN];
int dp[MAXK][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> important[i] >> required_time[i];

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            if(required_time[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - required_time[i]] + important[i]);
        }
    }
    cout << dp[k][n];
    
    return 0;
}