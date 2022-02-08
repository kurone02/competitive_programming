#include<bits/stdc++.h>
#define task "LIS"

const long long maxn=1e6+5;
const long long w=1e8;

using namespace std;

int n,kq=-1,len;
int a[maxn],res[maxn];
int f[maxn];
int d[maxn],trace[maxn];

inline void init(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    fill(f,f+maxn-5,1);
    trace[1]=0;
}

inline bool ss(int x,int y){return f[x]>f[y];}

inline int bs(int k,int x){
    int l=1,h=k;
    while(l<=h){
        int mid=(l+h)/2;
        if(a[d[mid]]<x) l=mid+1;
        else h=mid-1;
    }
    return h;
}

inline void solve(){
    int m=1; d[1]=1; trace[1]=0;
    for(int i=2;i<=n;i++){
        int k=bs(m,a[i]);
        f[i]=k+1;
        d[k+1]=i;
        if(k+1>m) m=k+1;
        trace[i]=d[k];
    }
    cout<<m<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    init();
    solve();
    return 0;
}
