#include<bits/stdc++.h>
#define task "TEST"

const long long maxn=1e4+5;
const long long w=1e9+7;

using namespace std;

int n,m,kq;
int a[30][maxn];
int c[30][maxn];
int f[maxn];

inline void init(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j],c[i][a[i][j]]=j;
    }
}

inline bool check(int i,int j){
    for(int k=2;k<=m;k++) if(c[k][i]>c[k][j]) return false;
    return true;
}

inline void prepare(){
    for(int i=1;i<=n;i++){
        //bool meo=true;
        for(int j=1;j<i;j++)
            if(check(a[1][j],a[1][i]))
                f[a[1][i]]=max(f[a[1][i]],f[a[1][j]]+1),kq=max(kq,f[a[1][i]]);
    }
}

inline void solve(){
    cout<<kq+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    init();
    prepare();
    //while(t--)
    solve();
    return 0;
}
