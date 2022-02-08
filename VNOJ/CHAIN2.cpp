#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define cntbit(x) __builtin_popcountll(x)
#define x first
#define y second

using namespace std;

typedef long long ll;

const int maxn=1e5+7;
const ll mod=1e9+7;
const int inf=1e9+7;
const double esp=1e-6;

struct Trie{
    int cnt;
    Trie *child[26];
}*root;
int n,res;
string s;

inline Trie* CreateNode(){
    Trie *node=new Trie;
    node->cnt=0;
    rep(i,0,26) node->child[i]=nullptr;
    return node;
}

inline void Insert(const string &str){
    Trie *node=root;
    rep(i,0,str.size()){
        int id=s[i]-'a';
        if(node->child[id]==nullptr) node->child[id]=CreateNode(),(node->child[id])->cnt=node->cnt;
        node=node->child[id];
    }
    node->cnt++;
    res=max(res,node->cnt);
}

inline void Enter(){
    cin>>n;
}

inline void Init(){
    root=CreateNode();
}

inline void Solve(){
    while(n--) cin>>s,Insert(s);
    cout<<res;
}

inline void Main(){
    Enter();
    Init();
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
