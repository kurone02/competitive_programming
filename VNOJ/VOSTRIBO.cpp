#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define self (*this)
#define pb push_back
#define cntbit(x) __builtin_popcountll(x)
#define x first
#define y second

using namespace std;

typedef unsigned long long ll;

const int maxn=1e6+7;
const ll mod=1e15+7;
const int inf=1e9+7;
const double esp=1e-6;

inline ll Mul(ll x,ll y){
    if(y==0) return 0;
    if(y==1) return x;
    ll res=Mul(x,y>>1);
    res=(res+res)%mod;
    if(y&1) return (res+x)%mod;
    return res;
}

int nTest,n;
struct Matrix{
    ll x[4][4];
    Matrix(){};
    Matrix(ll tmp[4][4]){
        rep(i,0,4) rep(j,0,4) x[i][j]=tmp[i][j];
    }
    friend inline Matrix operator *(const Matrix &A, const Matrix &B){
        Matrix C;
        ll tmp[4][4]={};
        C=Matrix(tmp);
        rep(i,0,4) rep(k,0,4) rep(j,0,4)
            C.x[i][j]=(C.x[i][j]+Mul(A.x[i][k],B.x[k][j]))%mod;
        return C;
    }
    friend inline Matrix Power(const Matrix &A, const int &k){
        if(k==1) return A;
        Matrix res=Power(A,k>>1);
        res=res*res;
        if(k&1) return res*A;
        return res;
    }
}A,B;

inline void Enter(){
    cin>>n;
}

inline void Solve(){
    if(n==1) cout<<"1\n";
    else if(n==2) cout<<"3\n";
    else if(n==3) cout<<"6\n";
    else{
        ll tmpA[4][4]={1,1,1,1,
                       0,1,1,1,
                       0,1,0,0,
                       0,0,1,0},
           tmpB[4][4]={6,0,0,0,
                       3,0,0,0,
                       2,0,0,0,
                       1,0,0,0};
        A=Matrix(tmpA);
        B=Matrix(tmpB);
        A=Power(A,n-3);
        A=A*B;
        cout<<A.x[0][0]<<'\n';
    }
}

inline void Main(){
    cin>>nTest;
    while(nTest--){
        Enter();
        Solve();
    }
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\nIn milliseconds: "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n' << "In seconds: "<<fixed<<setprecision(3)
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
    Execution_Time_Calculator(0);

    return 0;
}
