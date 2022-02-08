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
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;typedef vector<vi> vvi;typedef vector<pii> vii;
typedef set<int> si;
typedef map<int, int> mii;typedef map<bool, int> mbi;typedef map<string, int> msi;
typedef vl big;
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

int n,s,k;
int a[21][21];
int kq[21];
int sum;
bool chk;

inline void enter(){
    cin>>s>>k>>n;
    up(i,1,n) up(j,1,k) cin>>a[i][j];
}

inline void backtrack(int x){
    up(i,1,n){
        //cout<<x<<'\n';
        if(chk) return;
        if(a[i][x]>=kq[x-1]&&s-sum>=a[i][x]*(k-x+1)){
            sum+=a[i][x];
            kq[x]=a[i][x];

            if(x==k&&sum==s){
                chk=true;
                return;
            }
            else if(x<k&&sum<s) backtrack(x+1);
            sum-=kq[x];
        }
    }
}

inline void solve(){
    backtrack(1);
    if(chk){
        cout<<"YES\n";
        up(i,1,k) cout<<kq[i]<<' ';
        return;
    }
    else cout<<"NO";
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
    solve();
    return 0;
}
