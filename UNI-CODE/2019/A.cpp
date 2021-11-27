#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    int nTest;
    for(cin >> nTest; nTest--;){
        string s; cin >> s;
        size_t n = s.size();
        if(n == 7){
            bool check[26] = {};
            int cnt = 0;
            for(char x: s){
                if(!check[x - 'A']){
                    check[x - 'A'] = true;
                    cnt++;
                }
            }
            if(cnt == 2){
                if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3] && s[3] != s[4] && s[4] != s[5] && s[5] == s[6]){
                    cout << 1 << '\n';
                } else{
                    cout << 0 << '\n';
                }
            } else{
                cout << 0 << '\n';
            }
        } else{
            cout << 0 << '\n';
        }
    }
    
    return 0;
}