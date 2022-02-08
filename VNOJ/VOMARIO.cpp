#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> TLine;
const int maxn=1e5+7;
const int inf=1e9+7;

struct TLiChao{
    int l,r;
    TLine curLine;
    TLiChao *left,*right;
    inline TLiChao(int _l=0, int _r=0){
        l=_l; r=_r;
        curLine=TLine(0,-1e18);
        left=right=NULL;
    }
};

int n,x[maxn],w[maxn],temp[maxn],val[maxn];
long long e[maxn],res;
TLiChao *root;

inline void Build(const int &l, const int &r){
    root=new TLiChao(l,r);
}

inline long long F(const TLine &d, const int &x){
    return d.first*val[x]+d.second;
}

inline void Insert(TLine newLine, const int &low, const int &high, TLiChao *node=root){
    if(node->l>high || node->r<low) return;
    int m=node->l+node->r>>1;
    if(low<=node->l && node->r<=high){
        bool lef=(F(newLine,node->l)>F(node->curLine,node->l));
        bool mid=(F(newLine,m+1)>F(node->curLine,m+1));
        if(mid) swap(newLine,node->curLine);
        if(node->l==node->r) return;
        if(lef!=mid){
            if(!node->left) node->left=new TLiChao(node->l,m);
            Insert(newLine,low,high,node->left);
        } else{
            if(!node->right) node->right=new TLiChao(m+1,node->r);
            Insert(newLine,low,high,node->right);
        }
    } else{
        if(!node->left) node->left=new TLiChao(node->l,m);
        Insert(newLine,low,high,node->left);
        if(!node->right) node->right=new TLiChao(m+1,node->r);
        Insert(newLine,low,high,node->right);
    }
}

inline long long Get(const int &x, TLiChao *node=root){
    int m=node->l+node->r>>1;
    if(node->l==node->r) return F(node->curLine,x);
    if(x<=m){
        if(!node->left) return F(node->curLine,x);
        return max(F(node->curLine,x),Get(x,node->left));
    } else{
        if(!node->right) return F(node->curLine,x);
        return max(F(node->curLine,x),Get(x,node->right));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>w[i]>>e[i];
    set<int> mySet(x+1,x+n+1);
    int sz=0;
    for(set<int>::iterator it=mySet.begin();it!=mySet.end();it++) temp[++sz]=*it;
    for(int i=1;i<=n;i++){
        int newVal=lower_bound(temp+1,temp+sz+1,x[i])-temp;
        val[newVal]=x[i];
        x[i]=newVal;
    }
    Build(1,n); res=-1e18; Insert(TLine(0,0),1,n);
    for(int i=1;i<=n;i++){
        long long f=Get(x[i])+e[i];
        res=max(res,f);
        Insert(TLine(-w[i],f+1ll*w[i]*val[x[i]]),x[i],n);
        Insert(TLine(w[i],f-1ll*w[i]*val[x[i]]),1,x[i]);
    }
    cout<<res;
    return 0;
}