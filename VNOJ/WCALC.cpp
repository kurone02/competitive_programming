#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define pb push_back
//#define Kamisama

typedef long long ll;

using namespace std;

const int maxn=2e5+7;

ll a,b,m,n;
ll kq;

inline void Enter(){
    cin>>b>>n;
}

inline void Solve(){
    for(m=1;m<=2*n;m++){
        a=2*b*m*n-b*m*m;
        if(a%(n*n) || a<=0) continue;
        a/=n*n;
        kq+=(a*n*n-2*b*m*n+b*m*m==0);
    }
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifdef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif //Kamisama

    Enter();
    Solve();

    return 0;
}
