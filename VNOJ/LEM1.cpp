#include<bits/stdc++.h>
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=1e5+7;
const double esp=1e-5;
const double pi=atan(1)*4;

int n;
double r[maxn];
double lim;

inline double sqr(double x){
    return x*x;
}

inline bool f(double x){
    double sumang=0;
    up(i,1,n){
        double a=x+r[i],
               b=x+r[i+1],
               c=r[i]+r[i+1];
        sumang+=acos((sqr(a)+sqr(b)-sqr(c))/(2*a*b));
    }
    return sumang>=2*pi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);

    cin>>n;
    up(i,1,n) cin>>r[i],lim+=r[i];
    r[n+1]=r[1];

    double l=0,h=lim;
    while(l+esp<h){
        double mid=(l+h)/2;
        if(f(mid)) l=mid;
        else h=mid;
    }
    cout<<fixed<<setprecision(3)<<h;

    return 0;
}


















