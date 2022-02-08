#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

const int maxn=3e5+7;
const ll mod=1e9+7;

int n,k;
int a[maxn];
int f[maxn],g[maxn];
int kq;

inline void Enter(){
    cin>>n>>k;
    up(i,1,n) cin>>a[i];
}

inline void ComputeF(){
    deque<int> mn,mx;
    f[0]=1;
    up(i,1,n) up(j,f[i-1],i){
        while(mn.size() && mn.front()<j) mn.pop_front();
        while(mx.size() && mx.front()<j) mx.pop_front();

        while(mn.size() && a[mn.back()]>=a[i]) mn.pop_back();
        while(mx.size() && a[mx.back()]<=a[i]) mx.pop_back();

        mn.pb(i), mx.pb(i);

        if(a[mx.front()]-a[mn.front()]<=k){
            f[i]=j;
            break;
        }
    }
}

inline void ComputeG(){
    up(i,1,n) g[i]=max(g[i-1],i-f[i]+1);
}


inline void Solve(){
    up(i,1,n) kq=max(kq,i-f[i]+1+g[f[i]-1]);
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    ComputeF();
    ComputeG();
    Solve();

    return 0;
}
