#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int maxn=1e5+7;
const int mod=5000000;

int n,k,maxa;
int a[maxn];
int bit[maxn];
int lis[maxn];
int kq=0;

inline void update(int x,int val){
    for(;x<=maxa;x+=x&-x) bit[x]=(bit[x]+val)%mod;
}

inline int get(int x){
    int res=0;
    for(;x;x-=x&-x) res+=bit[x];
    return res%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>k;
    up(i,1,n) cin>>a[i],a[i]++,maxa=max(maxa,a[i]),lis[i]=1;

    up(adiusgh,2,k){
        fill(bit,bit+maxa+1,0);
        up(i,1,n) update(a[i],lis[i]),lis[i]=get(a[i]-1);
    }

    up(i,1,n) kq=(kq+lis[i])%mod;
    cout<<kq;

    return 0;
}
