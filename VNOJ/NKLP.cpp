#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e5+7;
const ll mod=1e9+7;
const int inf=1e9+7;

int n,a[maxn],pos[maxn],last[maxn],res;
ll sum[maxn];

inline void Enter(){
    cin>>n;
    last[n+1]=n+1;
    up(i,1,n){
        cin>>a[i];
        last[i]=max(last[i-1],pos[a[i]]+1);
        pos[a[i]]=i;
        sum[i]=sum[i-1]+a[i];
    }
}

inline void Maximize(int &Target,const int Value){
    Target=(Target<Value)? Value : Target;
}

inline void UpdateRes(const int &l,const int &r,const int &len){
    if(len<res) return;
    if(l>=last[r] && sum[r]-sum[l-1]==1ll*len*(len+1)/2) res=len;
}

inline void Solve(){
    up(i,1,n) if(a[i]==1){
        UpdateRes(i,i,1);
        for(int j=i-1,len=1;j>=last[i];j--){
            Maximize(len,a[j]);
            UpdateRes(j,j+len-1,len);
        }
        for(int j=i+1,len=1;last[j]<=i;j++){
            Maximize(len,a[j]);
            UpdateRes(j-len+1,j,len);
        }
    }
    cout<<res;
}

inline void Main(){
    Enter();
    Solve();
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
}

inline void Input_Output_From_File(const bool &Allow){
    if(not Allow) return;
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    Input_Output_From_File(0);
    Execution_Time_Calculator(1);

    return 0;
}
