#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e5+7;

int n;
int a[2*maxn];
ll s[2*maxn];
deque<int> q;
int kq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
   // freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);

    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,n+1,2*n) a[i]=a[i-n];

    up(i,1,2*n) s[i]=s[i-1]+a[i];

    int k=0;
    up(i,1,2*n){
        while(q.size() && s[q.back()]>=s[i]) q.pop_back();
        q.pb(i);
        if(q.front()+n+1<=i) q.pop_front();
        if(i>=n+1) kq+=s[q.front()]-s[k]>0,k++;
    }

    cout<<kq;

    return 0;
}
