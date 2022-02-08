#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
#define bit1(x) __builtin_popcount(x)
#define self (*this)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

template<typename T> inline void _read(T &x){
    char ch; x=0; bool neg=false;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') neg=true;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';
    if(neg) x=-x;
}
#define read(a) _read(a)
#define Read(a,b) _read(a),_read(b)
#define READ(a,b,c) _read(a),_read(b),_read(c)

const int maxn=1e5+7;
const int Nblocks=400;
const int maxa=1e8+7;
const ll mod=9901;
const int inf=1e9+7;
const ll linf=1e16+9;
const ll Radix=1e9;
const int Length=9;
const int MaxDigit=2e4+1;
const int nDigits=MaxDigit/Length+1;

///Bit manipulation
inline int SetBit(int x,int k){return x|1<<k;};
inline int OffBit(int x,int k){return x&~(1<<k);}
inline int GetBit(int x,int k){return (x>>k)&1;}
///End of Bit manipulation
int Start,End,d[(1<<16)+1];
bool c[(1<<16)+1];
deque<int> q;

inline void Enter(){
    char x;
    rep(i,0,16){
        cin>>x;
        if(x=='1') Start=SetBit(Start,i);
    }
    rep(i,0,16){
        cin>>x;
        if(x=='1') End=SetBit(End,i);
    }
}

inline void GoUp(int u,int pos){
    int v=OffBit(u,pos);
    v=SetBit(v,pos-4);
    if(c[v]) return;
    q.pb(v);
    c[v]=true;
    d[v]=d[u]+1;
}

inline void GoDown(int u,int pos){
    int v=OffBit(u,pos);
    v=SetBit(v,pos+4);
    if(c[v]) return;
    q.pb(v);
    c[v]=true;
    d[v]=d[u]+1;
}

inline void GoLeft(int u,int pos){
    int v=OffBit(u,pos);
    v=SetBit(v,pos-1);
    if(c[v]) return;
    q.pb(v);
    c[v]=true;
    d[v]=d[u]+1;
}

inline void GoRight(int u,int pos){
    int v=OffBit(u,pos);
    v=SetBit(v,pos+1);
    if(c[v]) return;
    q.pb(v);
    c[v]=true;
    d[v]=d[u]+1;
}

inline void Bfs(){
    q.pb(Start); c[Start]=true; d[Start]=0;
    while(q.size()){
        int u=q.front();
        q.pop_front();
        if(u==End){
            cout<<d[End];
            return;
        }
        rep(i,0,16){
            if(!GetBit(u,i)) continue;
            if(i>3 && !GetBit(u,i-4)) GoUp(u,i);
            if(i<12 && !GetBit(u,i+4)) GoDown(u,i);
            if(i%4!=3 && !GetBit(u,i+1)) GoRight(u,i);
            if(i%4 && !GetBit(u,i-1)) GoLeft(u,i);
        }
    }
}

inline void Solve(){
    #define Kamisama
    Bfs();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #ifndef Kamisama
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    #endif // Kamisama

    Enter();
    Solve();

    return 0;
}
