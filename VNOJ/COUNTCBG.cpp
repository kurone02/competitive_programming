#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e2+7;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    //freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);

    while(cin>>n){
        int kq=0;
        for(int x=2;x<=(int)sqrt(2*n);x++) if((2*n)%x==0){
            int y=(2*n)/x;
            kq+=(((x+y-1)&1)==0) && (((y-x-1)&1)==0);
            if((((x+y-1)&1)==0) && (((y-x-1)&1)==0)) cerr<<n<<": "<<x<<' '<<y<<'\n';
        }
        cout<<kq<<'\n';
    }

    return 0;
}
