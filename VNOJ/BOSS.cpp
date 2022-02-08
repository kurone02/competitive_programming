#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
#define Kami
#define taskname "TEST"
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e4+7;
const int inf=1e9+7;

struct TStaff{
    int id,salary,height;
    inline TStaff(int _id=0, int _salary=0, int _height=0){
        id=_id; salary=_salary; height=_height;
    }
    inline bool operator <(const TStaff &other) const{
        return height>other.height || (height==other.height && salary>other.salary);
    }
};

int n,q,boss[maxn],nSoldiers[maxn];
int bit[maxn],staffSalary[maxn],staffId[maxn];
TStaff a[maxn];
unordered_map<int,int> mpSalary,mpId,salaryId;

inline void Enter(){
    cin>>n>>q; salaryId.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i].id>>a[i].salary>>a[i].height;
        staffSalary[i]=a[i].salary;
        staffId[i]=a[i].id;
        salaryId[a[i].salary]=a[i].id;
    }
}

inline void Update(int x, const int &val){
    for(;x;x-=x&-x) bit[x]=min(bit[x],val);
}

inline int Get(int x){
    int res=inf;
    for(;x<=n;x+=x&-x) res=min(res,bit[x]);
    return res;
}

inline void Init(){
    sort(a+1,a+n+1); 
    sort(staffSalary+1,staffSalary+n+1);
    sort(staffId+1,staffId+n+1);
    mpSalary.clear(); mpId.clear();
    fill(bit,bit+n+1,inf);
    fill(nSoldiers,nSoldiers+n+1,0);
    fill(boss,boss+n+1,0);
    for(int i=1;i<=n;i++) {
        mpSalary[staffSalary[i]]=i;
        mpId[staffId[i]]=i;
    }
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        int p=Get(mpSalary[a[i].salary]+1);
        boss[mpId[a[i].id]]=(p==inf)? 0 : salaryId[p];
        Update(mpSalary[a[i].salary],a[i].salary);
    } 
    for(int i=n;i>=1;i--){
        int x=mpId[a[i].id];
        nSoldiers[mpId[boss[x]]]+=nSoldiers[x]+1;
    }
    for(int x;q--;) cin>>x, cout<<boss[mpId[x]]<<' '<<nSoldiers[mpId[x]]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    int nTest; cin>>nTest;
    while(nTest--){
        Enter();
        Init();
        Solve();
    }

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
