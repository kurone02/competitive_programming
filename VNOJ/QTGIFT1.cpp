#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;

const int maxn=1e6+7;

int n,k;
ll a[maxn],f[maxn],sum;
deque<int> q;

inline void Enter(){
    cin>>n>>k;
    up(i,1,n) cin>>a[i];
}

inline void Init(){
    up(i,1,n+1){
        while(q.size() && f[q.back()]>=f[i-1]) q.pop_back();
        q.push_back(i-1);
        f[i]=f[q.front()]+a[i];
        if(i-q.front()+1>k) q.pop_front();
    }
}

inline void Solve(){
    up(i,1,n) sum+=a[i];
    cout<<sum-f[n+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}
