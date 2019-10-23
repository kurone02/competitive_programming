#include <iostream>
#include <cstdio>
#define taskname "TEST"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int *a=new int[n];
    fill(a,a+n,1);
    while(m--){
        int x,y,val;
        cin>>x>>y>>val; x--,y--;
        a[x]=max(a[x],val);
        a[y]=max(a[y],val);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
