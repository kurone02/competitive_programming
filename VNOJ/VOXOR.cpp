#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define self (*this)
#define pb push_back
#define CL(x) x<<1
#define CR(x) x<<1|1
#define x first
#define y second
#define Kamisama
 
using namespace std;
 
typedef long long ll;
 
const int maxn=5e4+7;
const int maxk=5e2+7;
const int inf=1e9+7;
const double esp=1e-6;
 
int n,q;
bool flipped[32];
struct Trie{
    int cnt;
    Trie *child[2];
}*root;
 
inline bool GetBit(const int &x, const int &k){
    return (x>>k)&1;
}
 
inline Trie* NewNode(){
    Trie *node=new Trie;
    node->cnt=0;
    rep(i,0,2) node->child[i]=NULL;
    return node;
}
 
inline void Insert(const int &x){
    Trie *node=root;
    repd(i,31,0){
        int id=GetBit(x,i);
        if(node->child[id]==NULL) node->child[id]=NewNode();
        node=node->child[id];
        node->cnt++;
    }
}
 
inline void Update(const int &x){
    repd(i,31,0) if(GetBit(x,i)) flipped[i]^=1;
}
 
inline int Get(int k){
    Trie *node=root;
    int res=0;
    repd(i,31,0){
        if(!flipped[i]){
            if(node->child[1]!=NULL){
                Trie *tmp=node->child[1];
//                cout<<k<<' '<<node->cnt<<'\n';
                if(k<=tmp->cnt){
                    res+=(1<<i);
                    node=tmp;
                } else{
                    node=node->child[0];
                    k-=tmp->cnt;
                }
            } else{
//                cout<<k<<' '<<node->cnt<<'\n';
                node=node->child[0];
            }
        } else{
            if(node->child[0]!=NULL){
                Trie *tmp=node->child[0];
                if(k<=tmp->cnt){
                    res+=(1<<i);
                    node=tmp;
                } else{
                    node=node->child[1];
                    k-=tmp->cnt;
                }
            } else{
                node=node->child[1];
//                k-=node->cnt;
            }
        }
    }
    return res;
}
 
inline void Enter(){
    cin>>n>>q;
    root=NewNode();
    up(i,1,n){
        int x;
        cin>>x;
        Insert(x);
    }
}
 
inline void Solve(){
    while(q--){
        string type;
        int k;
        cin>>type>>k;
        if(type=="FIND") cout<<Get(k)<<'\n';
        else Update(k);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    #undef Kamisama
    #ifdef Kamisama
    #define task "TEST"
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    #endif // Kamisama
 
    Enter();
    Solve();
 
    return 0;
}