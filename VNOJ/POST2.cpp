#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
using namespace std;
typedef complex<double> base;

const int NUM_STATE = 18;
const int MAXN = 1 << NUM_STATE;
const int MAP = 50000;
const double PI = acos(-1);

int n;

inline bool getBit(const int &x, const int &k){
    return x & (1 << k);
}

inline int reverseBit(const int &n_bits, int mask){
    for(int i = 0, j = n_bits - 1; i <= j; i++, j--){
        if(getBit(mask, i) != getBit(mask, j)){
            mask ^= 1 << i;
            mask ^= 1 << j;
        }
    }
    return mask;
}

inline vector<base> fft(vector<base> a, bool invert = false){
    int n = a.size();

    for(int i = 0; i < n; i++){
        int j = reverseBit(NUM_STATE, i);
        if(i < j) swap(a[i], a[j]);
    }

    vector<base> a_next(n);

    for(int step = 1; step < n; step <<= 1){
        double angle = PI / step;
        if(invert) angle = -angle;

        base w(1), w_n(cos(angle), sin(angle));
        vector<base> root(step);
        for(int i = 0; i < step; i++){
            root[i] = w;
            w *= w_n;
        }

        int start_even = 0;
        int start_odd = start_even + step;
        while(start_even < n){
            for(int i = 0; i < step; i++){
                a_next[start_even + i] = a[start_even + i] + root[i] * a[start_odd + i];
                a_next[start_even + i + step] = a[start_even + i] - root[i] * a[start_odd + i];
            }

            start_even += 2 * step;
            start_odd = start_even + step;
        }

        for(int i = 0; i < n; i++) a[i] = a_next[i];
    }

    if(invert){
        for(int i = 0; i < n; i++) a[i] /= n;
    }

    return a;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    if(fopen("input.inp", "r")){
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    }

    int n; cin >> n;
    vector<base> a(MAXN), b(MAXN);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x + MAP] += 1;
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b[x + MAP] += 1;
    }

    a = fft(a);
    b = fft(b);

    for(int i = 0; i < MAXN; i++) a[i] *= b[i];

    a = fft(a, true);

    long long res = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        res += round(a[x + 2 * MAP].real());
    }

    cout << res;
    
    return 0;
}