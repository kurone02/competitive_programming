#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define Kami
#define taskname "TEST"
using namespace std;

struct Nodes;  
typedef Nodes* PNodes;
struct Nodes{
    int val;
    int size;
    PNodes child[2],parrent;
}; PNodes nil;

template<typename T> class SplayTree{
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

    PNodes Locate(int i){
        PNodes x=root;
        while(true){
            int p=x->child[0]->size+1;
            if(i==p) break;
            if(i<p) x=x->child[0];
            else x=x->child[1],i-=p;
        }
        return x;
    }

    inline void Split(const T &i, SplayTree<T> &TL, SplayTree<T> &TR){
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

    friend inline SplayTree<T> Join(SplayTree<T> TL, SplayTree<T> TR){
        if(TL.root==nil) return TR;
        PNodes A=TL.Locate(TL.Size());
        TL.Splay(A);
        TL.SetChild(A,TR.root,1);
        TL.Update(A);
        SplayTree<T> res=TL;
        TL.root=TR.root=nil;
        return res;
    }
 
    inline PNodes Insert(const T &key){
        PNodes cur=root;
        PNodes last=nil;
        int dir=-1;
        while(cur!=nil){
            last=cur;
            if(cur->val==key) return Splay(cur);
            else{
                dir=(key>cur->val);
                cur=cur->child[dir];
            }
        }
        PNodes u=new Nodes();
        u->val=key;
        u->child[0]=u->child[1]=u->parrent=nil;
        Update(u);
        if(dir!=-1) SetChild(last,u,dir);
        return Splay(u);
    }
 
    inline PNodes Find(const T &key){
        PNodes cur=root;
        while(cur!=nil){
            if(key==cur->val) return Splay(cur);
            cur=cur->child[key>cur->val];
        }
        return nil;
    }
 
    inline void Erase(const T &key){
        if(Find(key)==nil) return;
        PNodes left=root->child[0];
        PNodes right=root->child[1];
        left->parrent=right->parrent=nil;
        delete root;
        if(left==nil) root=right;
        else{
            left=Splay(RightMost(left));
            SetChild(left,right,1);
            root=left;
            Update(root);
        }
    }

    inline int Size(){
        return root->size;
    }
 
    inline bool isEmpty(){
        return root==nil;
    }
 
    inline PNodes LeftMost(PNodes x){
        if(x==nil) return nil;
        while(x->child[0]!=nil) x=x->child[0];
        return x;
    }
 
    inline PNodes RightMost(PNodes x){
        if(x==nil) return nil;
        while(x->child[1]!=nil) x=x->child[1];
        return x;
    }
 
    inline T Minimum(){return LeftMost(root)->val;}
    inline T Maximum(){return RightMost(root)->val;}
 
    inline PNodes Greater(const T &x){
        PNodes cur=root;
        PNodes res=nil;
        while(cur!=nil){
            if(x>=cur->val) cur=cur->child[1];
            else{
                if(res==nil || cur->val<res->val) res=cur;
                cur=cur->child[0];
            }
        }
        if(res!=nil) Splay(res);
        return res;
    }
 
    inline PNodes Smaller(const T &x){
        PNodes cur=root;
        PNodes res=nil;
        while(cur!=nil){
            if(x<=cur->val) cur=cur->child[0];
            else{
                if(res==nil || cur->val>res->val) res=cur;
                cur=cur->child[1];
            }
        }
        if(res!=nil) Splay(res);
        return res;
    }

    inline T KthOrder(const T &k){
        int rem=0;
        int nleft=0;
        PNodes p=root;
        while(p!=nil){
            if(p->child[0]==nil) nleft=0; 
            else nleft=p->child[0]->size;
            if(rem+nleft+1==k){
                Splay(p);
                break;
            }
            if(rem+nleft+1>k) p=p->child[0];
            else{
                p=p->child[1];
                rem+=nleft+1;
            }
        }
        return p->val;
    }

    inline int SmallerCount(const int &key){
        int res=0;
        int nleft=0;
        PNodes p=root;
        while(p!=nil){
            if (p->child[0]==nil) nleft=0; 
            else nleft=p->child[0]->size;
            if(p->val<key){
                res+=nleft+1;
                if(p->child[1]!=nil) p=p->child[1];
                else break;
            }
            else{
                if(p->child[0]!=nil) p=p->child[0];
                else break;
            }
        }
        Splay(p);
        return res;
    }

    inline void Dfs(const PNodes &x){
        if(x==nil) return;
        Dfs(x->child[0]);
        cout<<x->val<<' ';
        Dfs(x->child[1]);
    }

    inline void Print(){Dfs(root);}
};

SplayTree<int> tree;

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

inline void S(const int &i, const int &m, const int &j){
    SplayTree<int> T1,T2,T3;
    tree.Split(i-1,T1,T2);
    T2.Split(m,T2,T3);
    tree=Join(T1,T3);
    tree.Split(j-1,T1,T3);
    tree=Join(Join(T1,T2),T3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    int n,x; cin>>n>>x;
    nil=new Nodes();
    nil->child[0]=nil->child[1]=nil->parrent=nil;
    nil->val=0; nil->size=0;
    tree.root=Build(1,n);
    while(x--){
        int i,m,j; cin>>i>>m>>j;
        S(i,m,j);
    }
    tree.Print();

    #ifdef Kami
    auto end=chrono::steady_clock::now();
    cerr<<"\nIn milliseconds : "
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr<<'\n'<<"In seconds : "<<fixed<<setprecision(3)
        <<(double)chrono::duration_cast<chrono::milliseconds>(end-start).count()/1000<<'\n';
    #endif

    return 0;
}
