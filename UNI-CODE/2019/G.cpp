#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 7;
const int MOD = 1e9 + 7;
const int BASE = 571;

int n, res, sa[MAXN], lcp[MAXN];
string s;

inline void BuildSuffixArray(){
    int *sb = new int[n], *key = new int[n], *head = new int[n];
    bool *mark = new bool[n];
    for(int i = 0; i < n; i++) sa[i] = i;
    sort(sa, sa + n, [](const int &i, const int &j){
        return s[i] < s[j];
    });
    mark[0] = false;
    for(int i = 1; i < n; i++) mark[i] = (s[sa[i]] != s[sa[i - 1]]);
    for(int k = 1; k < n; k *= 2){
        int nKey = 0;
        head[0] = 0;
        for(int i = 0; i < n; i++){
            if(mark[i]) head[++nKey] = i;
            key[sa[i]] = nKey;
        }
        if(nKey == n - 1) break;
        for(int i = 0 ; i < n; i++) sb[i] = (sa[i] - k + n) % n;
        for(int i = 0 ; i < n; i++) sa[head[key[sb[i]]]++] = sb[i];
        for(int i = 1 ; i < n; i++) mark[i] |= (key[(sa[i] + k) % n] != key[(sa[i - 1] + k) % n]);
    }
}

inline void BuildLCP(){
    int *rnk = new int[n];
    for(int i = 0; i < n; i++) rnk[sa[i]] = i;
    lcp[0] = 0;
    for(int i = 0, q = 0; i < n - 1; i++){
        int j = sa[rnk[i] - 1];
        while(s[i + q] == s[j + q]) q++;
        lcp[rnk[i]] = q;
        if(q) q--;
    }
}

bool check(const int &k){
    int min_id = sa[0];
    int max_id = sa[0];
    lcp[n] = -1;
    for(int i = 1; i <= n; i++){
        if(lcp[i] >= k){
            min_id = min(min_id, sa[i]);
            max_id = max(max_id, sa[i]);
        } else{
            if(max_id - min_id >= k) return true;
            min_id = sa[i];
            max_id = sa[i];
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    cin >> s; s.push_back('@');
    n = s.size();

    BuildSuffixArray();
    BuildLCP();

    int l = 1, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)) l = m + 1;
        else r = m - 1;
    }
    if(r == 0) cout << -1;
    else cout << r;
    
    return 0;
}