#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

int m, q;
string cycle;

string num_to_str(int x){
    stringstream ss;
    ss << x;
    string res; ss >> res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }
    
    cin >> q >> m;

    int cur = 1, pre = 1;
    cycle = "011";
    for(int i = 3; i < 6*m; i++){
        int temp = cur;
        cur += pre;
        pre = temp;
        if(cur >= m) cur -= m;
        if(cur == 1  && pre == 0){
            cycle.pop_back();
            break;
        }
        cycle += num_to_str(cur);
    }
    while(q--){
        long long n; cin >> n;
        int sum_n_digit = cycle.size();
        cout << cycle[n % sum_n_digit] << '\n';
    }
    
    return 0;
}