#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
const int maxn=1e4+7,inf=1e9+7;
int n,l,a[maxn],f[maxn],s[maxn];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL),std::cout.tie(NULL);
    std::cin>>n>>l; up(i,1,n) std::cin>>a[i],s[i]=s[i-1]+a[i];
    std::fill(f+1,f+n+1,inf);
    up(i,1,n) down(j,i,1)
        if(s[i]-s[j-1]<=l) f[i]=std::min(f[i],std::max(f[j-1],l-s[i]+s[j-1]));
        else break;
    std::cout<<f[n];
    return 0;
}
