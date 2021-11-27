#include <iostream>
#include <cstdlib>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> s;
    s = '0' + s;
    for(int i = (int)s.size() - 1; i >= 1; i--){
        if(s[i] >= '5'){
            bool carry = true;
            for(int j = (int)s.size() - 1; j >= i; j--) s[j] = '0';
            for(int j = i - 1; j >= 0 && carry; j--){
                if(s[j] == '9') s[j] = '0';
                else s[j]++, carry = false;
            }
        }
    }
    if(s[0] == '0') s.erase(s.begin());
    cout << s;
    
    return 0;
}