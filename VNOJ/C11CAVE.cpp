#include <bits/stdc++.h>
#define FORE(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int MAXN = 1e5 * 5;
const int INF = 1e9 + 7;
 
using namespace std;
int n,h,ans,a[MAXN],b[MAXN],sl;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("c11cave.inp", "r", stdin);
    freopen("c11cave.out", "w", stdout);
    #endif 
    cin>>n>>h;
    int m=0;
    FORE(i,1,n)
    if (i&1==1) cin>>a[++m];
    else cin>>b[m];
    sort(a+1,a+m+1);
    sort(b+1,b+m+1);
    //FORE(i,1,m) cout<<b[i]<<' ';
    ans=n+1;
    FORE(hh,1,h)
    {
        a[m+1]=hh;
        b[m+1]=h-hh+1;
        int j1=lower_bound(a+1,a+m+2,hh)-a;
        int j2=lower_bound(b+1,b+m+2,h-hh+1)-b;
        //cout<<j1<<' '<<j2<<' ';
        int res=n-j1-j2+2;
        //cout<<res<<endl;
        if (res<ans)
        {
            ans=res;
            sl=1;
        }
        else if (res==ans) ++sl;
    }
    cout<<ans<<' '<<sl;
    return 0;
}