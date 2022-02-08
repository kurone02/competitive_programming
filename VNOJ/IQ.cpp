#include <bits/stdc++.h>
#include <unordered_map>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define UP(i,a,b) for(i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define All(x) x.begin(),x.end()
#define CntBit(x) __builtin_popcount(x)
#define GetBit(x,k) ((x>>k)&1)
#define x first
#define y second
#define Kamisama

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int maxn=1e1+7;
const int maxk=6;
const ll mod=1e9+7;
const ll base=257;
const int inf=1e9+7;
const double esp=1e-7;
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

int n,m,nBalls,res;
char a[maxn][maxn];
int dx[]={1, 0,-1, 0},
    dy[]={0,-1, 0, 1};
pii grav[maxn][maxn][maxk],finishLine[maxk],inFinishLine[maxn][maxn],onTop[maxn][maxn][maxk];
pii ballPos[maxk];
struct Neko{pii ball[maxk];int gravity;};
unordered_map<int,int> d;
queue<Neko> q;

inline void Enter(){
    cin>>m>>n>>nBalls;
    up(i,1,nBalls) cin>>finishLine[i].x>>finishLine[i].y;
    int cnt=0;
    up(i,1,m) up(j,1,n){
        cin>>a[i][j];
        if(a[i][j]=='o') ballPos[++cnt]=pii(i,j);
    }
    up(i,0,m+1) a[i][0]=a[i][n+1]='#';
    up(i,0,n+1) a[0][i]=a[m+1][i]='#';
}

inline int Val(Neko x){
    int p11=11;
    int res=x.gravity;
    down(i,4,1) res+=x.ball[i].x*p11+x.ball[i].y*p11*11,p11*=11*11;
    return res;
}

inline void Init(){
    up(i,1,m) up(j,1,n){
        down(k,i,0) if(a[k][j]=='#'){
            grav[i][j][0]=pii(k+1,j);
            break;
        }
        down(k,j,0) if(a[i][k]=='#'){
            grav[i][j][3]=pii(i,k+1);
            break;
        }
        up(k,i,m+1) if(a[k][j]=='#'){
            grav[i][j][2]=pii(k-1,j);
            break;
        }
        up(k,j,n+1) if(a[i][k]=='#'){
            grav[i][j][1]=pii(i,k-1);
            break;
        }
        rep(k,0,4) onTop[i][j][k]=pii(i+dx[k],j+dy[k]);
    }
    sort(finishLine+1,finishLine+nBalls+1);
    sort(ballPos+1,ballPos+nBalls+1);
}

inline pii Fall(const int &gravity,const pii &pos){
    return grav[pos.x][pos.y][gravity];
}

inline pii StackUp(const int &gravity,const pii &pos){
    return onTop[pos.x][pos.y][gravity];
}

inline Neko RotateRight(Neko board){
    board.gravity=(board.gravity+3)%4;
    up(i,1,nBalls) ballPos[i]=Fall(board.gravity,board.ball[i]);
    sort(ballPos+1,ballPos+nBalls+1);
    up(i,1,nBalls) board.ball[i]=ballPos[i];
    up(i,1,nBalls) if(ballPos[i]==ballPos[i-1]) board.ball[i]=StackUp(board.gravity,board.ball[i-1]);
    sort(board.ball+1,board.ball+nBalls+1);
    return board;
}

inline Neko RotateLeft(Neko board){
    board.gravity=(board.gravity+1)%4;
    up(i,1,nBalls) ballPos[i]=Fall(board.gravity,board.ball[i]);
    sort(ballPos+1,ballPos+nBalls+1);
    up(i,1,nBalls) board.ball[i]=ballPos[i];
    up(i,1,nBalls) if(ballPos[i]==ballPos[i-1]) board.ball[i]=StackUp(board.gravity,board.ball[i-1]);
    sort(board.ball+1,board.ball+nBalls+1);
    return board;
}

inline bool isFinish(Neko &board){
    sort(board.ball+1,board.ball+nBalls+1);
    up(i,1,nBalls) if(board.ball[i]!=finishLine[i]) return false;
    return true;
}

inline void Solve(){
    Neko top;
    up(i,1,nBalls) top.ball[i]=ballPos[i];
    top.gravity=2;
    q.push(top);
    if(isFinish(top)){
        cout<<0;
        return;
    }
    while(q.size()){
        Neko u=q.front();
        q.pop();
        /// Left
        Neko v=RotateRight(u);
        if(isFinish(v)){
            cout<<d[Val(u)]+1;
            return;
        }
        if(d[Val(v)]==0) d[Val(v)]=d[Val(u)]+1, q.push(v);
        /// Right
        v=RotateLeft(u);
        if(isFinish(v)){
            cout<<d[Val(u)]+1;
            return;
        }
        if(d[Val(v)]==0) d[Val(v)]=d[Val(u)]+1, q.push(v);
    }
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
