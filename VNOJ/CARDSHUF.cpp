#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;
const int maxn=1e5+7;

struct Nodes;  
typedef Nodes* PNodes;
struct Nodes{
    int val;
    int size;
    PNodes child[2],parrent;
}; PNodes nil;

class SplayTree{
public:
    PNodes root;

    inline void SetChild(PNodes x, PNodes y, const int &d){
        x->child[d]=y;
        y->parrent=x;
    }
 
    inline bool GetChild(PNodes x, PNodes y){
        return x->child[0]!=y;
    }

    inline void Update(PNodes x){
        x->size=x->child[0]->size+x->child[1]->size+1;
    }
 
    inline void UpTree(PNodes x){
        PNodes y=x->parrent;
        PNodes z=y->parrent;
        int d=GetChild(y,x);
        SetChild(y,x->child[!d],d);
        SetChild(x,y,!d);
        d=GetChild(z,y);
        SetChild(z,x,d);
        Update(y);
        Update(x);
    }
 
    inline PNodes Splay(PNodes x){
        while(true){
            PNodes y=x->parrent;
            PNodes z=y->parrent;
            if(y==nil) break;
            if(z!=nil){
                if(!GetChild(z,y) && !GetChild(y,x)) UpTree(y);
                else UpTree(x);
            }
            UpTree(x);
        }
        return root=x;
    }
    inline SplayTree(){root=nil;}

    inline PNodes Locate(int i){
        PNodes x=root;
        while(true){
            int p=x->child[0]->size+1;
            if(i==p) break;
            if(i<p) x=x->child[0];
            else x=x->child[1],i-=p;
        }
        return x;
    }

    inline void Split(const int &i, SplayTree &TL, SplayTree &TR){
        if(i==0){
            TL.root=nil;
            TR=*this;
            return;
        }
        PNodes A=Locate(i);
        Splay(A);
        PNodes B=A->child[1];
        A->child[1]=nil;
        B->parrent=nil;
        root=nil;
        TL.root=A;
        TL.Update(A);
        TR.root=B;
    }

    friend inline SplayTree Join(SplayTree TL, SplayTree TR){
        if(TL.root==nil) return TR;
        PNodes A=TL.Locate(TL.Size());
        TL.Splay(A);
        TL.SetChild(A,TR.root,1);
        TL.Update(A);
        SplayTree res=TL;
        TL.root=TR.root=nil;
        return res;
    }

    inline int Size(){
        return root->size;
    }
};

int n,x,nCards,deck[maxn],bit[maxn];
SplayTree tree;

inline PNodes Build(const int &l, const int &r){
    if(l>r) return nil;
    int mid=(l+r)>>1;
    PNodes x=new Nodes();
    x->val=mid;
    x->parrent=nil;
    tree.SetChild(x,Build(l,mid-1),0);
    tree.SetChild(x,Build(mid+1,r),1);
    tree.Update(x);
    return x;
}

inline void S(const int &i, const int &j){
    SplayTree T1,T2,T3;
    tree.Split(i-1,T1,T2); 
    T2.Split(1,T2,T3);
    tree=Join(T1,T3);
    tree.Split(j-1,T1,T3);
    tree=Join(Join(T1,T2),T3);
}

inline void FinalDeck(const PNodes &x){
    if(x==nil) return;
    FinalDeck(x->child[0]);
    deck[++nCards]=x->val;
    FinalDeck(x->child[1]);
}

inline void Update(int x,int val){
    for(;x<=n;x+=x&-x) bit[x]=max(bit[x],val);
}
 
inline int Get(int x){
    int res=0;
    for(;x;x-=x&-x) res=max(res,bit[x]);
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    cin>>n>>x;
    nil=new Nodes();
    nil->child[0]=nil->child[1]=nil->parrent=nil;
    nil->val=0; nil->size=0;
    tree.root=Build(1,n);
    while(x--){
        int i,j; cin>>i>>j;
        S(i,j);
    }
    FinalDeck(tree.root);
    for(int i=1;i<=n;i++) Update(deck[i],Get(deck[i]-1)+1);
    cout<<n-Get(n);

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
