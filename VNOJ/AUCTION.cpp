#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> a;
 
void Init()
{
    cin>>n>>m;
    a.resize(m);
    for (int i=0;i<m;i++)
    {
        cin>>a[i];
    }
}
 
void Solve()
{
    int res=0;
    int gia=0;
    for (int i=0;i<m;i++)
    {
        int sum=0;
        for (int j=0;j<m;j++)
        {
            if(a[j]>=a[i]) sum+=a[i];
        }
        sum=min(sum,n*a[i]);
        if(sum==res)
            gia=min(gia,a[i]);
        if(sum>res)
        {
            res=sum;
            gia=a[i];
        }
    }
    cout<<gia<<" "<<res;
}
 
int main()
{
    Init();
    Solve();
}