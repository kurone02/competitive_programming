#include<bits/stdc++.h>
#define task "VOI08LOCO"
#define author "Kamisama"

const int maxn=1e6+6;
const int w=1e9+7;

using namespace std;

int n,a[4000];
int f[4000];
int p;
map<int,bool> c;
int meo=1;

inline void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=true;
	}
	sort(a+1,a+n+1);
	fill(f,f+4000,1);
}

/*inline void solve(){
    for(int i=3;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[i]!=a[j]*2){
                if(c[a[i]-a[j]]>0){
                    f[i]=max(f[i],f[j]+1);
                }
            }
            else{
                if(c[a[i]-a[j]]>1){
                    f[i]=max(f[i],f[j]+1);
                    //if(p>=f[i]) f[i]=p;
                }
            }
        }
    }
    sort(f+1,f+n+1);
    cout<<f[n];
}*/

inline void solve(){
    int j=1;
    for(int k=3;k<=n;k++){
        j=1;
        for(int i=k-1;i>=1;i--){
            while(a[i]+a[j]<a[k]) j++;
            if(a[i]+a[j]>a[k]) continue;
            if(a[i]+a[j]==a[k]&&i!=j) f[k]=max(f[k],f[i]+1);
        }
    }
    sort(f+1,f+n+1);
    cout<<f[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    init();
    solve();
    return 0;
}
