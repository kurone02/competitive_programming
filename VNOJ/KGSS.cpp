//
// Created by root on 02/05/2018.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
#define CL(x) (x << 1)
#define CR(x) (x << 1) + 1
#define X first
#define Y second
#define mp make_pair
typedef pair <int, int> pii;
struct SegTree {
    pii it[4 * N];
    int L[4 * N], H[4 * N];
    pii combine(const pii &a, const pii &b) {
        vector <int> cur;
        cur.clear();
        cur.push_back(a.X);
        cur.push_back(a.Y);
        cur.push_back(b.X);
        cur.push_back(b.Y);
        sort(cur.rbegin(), cur.rend());
        return mp(cur[0], cur[1]);
    }
    void build(const int x, const int low, const int high) {
        if (low > high) return;
        L[x] = low; H[x] = high;
        if (low == high) {
            it[x] = mp(a[low], -1);
            return;
        }
        int mid = (low + high) >> 1;
        build(CL(x), low, mid);
        build(CR(x), mid + 1, high);
        it[x] = combine(it[CL(x)], it[CR(x)]);
    }
    void update(const int x, const int pos, const int val) {
        if (L[x] > pos || H[x] < pos) return;
        if (L[x] == H[x]) {
            it[x] = mp(val, -1);
            return;
        }
        update(CL(x), pos, val);
        update(CR(x), pos, val);
        it[x] = combine(it[CL(x)], it[CR(x)]);
    }
    pii query(const int x, const int u, const int v) {
        if (L[x] > v || H[x] < u) return mp(-1, -1);
        if (u <= L[x] && H[x] <= v) return it[x];
        return combine(query(CL(x), u, v), query(CR(x), u, v));
    }
} IT;
int main() {
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    ios_base:: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    IT.build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'U') {
            int i, x;
            cin >> i >> x;
            IT.update(1, i, x);
        } else {
            int u, v;
            cin >> u >> v;
            pii ans = IT.query(1, u, v);
            cout << ans.X + ans.Y << "\n";
        }
    }
    return 0;
}
