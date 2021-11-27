#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 20;
const int MAXK = 20;

int n, k;
string s;
long long f[MAXN][MAXK];
long long p[MAXN];

long long solve(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++) f[i][j] = -1;
    }
    f[2][0] = f[2][2] = s[1] - '0' + (s[2] - '0') * 10;
    f[2][1] = s[1] - '0' + s[2] - '0';
    for(int i = 3; i <= n; i++){
        for(int j = 0; j <= min(i, k); j++){
            if(f[i - 1][j] != -1) f[i][j] = f[i - 1][j] + (s[i] - '0') * p[i - 1 - j];
            if(j >= 1 && f[i - 1][j - 1] != -1) f[i][j] = max(f[i][j], f[i - 1][j - 1] + (s[i] - '0') * p[j - 1]);
            // cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
        }
    }
    // cout << f[n][k] << '\n';
    return f[n][k];
}

bool getBit(const int &x, const int &k){
    return (x >> (k - 1)) & 1;
}

long long bruteforce(){
    long long ret = 0;
    for(int state = 0; state < (1 << n); state++){
        if(__builtin_popcount(state) != k) continue;
        long long chosen = 0;
        long long other = 0;
        for(int i = 1; i <= n; i++){
            if(getBit(state, i)) chosen = chosen * 10 + s[i] - '0';
            else other = other * 10 + s[i] - '0';
        }
        ret = max(ret, chosen + other);
    }
    return ret;
}

random_device rd;
mt19937 engine32(rd());
mt19937_64 engine64(rd());

int random(const int &l, const int &r){
    uniform_int_distribution<int> rng(l, r);
    return rng(engine32);
}

long long random(const long long &l, const long long &r){
    uniform_int_distribution<long long> rng(l, r);
    return rng(engine64);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    p[0] = 1;
    for(int i = 1; i <= 18; i++) p[i] = p[i - 1] * 10;

    
    int nTest; cin >> nTest;
    // nTest = 500;
    while(nTest--){
        cin >> n >> k;
        cin >> s; 
        
        // n = random(2, 18);
        // k = random(1, n - 1);
        // unsigned long long x = random(p[n - 1], p[n] - 1);
        // stringstream ss; ss << x;
        // ss >> s;

        // cout << "TEST: " << n << ' ' << k << ' ' << s << '\n';

        reverse(s.begin(), s.end());
        s = ' ' + s;
        long long real = solve();
        cout << real << '\n';
        // reverse(s.begin() + 1, s.end());
        // long long brute = bruteforce();
        
        // cout << setw(15) << left << "BRUTEFORCE: " << brute << '\n';
        // cout << setw(15) << left << "SOLUTION: " << real << '\n';

        // if(real == brute) cout << "Correct!\n";
        // else{
        //     cout << "Wrong!\n";
        //     break;
        // }

        // cout << "--------------------------------\n";
    }
    
    return 0;
}