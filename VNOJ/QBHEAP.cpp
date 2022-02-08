#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 20000;
string s;
priority_queue <int> h;
char key;
int num, a[MAXN];
 
bool cmp(int a, int b) {
    return (a > b);
}
 
int main() {
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    // solve
    getline(cin, s);
    do {
        key = s[0];
        if (key == '+') {
            s.erase(0,1);
            num = atoi(s.c_str());
            if (h.size()<15000) h.push(num);
        } else if (!h.empty())
        {
            num = h.top();
            while (!h.empty() && h.top()==num) h.pop();
        }
        getline(cin, s);
    } while (s != "");
    // pop
    int res = 0;
    while (!h.empty()) {
        res++;
        a[res] = h.top();
        while (!h.empty() && h.top()==a[res]) h.pop();
    }
    // print
    cout << res << endl;
    for (int i = 1; i <= res; i++) cout << a[i] << endl;
    return 0;
}