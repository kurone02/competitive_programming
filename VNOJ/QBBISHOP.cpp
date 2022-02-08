#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define repd(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii; typedef vector<pli> vli;
/*----------------------------------------------*/
const int maxn=1e3+7;
const int maxm=1e6+6;
const ll linf=1e16; const int inf=2e9;
const ll mod=20122007;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return (x>>k)&1;}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

struct Neko{
    int x,y;
    int d;
};
int m,n,P,Q,s,t;
bool a[maxn][maxn];
bool c[maxn][maxn];

inline void enter(){
    cin>>n>>m>>P>>Q>>s>>t;
    up(i,1,m){
        int x,y;
        cin>>x>>y;
        a[x][y]=true;
    }
}

inline int bfs(int x,int y){
    queue<Neko> q;
    q.push({x,y,0});
    c[x][y]=true;
    while(q.size()){
        Neko u=q.front();
        q.pop();
        int x=u.x,y=u.y;
        for(int k=1;x+k<=n&&y+k<=n;k++)if(!a[x+k][y+k]){
            int i=x+k,j=y+k;
            if(!c[i][j]){
                q.push({i,j,u.d+1});
                c[i][j]=true;
                if(i==s&&j==t) return u.d+1;
            }
        } else break;

        for(int k=1;x-k>=1&&y-k>=1;k++)if(!a[x-k][y-k]){
            int i=x-k,j=y-k;
            if(!c[i][j]){
                q.push({i,j,u.d+1});
                c[i][j]=true;
                if(i==s&&j==t) return u.d+1;
            }
        } else break;

        for(int k=1;x-k>=1&&y+k<=n;k++)if(!a[x-k][y+k]){
            int i=x-k,j=y+k;
            if(!c[i][j]){
                q.push({i,j,u.d+1});
                c[i][j]=true;
                if(i==s&&j==t) return u.d+1;
            }
        } else break;

        for(int k=1;x+k<=n&&y-k>=1;k++)if(!a[x+k][y-k]){
            int i=x+k,j=y-k;
            if(!c[i][j]){
                q.push({i,j,u.d+1});
                c[i][j]=true;
                if(i==s&&j==t) return u.d+1;
            }
        } else break;
    }
    return -1;
}

inline void solve(){
    cout<<bfs(P,Q);
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
