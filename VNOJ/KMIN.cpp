#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;

const int maxn=1e5+7;

int n,m,k;
int a[maxn],b[maxn];
struct Neko{int sum,id;};
struct cmp{bool operator()(Neko x,Neko y){return x.sum>y.sum;}};
priority_queue<Neko,vector<Neko>,cmp> q;
int MinID[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>m>>n>>k;
    up(i,1,m) cin>>a[i];
    up(i,1,n) cin>>b[i];

    sort(a+1,a+m+1);
    up(i,1,n) q.push({a[1]+b[i],i});
    fill(MinID,MinID+maxn,1);

    while(k--){
        int sum=q.top().sum,
            id=q.top().id;
        q.pop();
        cout<<sum<<'\n';
        MinID[id]++;
        if(MinID[id]<=m) q.push({a[MinID[id]]+b[id],id});
    }

    return 0;
}






















