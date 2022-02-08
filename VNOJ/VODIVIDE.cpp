#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define All(x) x.begin(),x.end()
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=5e3+7;
const int maxm=5e4+7;
const int base=237;
const ll mod=1e9+7;
const int inf=1e9+7;
const ll linf=1e16+7;
const double esp=1e-6;
const double pi=acos(-1);

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

template<typename T> inline void Write(T x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

int n;
struct Neko{int x,y,id;}coin[maxn];
int f[maxn][maxn];

inline void Enter(){
    cin>>n;
    up(i,1,n) cin>>coin[i].x;
    up(i,1,n) cin>>coin[i].y;
    up(i,1,n) coin[i].id=i;
}

inline void Init(){
    sort(coin+1,coin+n+1,[](const Neko &A, const Neko &B){
         return A.x>B.x || (A.x==B.x && A.y<B.y);
    });
    up(i,1,n) up(j,1,i/2) f[i][j]=max(f[i-1][j],f[i-1][j-1]+coin[i].y);
}

inline void Trace(){
    stack<int> st;
    bitset<maxn> chk;
    int i=n,j=n/2;
    while(i>0 && j>0){
        if(f[i][j]==f[i-1][j-1]+coin[i].y) st.push(i),j--,chk.set(i);
        i--;
    }
    while(st.size()){
        cerr<<st.top()<<'\n';
        repd(i,st.top(),1) if(!chk.test(i)){
            cout<<coin[st.top()].id<<' '<<coin[i].id<<'\n';
            chk.set(i);
            break;
        }
        st.pop();
    }
}

inline void Solve(){
    cout<<f[n][n/2]<<'\n';
    Trace();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
//

    Enter();
    Init();
    Solve();

    return 0;
}
