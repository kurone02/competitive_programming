#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
 
using namespace std;
 
const int maxn=3e5+7;
 
int n,c,q;
int a[maxn];
int bit[maxn][21][2];
vector<int> d[maxn];
 
inline int getbit(int x,int k){
    return (x>>k)&1;
}
 
inline int log2(int x){
    int res=0;
    for(;x;x/=2) res++;
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    cin>>n>>c; c=log2(c);
    up(i,1,n){
        cin>>a[i]; d[a[i]].push_back(i);
        up(j,0,c) bit[i][j][getbit(a[i],j)]=bit[i-1][j][getbit(a[i],j)]+1,
                    bit[i][j][!getbit(a[i],j)]=bit[i-1][j][!getbit(a[i],j)];
    }
    
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int num=0;
        up(i,0,c){
            int bit1=bit[r][i][1]-bit[l-1][i][1];
            int bit0=bit[r][i][0]-bit[l-1][i][0];
            if(bit1>bit0) num+=1<<i;
        }
        int lo=0,hi=d[num].size()-1;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(d[num][mid]>=l) hi=mid-1;
            else lo=mid+1;
        }
 
        int low=lo;
 
        lo=0,hi=d[num].size()-1;
 
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(d[num][mid]<=r) lo=mid+1;
            else hi=mid-1;
        }
 
        int high=hi;
        int res=high-low+1;
        if(res>(r-l+1)/2) cout<<"yes "<<num<<'\n';
        else cout<<"no\n";
    }
 
    return 0;
} 