//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
using namespace std;

int n,m,res;
vector<int> T,F;

void Init()
{
    #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
#endif
    ios_base::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    F.resize(8*n + 5);
    T.resize(8*n + 5);
}

void Update(int k, int l, int r, int x, int y, int value)
{
    if(T[k]!=0)
    {
        F[k]+=T[k];
        T[2*k]+=T[k];
        T[2*k+1]+=T[k];
        T[k]=0;
    }
    if(l>y || r<x) return;
    if(x<=l && y>=r)
    {
        F[k]+=value;
        T[2*k]+=value;
        T[2*k+1]+=value;
        T[k]=0;
        return;
    }
    int m=(l+r)/2;
    Update(2*k,l,m,x,y,value);
    Update(2*k+1,m+1,r,x,y,value);
    F[k]=max(F[2*k],F[2*k+1]);
}

void Query(int k, int l, int r, int x, int y)
{
    if(T[k]!=0)
    {
        F[k]+=T[k];
        T[2*k]+=T[k];
        T[2*k+1]+=T[k];
        T[k]=0;
    }
    if(l>y || r<x) return;
    if(x<=l && r<=y)
    {
        res=max(res,F[k]);
        return;
    }
    int m=(l+r)/2;
    Query(2*k,l,m,x,y);
    Query(2*k+1,m+1,r,x,y);
    F[k]=max(F[2*k],F[2*k+1]);
}
void Solve()
{
    while(m--)
    {
        int type;
        scanf("%d",&type);
        if(type==0)
        {
            int x,y,value;
            scanf("%d%d%d",&x,&y,&value);
            Update(1,1,n,x,y,value);
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            res=0;
            Query(1,1,n,x,y);
            printf("%d\n",res);
        }
    }
}

int main()
{
    Init();
    Solve();
}
