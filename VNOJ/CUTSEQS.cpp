#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <deque>
#define CL(x) ((x)<<1)
#define CR(x) (CL(x)|1)
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e5+7;
const long long inf=(long long)1e18+7;

int n,a[maxn],l[4*maxn],r[4*maxn];
long long m,sum,f[maxn],it[4*maxn];
deque<int> dq;

inline void Build(const int &x, const int &low, const int &high){
    l[x]=low; r[x]=high;
    if(low==high) it[x]=inf;
    else{
        int mid=(low+high)>>1;
        Build(CL(x),low,mid);
        Build(CR(x),mid+1,high);
        it[x]=min(it[CL(x)],it[CR(x)]);
    }
}

inline void Update(const int &x, const int &pos, const long long &val){
    if(l[x]>pos || r[x]<pos) return;
    if(l[x]==r[x]) it[x]=val;
    else{
        Update(CL(x),pos,val);
        Update(CR(x),pos,val);
        it[x]=min(it[CL(x)],it[CR(x)]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    cin>>n>>m; Build(1,1,n);
    for(int i=1,j=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>m) return cout<<-1,0;
        sum+=a[i];
        while(sum>m) sum-=a[j++];
        while(dq.size() && a[dq.back()]<=a[i]){
            Update(1,dq.back(),inf);
            dq.pop_back();
        }
        while(dq.size() && dq.front()<j){
            Update(1,dq.front(),inf);
            dq.pop_front();
        }
        if(dq.empty()) Update(1,i,a[i]+f[j-1]);
        else{
            Update(1,dq.front(),a[dq.front()]+f[j-1]);
            Update(1,i,a[i]+f[dq.back()]);
        }
        dq.push_back(i);
        f[i]=it[1];
    }
    cout<<f[n];

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
