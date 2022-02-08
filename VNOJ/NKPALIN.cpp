#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=2e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n;
string a,b;
int f[maxn][maxn];
string kq;

inline void enter(){
    cin>>a; n=a.size();
    reverse(a.begin(),a.end());
    b=a; reverse(a.begin(),a.end());
}

inline void solve(){
    up(i,1,n){
        up(j,1,n){
            if(a[i-1]!=b[j-1]) f[i][j]=max(f[i-1][j],f[i][j-1]);
            else f[i][j]=f[i-1][j-1]+1;
        }
    }
    kq.resize(f[n][n]);
    int i=n,j=n,z=0;
    while(f[i][j]!=0){
        if(a[i-1]==b[j-1]){
            kq[z++]=a[i-1];
            i--;j--;
        }
        else{
            if(f[i-1][j]>=f[i][j-1]) i--;
            else j--;
        }
    }
    cout<<kq;
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    #define OnlineJudge
    #ifndef OnlineJudge
    file();
    #endif
    enter();
    solve();
    return 0;
}
