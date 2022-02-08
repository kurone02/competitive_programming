#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=5e4+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n,t;
int a[maxn];
char q;
int lg[maxn];
int fx[30][maxn],fy[30][maxn];

inline void enter(){
    cin>>n>>t;
    up(i,1,n) cin>>a[i];
}

inline void prepare(){
    lg[1]=0;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;//cout<<lg[i]<<' ';
    for(int i=1;i<=n;i++) fy[0][i]=a[i];
    for(int k=1;k<=lg[n];k++){
        for(int i=1;i<=n;i++){
            int j=i+(1<<(k-1));
            if(j>n) fy[k][i]=fy[k-1][i];
            else{
                fy[k][i]=max(fy[k-1][i],fy[k-1][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) fx[0][i]=a[i];
    for(int k=1;k<=lg[n];k++){
        for(int i=1;i<=n;i++){
            int j=i+(1<<(k-1));
            if(j>n) fx[k][i]=fx[k-1][i];
            else{
                fx[k][i]=min(fx[k-1][i],fx[k-1][j]);
            }
        }
    }
}

inline void solve(){
    int i,j;
    cin>>i>>j;
    int tmp=lg[j-i+1];
    int kq1=fy[tmp][i],
        kq2=fy[tmp][j-(1<<tmp)+1];
    int kq3=fx[tmp][i],
        kq4=fx[tmp][j-(1<<tmp)+1];
    cout<<max(kq1,kq2)-min(kq3,kq4)<<'\n';
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    //#define OfflineJudge
    #ifdef OfflineJudge
    file();
    #endif
    enter();
    prepare();
    while(t--) solve();
    return 0;
}
