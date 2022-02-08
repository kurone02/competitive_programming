#include<bits/stdc++.h>
#define task "TEST"

const long long maxn=1e6+5;
const long long w=1e9+7;
const long double pi=3.14159265;
const int inf=1e9;

using namespace std;

int n,k;
int a[20];
long long f[1<<17][20];
long long kq;

inline void init(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}

inline bool checkbit(int x,int i){
    return  (x>>i)&1;
}

inline void prepare(){
    for(int i=1;i<=n;i++) f[1<<(i-1)][i]=1;
    for(int bit=0;bit<(1<<n);bit++){
        for(int i=1;i<=n;i++){
            if(!checkbit(bit,i-1)) continue;
            for(int j=1;j<=n;j++){
                if(checkbit(bit,j-1)&&abs(a[i]-a[j])>k) f[bit][i]+=f[bit^(1<<(i-1))][j];
            }
        }
    }
}

inline void solve(){
    for(int i=1;i<=n;i++) kq+=f[(1<<n)-1][i];
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    init();
    prepare();
    //while(t--)
    solve();
    return 0;
}
