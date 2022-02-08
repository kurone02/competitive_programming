#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

typedef long long ll;

using namespace std;

const int maxn=2e3+7;
const int inf=1e9+7;

int n;
struct Neko{int x,y;}a[maxn];
double p[maxn];
ll kq;

inline ll Solve(int k){
    ll res;
    rep(i,1,k){
        int dx=a[i].x-a[k].x,
            dy=a[i].y-a[k].y;
        if(dy!=0) p[i]=(double)dx/dy;
        else p[i]=inf;
    }
    sort(p+1,p+k);
    ll cnt=1;
    rep(i,2,k){
        //cerr<<p[i]<<"><"<<p[i-1]<<"->"<<(p[i]!=p[i-1])<<' ';
        if(p[i]!=p[i-1]) res+=cnt*(cnt-1)/2,cnt=0;
        cnt++;
    }
    //cerr<<'\n';
    res+=cnt*(cnt-1)/2;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>n;
    up(i,1,n) cin>>a[i].x>>a[i].y;

    up(i,3,n) kq+=Solve(i);

    cout<<kq;

    return 0;
}
