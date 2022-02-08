#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;

const int maxn=2e5+7;

int n,m;
int a[maxn];
struct Neko{
    int l,r,id;
}q[maxn];
int bit[maxn];
map<int,int> d;
int kq[maxn];

inline void update(int x,int val){
    for(;x<=n;x+=x&-x) bit[x]+=val;
}

inline int get(int x){
    int res=0;
    for(;x;x-=x&-x) res+=bit[x];
    return res;
}

inline bool ss(Neko x,Neko y){
    return x.r<y.r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    up(i,1,n) cin>>a[i];
    cin>>m;
    up(i,1,m) cin>>q[i].l>>q[i].r,q[i].id=i;

    sort(q+1,q+m+1,ss);

    int r=1;
    up(i,1,m){
        while(r<=q[i].r){
            update(r,1);
            if(d[a[r]]) update(d[a[r]],-(get(d[a[r]])-get(d[a[r]]-1)));
            d[a[r]]=r;
            r++;
        }
        kq[q[i].id]=get(q[i].r)-get(q[i].l-1);
    }

    up(i,1,m) cout<<kq[i]<<'\n';

    return 0;
}






















