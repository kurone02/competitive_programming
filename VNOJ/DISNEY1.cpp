#include <iostream>
using namespace std;
int a[201][201],f[201][201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,res; cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    fill(&f[0][0],&f[0][0]+201*201,res=1000000007);
    f[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int nxt=max(i,j)+1;
            if(nxt>n) res=min(res,f[i][j]+a[i][1]+a[j][1]);
            else{
                f[i][nxt]=min(f[i][nxt],f[i][j]+a[j][nxt]);
                f[nxt][j]=min(f[nxt][j],f[i][j]+a[i][nxt]);
                f[nxt][nxt]=min(f[nxt][nxt],f[i][j]+a[i][nxt]+a[j][nxt]);
            }
        }
    }
    cout<<res;
    return 0;
}