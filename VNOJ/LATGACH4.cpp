#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define f first
#define s second
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<string, int> mii;
/*----------------------------------------------*/
const int maxn=1e6+10;
const int maxt=2e5+10;
const ll inf=1e16;
const int mod=111539786;
const double pi=4*atan(1);
const bool OnlineJudge=1;
const int mxs=2;
/*----------------------------------------------*/

struct matrix{
    ll x[mxs][mxs];
    matrix(){};
    matrix(ll a[mxs][mxs]){
        up(i,0,1) up(j,0,1) x[i][j]=a[i][j];
    }
    friend matrix operator *(const matrix &a,const matrix &b){
        matrix c;
        up(i,0,1)
        up(j,0,1){
            c.x[i][j]=0;
            up(k,0,1) c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
        }
        return c;
    }
    friend matrix operator ^(const matrix &a,const int &k){
        if(k==1) return a;
        matrix c=a^(k/2);
        if(k%2) return c*c*a;
        else return c*c;
    }
};

int n,t;
matrix kq,tmp;

inline void init(){
    scanf("%d",&t);
}

inline void prepare(){
    ll T[2][2]={1,1,1,0};
    tmp=matrix(T);
}

inline void solve(){
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
        return;
    }
    kq=tmp^(n-1);
    printf("%d\n",(kq.x[0][0]+kq.x[1][0])%mod);
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    if(!OnlineJudge) file();
    init();
    prepare();
    while(t--)
    solve();
    return 0;
}
