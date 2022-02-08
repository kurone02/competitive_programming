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
const int maxn=1e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int t;
ll countA,countB,maxA,maxB;

inline void enter(){
    cin>>t;
}

inline void solve(){
    cin>>countA>>countB>>maxA>>maxB;
    if(countA==0||maxA==0) cout<<min(countB,maxB);
    else if(countB==0||maxB==0) cout<<min(countA,maxA);
    else{
        if(countA==countB) cout<<countA+countB;
        else if(countA<countB) cout<<2*countA+1+min(countB-countA-1,(maxB-1)*(countA+1));
        else cout<<2*countB+1+min(countA-countB-1,(maxA-1)*(countB+1));
    }
    cout<<'\n';
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
    while(t--) solve();
    return 0;
}
