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
const int maxn=1e5+10;
const int maxt=2e5+10;
const ll inf=1e16;
const int mod=111539786;
const double pi=4*atan(1);
const bool OnlineJudge=1;
const int mxs=2;
/*----------------------------------------------*/

int n,m;
int r[maxn];
char s[maxn];
int a[maxn];
int c[102];
int f[maxn];

inline void init(){
    scanf("%d%d",&n,&m);
    up(i,1,n) scanf("%d",r+i);
    scanf("\n");
    up(i,1,m) scanf("%c",s+i);
    s[m+1]='0';
    fill(c,c+maxn,-1);
    up(i,1,n){
        if(c[r[i]]==-1){
            int t1,t; t1=t=0;
            while(t1<m+1){
                int tmp=min(r[i],m+1-t1);
                while(tmp>0&&s[t1+tmp]!='0') tmp--;
                t1+=tmp;
                t++;
            }
            a[i]=c[r[i]]=t;
        }
        else a[i]=c[r[i]];
    }
}

inline void prepare(){
    sort(a+1,a+n+1);
    f[1]=a[1],f[2]=a[2];
    up(i,3,n) f[i]=min(f[i-1]+a[i]+a[1],f[i-2]+a[i]+a[1]+2*a[2]);
}

inline void solve(){
    cout<<f[n];
}

inline void file(){
    #define task "BRIDGE12"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    if(!OnlineJudge) file();
    init();
    prepare();
    //while(t--)
    solve();
    return 0;
}
