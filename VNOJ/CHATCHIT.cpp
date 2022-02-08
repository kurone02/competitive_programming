#include<bits/stdc++.h>
#define up(i,a,b) for(int i=int(a);i<=int(b);i++)
#define down(i,a,b) for(int i=int(a);i>=int(b);i--)
#define X first
#define Y second
#define CL(x) (x<<1)
#define CR(x) (x<<1)+1
#define pb push_back
/*----------------------------------------------*/
using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> pii;typedef pair<ll, int> pli;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<ll> vl;typedef vector<pll> vll;
typedef vector<vi> vvi;typedef vector<pii> vii;
/*----------------------------------------------*/
const int maxn=1e3+7;
const int maxm=6e6+7;
const ll linf=1e16; const int inf=2e9; const int mod=111539786;
const double pi=4*atan(1);
const int as=2e2;
/*----------------------------------------------*/
inline int getbit(int x,int k){return x&(1<<k);}
inline int pow2(int x){return (1<<x);}
inline int offbit(int x,int k){return x&~(1<<k);}
/*----------------------------------------------*/

int n;
string s[300];
string a[]={"k","ko","ng","n","dc","hok","ntn","kq","j","w","f","dz","z"};
string b[]={"khong","khong","nguoi","nhieu","duoc","khong","nhu the nao",
            "ket qua","gi","qu","ph","d","d"};
bool c[300];

inline void enter(){
    string tmp;
    while(cin>>tmp) s[++n]=tmp;
}

inline void solve(){
    up(i,0,7){
        up(j,1,n){
            if(s[j]==a[i]) s[j]=b[i],c[j]=true;
            //cerr<<a[i]<<' '<<s[j]<<'\n';
        }
    }
    up(i,8,12){
        up(j,1,n)if(!c[j]){
            int tmp=s[j].find(a[i]);
            if(tmp!=-1){
                s[j].erase(tmp,tmp+a[i].size());
                s[j].insert(tmp,b[i]);
            }
            //cerr<<tmp<<' '<<s[j]<<' '<<a[i]<<'\n';
        }
    }
    up(i,1,n) cout<<s[i]<<' ';
}

inline void file(){
    #define task "TEST"
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
}

int main(){
    #define OnlineJudge
    #ifndef OnlineJudge
    file();
    #endif
    enter();
    solve();
    return 0;
}
