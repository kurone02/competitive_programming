#include <bits/stdc++.h>
#include "wall.h"
#define CL(x) (x<<1)
#define CR(x) (x<<1|1)
using namespace std;
const int maxn=2e6+7;
const int inf=1e9+7;
 
class SegmentTree{
private:
    int low,high,mn,mx,pos,l[4*maxn],r[4*maxn];
    struct Nodes{
        int min,max;
        inline Nodes(int _min=0, int _max=0){
            tie(min,max)=tie(_min,_max);
        }
    }it[4*maxn];
public:
    inline void Combine(const int &x){
        it[x].min=min(it[CL(x)].min,it[CR(x)].min);
        it[x].max=max(it[CL(x)].max,it[CR(x)].max);
    }
 
    inline void Build(const int &x, const int &low, const int &high){
        l[x]=low; r[x]=high;
        if(low==high) it[x]=Nodes(0,0);
        else{
            int mid=(low+high)>>1;
            Build(CL(x),low,mid);
            Build(CR(x),mid+1,high);
            Combine(x);
        }
    }
 
    inline void Modify(const int &x, const int &mn, const int &mx){
        if(it[x].min>mx) it[x].min=it[x].max=mx;
        else if(it[x].max<mn) it[x].min=it[x].max=mn;
        else{
            it[x].min=max(it[x].min,mn);
            it[x].max=min(it[x].max,mx);
        }
    }
 
    inline void PushDown(const int &x){
        if(x!=1) Modify(x,it[x>>1].min,it[x>>1].max);
    }
 
    inline void Update(const int &x){
        PushDown(x);
        if(l[x]>high || r[x]<low) return;
        if(low<=l[x] && r[x]<=high) Modify(x,mn,mx);
        else{
            Update(CL(x));
            Update(CR(x));
            Combine(x);
        }
    }
 
    inline void Update(const int &i, const int &j, const int &min, const int &max){
        tie(low,high,mn,mx)=tie(i,j,min,max);
        Update(1);
    }
 
    inline int Query(const int &x){
        if(l[x]>pos || r[x]<pos) return inf;
        PushDown(x);
        if(l[x]==r[x]) return it[x].min;
        return min(Query(CL(x)),Query(CR(x)));
    }
 
    inline int Get(const int &x){
        return pos=x,Query(1);
    }
}seg_tree;
 
int n,k;
int op[maxn],left[maxn],right[maxn],height[maxn],finalHeight[maxn];
 
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    seg_tree.Build(1,0,n-1);
    for(int i=0;i<k;i++){
        if(op[i]==1) seg_tree.Update(left[i],right[i],height[i],inf);
        else seg_tree.Update(left[i],right[i],0,height[i]);
    }
    for(int i=0;i<n;i++) finalHeight[i]=seg_tree.Get(i);
}