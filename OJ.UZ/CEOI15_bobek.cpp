#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#include <algorithm>
#define GetBit(x,k) ((x)>>(k)&1)
#define taskname "TEST"
using namespace std;
 
int n;
long long m,a[41],res;
vector<long long> sumL,sumR;
 
inline void Attempt(const int &low, const int &high, vector<long long> &v){
    for(int state=0;state<1<<(high-low+1);state++){
        long long sum=0;
        for(int i=low;i<=high;i++) sum+=a[i]*(GetBit(state,i-low));
        v.push_back(sum);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    Attempt(1,n/2,sumL); Attempt(n/2+1,n,sumR);
    sort(sumR.begin(),sumR.end());
    for(auto x: sumL) res+=upper_bound(sumR.begin(),sumR.end(),m-x)-sumR.begin();
    cout<<res;
    return 0;
}