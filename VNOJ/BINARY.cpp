#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e2+7;

int n,k;
int f[32][32][2][2];

inline int dp(int pos,int cnt,int chk,int pre){
    if(pos<0) return cerr<<cnt<<'\n',(cnt==k);
    int res=f[pos][cnt][chk][pre];
    if(res!=-1) return res;

    int cur=(n>>pos)&1;

    res=0;

    up(d,0,1) if(d<=cur || pre){
        res+=dp(pos-1,cnt+(d==0 && chk),chk || d>0,pre || d<cur);
    }
    return f[pos][cnt][chk][pre]=res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    //freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);

    while(cin>>n>>k){
        memset(f,-1,sizeof(f));
        if(k==1) cout<<dp(30,0,0,0)+1<<'\n';
        else if(k==0) cout<<dp(30,0,0,0)-1<<'\n';
        else cout<<dp(30,0,0,0)<<'\n';
        cerr<<'\n';
    }

    return 0;
}
