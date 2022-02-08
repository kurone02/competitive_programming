#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#define GetBit(x,k) (x>>k&1)
#define Kami
#define taskname "TEST"
using namespace std;

class TTrie{
private:
    static const int bonus=1e9+3;
    struct TNodes{
        int cnt;
        TNodes* child[2];
    }*root;
    inline TNodes* NewNode(){
        TNodes *node=new TNodes;
        node->cnt=0;
        node->child[0]=node->child[1]=NULL;
        return node;
    }
    inline TNodes* Delete(TNodes* &node, const int &x, const int &lv){
        if(!node) return NULL;
        int k=GetBit(x+bonus,lv);
        node->cnt--;
        node->child[k]=Delete(node->child[k],x,lv-1);
        if(node->cnt==0){
            delete node;
            return NULL;
        } return node;
    }
public:
    inline TTrie(){root=NewNode();}
    inline int Size(){
        int res=0;
        if(root->child[0]) res+=root->child[0]->cnt;
        if(root->child[1]) res+=root->child[1]->cnt;
        return res;
    }
    inline void Insert(const int &x){
        if(Find(x)) return;
        TNodes *node=root;
        for(int i=31;i>=0;i--){
            int k=GetBit(x+bonus,i);
            if(!node->child[k]) node->child[k]=NewNode();
            node=node->child[k];
            node->cnt++;
        }
    }
    inline bool Find(const int &x){
        TNodes *node=root;
        for(int i=31;i>=0;i--){
            int k=GetBit(x+bonus,i);
            if(!node->child[k]) return false;
            node=node->child[k];
        }
        return true;
    }
    inline void Delete(const int &x){if(Find(x)) Delete(root,x,31);}
    inline int GetKth(int k){
        int res=0;
        TNodes *node=root;
        for(int i=31;i>=0;i--){
            if(node->child[0]){
                if(k<=node->child[0]->cnt){
                    node=node->child[0];
                    continue;
                } else k-=node->child[0]->cnt;
            }
            res|=1<<i;
            node=node->child[1];
        }
        return res-bonus;
    }
    inline int GetRank(const int &x){
        int res=0;
        TNodes *node=root;
        for(int i=31;i>=0;i--){
            if(GetBit(x+bonus,i)){
                if(node->child[0]) res+=node->child[0]->cnt;
                if(!node->child[1]) break;
                node=node->child[1];
            } else if(!node->child[0]) break;
            else node=node->child[0];
        }
        return res;
    }
}trie;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    #ifdef Kami
    auto start=chrono::steady_clock::now();
    #endif

    int nTest;
    for(cin>>nTest;nTest--;){
        char type; int x;
        cin>>type>>x;
        if(type=='I') trie.Insert(x);
        else if(type=='D') trie.Delete(x);
        else if(type=='K'){
            if(trie.Size()<x) cout<<"invalid\n";
            else cout<<trie.GetKth(x)<<'\n';
        } else cout<<trie.GetRank(x)<<'\n';
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
