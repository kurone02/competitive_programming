#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)

using namespace std;

typedef long long ll;

const int maxn=1e3+7;
const int Mrow=2,Mcol=2;

ll a,b,m,k;

inline ll mul(ll x,ll y){
    if(y==0) return 0;
    if(y==1) return x;
    ll Res=mul(x,y/2);
    Res=(Res+Res)%m;
    if(y&1) return (Res+x)%m;
    return Res;
}

struct Matrix{
    ll x[Mrow][Mcol];
    Matrix(){};
    Matrix(ll ma[Mrow][Mcol]){
        rep(i,0,Mrow) rep(j,0,Mcol) x[i][j]=ma[i][j]%m;
    }
    friend inline Matrix operator *(Matrix A,Matrix B){
        Matrix C;
        rep(i,0,Mrow) rep(j,0,Mcol){
            C.x[i][j]=0;
            rep(k,0,Mcol) C.x[i][j]=(C.x[i][j]+mul(A.x[k][j],B.x[i][k]))%m;
        }
        return C;
    }
    friend inline Matrix operator ^(const Matrix &A,const ll &p){
        if(p==1) return A;
        Matrix Res=A^(p/2);
        if(p&1) return Res*Res*A;
        return Res*Res;
    }
}A,B;

inline ll Solve(){
    cin>>a>>b>>m>>k;
    ll tmpa[Mrow][Mcol]={a,0,
                         1,1},
       tmpb[Mrow][Mcol]={b,b,
                         0,0};
    if(k==1) return b%m;
    A=Matrix(tmpa),
    B=Matrix(tmpb);
    A=A^(k-1);
    return (A*B).x[0][0]%m;
}

inline void Main(){
    int nTest;
    cin>>nTest;
    while(nTest--) cout<<Solve()<<'\n',cerr<<'\n';
}

inline void Execution_Time_Calculator(const bool &Allow){
    auto start = chrono::steady_clock::now();
    Main();
    if(not Allow) return;
    auto end=chrono::steady_clock::now();
    cerr<<"\n\n\nIn milliseconds : "
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
    Execution_Time_Calculator(0);

    return 0;
}
