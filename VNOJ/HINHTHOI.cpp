#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <vector>
#include <algorithm>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=2e3+7;
const int maxp=2e2+7;
 
struct TPoints{
    double x,y;
    inline TPoints(double _x=0, double _y=0){
        x=_x; y=_y;
    }
    inline bool operator <(const TPoints &other) const{
        return x<other.x || (x==other.x && y<other.y);
    }
    inline bool operator ==(const TPoints &other) const{
        return x==other.x && y==other.y;
    }
    inline TPoints operator +(const TPoints &other) const{
        return TPoints(x+other.x,y+other.y);
    }
    inline TPoints operator -(const TPoints &other) const{
        return TPoints(x-other.x,y-other.y);
    }
    inline double operator *(const TPoints &other) const{
        return x*other.x+y*other.y;
    }
    inline TPoints operator /(const int &num) const{
        return TPoints(x/num,y/num);
    }
};
 
int n;
long long res;
TPoints points[maxn];
vector<TPoints> ma[maxp][maxp];
 
inline void Enter(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>points[i].x>>points[i].y;
}
 
inline void Init(){
    sort(points+1,points+n+1);
    n=unique(points+1,points+n+1)-points-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            TPoints mid=(points[i]+points[j]);
            ma[(int)mid.x+100][(int)mid.y+100].push_back(points[i]-mid/2);
        }
    }
}
 
inline long long Calc(vector<TPoints> v){
    long long cnt=0;
    sort(v.begin(),v.end(),[](const TPoints &A, const TPoints &B){
        return A.x*B.y>A.y*B.x;
    });
    for(int i=0,j=0,k=0;i<(int)v.size();i++){
        j=max(j,i+1); k=max(k,i+1);
        while(j<(int)v.size() && v[i]*v[j]>0) j++;
        while(k<(int)v.size() && v[i]*v[k]>=0) k++;
        cnt+=k-j;
    }
    return cnt;
}
 
inline void Solve(){
    for(int x=0;x<=200;x++){
        for(int y=0;y<=200;y++){
            res+=Calc(ma[x][y]);
        }
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    Enter();
    Init();
    Solve();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
