#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
//#define Kamisama

typedef long long ll;

using namespace std;

const int maxn=1e3+7;

int n,k;
ll s[maxn][maxn];
ll kq;

inline void Enter(){
    cin>>n>>k;
    up(i,1,n)up(j,1,n){
        int x;
        cin>>x;
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
    }
}

inline ll get(int i,int j,int u,int v){
    return s[u][v]-s[u][j-1]-s[i-1][v]+s[i-1][j-1];
}

inline void Solve(){
    up(i,1,n-k+1) up(j,1,n-k+1) kq=max(kq,get(i,j,i+k-1,j+k-1));
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
