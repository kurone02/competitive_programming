#include<bits/stdc++.h>
#define task "TEST"

const long long maxn=1e6+5;
const long long w=1e9+7;
const long double pi=3.14159265;
const int inf=1e9;

using namespace std;

int n;
long long a[10][10005];
long long f[300][10005],s[300][10005];
long long kq=LLONG_MIN;
long long neko=INT_MIN;

inline void init(){
    cin>>n;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=n;j++) f[i][j]=INT_MIN;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j],neko=max(neko,a[i][j]);
}

inline bool checkbit(int x,int i){
    return  (x>>i)&1;
}

inline bool checksquare(int x){
    return (x&(x>>1))==0;
}

inline bool checkcolumn(int x,int y){
    return (x&y)==0;
}

inline void prepare(){
    for(int j=1;j<=n;j++)
        for(int bit=0;bit<(1<<8);bit++){
            if(checksquare(bit))
                for(int i=1;i<=8;i++)
                    if(checkbit(bit,i-1)) s[bit][j]+=a[i][j];//cout<<s[bit][j]<<' ';
            //cout<<'\n';
        }

    for(int bit=0;bit<(1<<8);bit++)
        if(checksquare(bit))
            for(int i=1;i<=8;i++){
                f[bit][1]=max(f[bit][1],s[bit][1]);
            }

    for(int i=2;i<=n;i++){
        for(int bit=0;bit<(1<<8);bit++){
            //cout<<i<<' ';
            if(!checksquare(bit)){continue;}
            f[bit][i]=LLONG_MIN;
            for(int pre=0;pre<(1<<8);pre++){
                if(pre==bit) continue;
                if(!checksquare(pre)) continue;
                if(!checkcolumn(bit,pre)) continue;
                f[bit][i]=max(f[bit][i],f[pre][i-1]+s[bit][i]);
                //cout<<checkcolumn(bit,pre)<<' ';
                kq=max(kq,f[bit][i]);
            }
            //cout<<'\n';
        }
    }
}

inline void solve(){
    if(neko<0){
        cout<<neko;
        return;
    }
    cout<<kq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    init();
    prepare();
    //while(t--)
    solve();
    return 0;
}
