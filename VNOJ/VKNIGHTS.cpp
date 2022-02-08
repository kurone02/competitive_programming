#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bit1(x) __builtin_popcount(x)

using namespace std;

typedef long long ll;

const int maxn=1e2+7;
const int maxS=(1<<6);

int n;
bool a[4][maxn];
int z[maxn],f[maxn][maxS];
ll g[maxn][maxS];

inline void Enter(){
    cin>>n;
    up(i,1,n){
        int x;
        cin>>x;
        if(x) a[x][i]=true;
    }
}

inline bool getbit(int x,int k){
    return (x>>6-k)&1;
}

inline void Prepare(){
    up(i,1,3) z[1]=(z[1]<<1)+a[i][1];
    up(i,2,n){
        up(j,1,3) z[i]=(z[i]<<1)+a[j][i-1];
        up(j,1,3) z[i]=(z[i]<<1)+a[j][i];
    }

    f[0][0]=0, g[0][0]=1;
    rep(state,0,8) if(!(state&z[1])) f[1][state]=bit1(state),g[1][state]=1;
}

inline bool CheckKnight(int state,int pre){
    if(getbit(state,1)){
        if(getbit(state,6)) return false;
        if(getbit(pre,6)) return false;
        if(getbit(pre,2)) return false;
    }
    if(getbit(state,2)){
        if(getbit(pre,1)) return false;
        if(getbit(pre,3)) return false;
    }
    if(getbit(state,3)){
        if(getbit(state,4)) return false;
        if(getbit(pre,4)) return false;
        if(getbit(pre,2)) return false;
    }
    if(getbit(state,4)){
        if(getbit(state,3)) return false;
        if(getbit(pre,5)) return false;
    }
    if(getbit(state,5)){
        if(getbit(pre,4)) return false;
        if(getbit(pre,6)) return false;
    }
    if(getbit(state,6)){
        if(getbit(state,1)) return false;
        if(getbit(pre,5)) return false;
    }
    return true;
}

inline void DPBitmask(){
    up(i,2,n){
        rep(state,0,maxS){
            if(state&z[i]) continue;
            rep(pre,0,maxS){
                if(pre&z[i-2] || !g[i-2][pre]) continue;
                if(i>3 || (i==2 && pre==0) || (i==3 && pre<8)){
                    if(!CheckKnight(state,pre)) continue;
                    if(f[i][state]<f[i-2][pre]+bit1(state)){
                        f[i][state]=f[i-2][pre]+bit1(state);
                        g[i][state]=g[i-2][pre];
                    } else if(f[i][state]==f[i-2][pre]+bit1(state)) g[i][state]+=g[i-2][pre];
                }
            }
        }
    }
}

inline void Solve(){
    int kq=0; ll cnt=0;
    rep(state,0,maxS) kq=max(kq,f[n][state]);
    rep(state,0,maxS){
        if(f[n][state]==kq) cnt+=g[n][state];
        //cerr<<"f["<<n<<"]["<<state<<"]= "<<f[n][state]<<", "<<"g["<<n<<"]["<<state<<"]= "<<g[n][state]<<'\n';
    }
    cout<<kq<<' '<<cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Enter();
    Prepare();
    DPBitmask();
    Solve();

    return 0;
}
