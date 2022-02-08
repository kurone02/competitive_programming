#include <iostream>
#include <cstdio>
#include <map>
#define Kami
#define taskname "YPKTH"
using namespace std;
struct TNodes;
typedef TNodes* PNodes;
const int maxn = 1e5 + 7;

struct TNodes{
    int cnt;
    PNodes left, right;
    inline TNodes(int cnt = 0, PNodes left = NULL, PNodes right = NULL):
        cnt(cnt), left(left), right(right){}
    inline PNodes update(const int &l, const int &r, const int &pos);
};

PNodes nil = new TNodes;

inline PNodes TNodes::update(const int &l, const int &r, const int &pos){
    if(l > pos || r < pos) return this;
    if(l == r) return new TNodes(this->cnt + 1, nil, nil);
    int mid = (l + r) >> 1;
    return new TNodes(this->cnt + 1, this->left->update(l, mid, pos), this->right->update(mid + 1, r, pos));
}

int n, q, nValues, a[maxn], decode[maxn];
map<int, int> encode;
PNodes root[maxn];

inline void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], encode[a[i]] = 0;
}

inline void Init(){
    for(auto &it: encode){
        it.second = ++nValues;
        decode[nValues] = it.first;
    }
    nil->left = nil->right = nil;
    root[0] = nil;
    for(int i = 1; i <= n; i++){
        root[i] = root[i - 1]->update(1, nValues, encode[a[i]]);
    }
}

inline int Query(const PNodes &i, const PNodes &j, const int &l, const int &r, const int &k){
    if(l == r) return l;
    int cnt = (j->left->cnt) - (i->left->cnt);
    int mid = (l + r) >> 1;
    if(cnt < k) return Query(i->right, j->right, mid + 1, r, k - cnt);
    return Query(i->left, j->left, l, mid, k);
}

inline void Solve(){
    cin >> q;
    for(int i, j, k; q--;){
        cin >> i >> j >> k;
        int res = Query(root[i - 1], root[j], 1, nValues, k);
        cout << decode[res] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Input();
    Init();
    Solve();
    return 0;
}
