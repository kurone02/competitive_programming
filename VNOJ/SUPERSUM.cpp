#include <iostream>
using namespace std;
const int mod=1e9+7;

inline int Pow(const int &x, const int &y){
    if(y==0) return 1;
    int res=Pow(x,y>>1);
    res=1ll*res*res%mod;
    if(y&1) return 1ll*res*x%mod;
    return res;
}

inline int C(const int &n, const int &k){
    int res=1,fact=1;
    for(int i=1;i<=k;i++)
        res=1ll*res*(n-k+i)%mod,
        fact=1ll*fact*i%mod;
    return 1ll*res*Pow(fact,mod-2)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(string s;cin>>s;){
        if(s=="[END]") break;
        int n,k; cin>>k>>n;
        cout<<C(n+k,k+1)<<'\n';
    }
    return 0;
}