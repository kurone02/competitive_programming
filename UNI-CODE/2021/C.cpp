#include <iostream>
#include <cstdlib>
using namespace std;

int n;
string s;
long long res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> n; cin >> s;
    s = ' ' + s;
    int current_head = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i + 1]){
            res += 1ll * (i - current_head) * (n - i);
            current_head = i;
        }
    }
    cout << res;
    
    return 0;
}