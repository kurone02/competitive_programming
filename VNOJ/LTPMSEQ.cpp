#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int maxn=1e5+7;

int n;
string s[maxn];
map<string,int> d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>n;
    up(i,1,n) cin>>s[i],d[s[i]]++;

    up(i,1,n) if(d[s[i]]%2){
        cout<<s[i];
        return 0;
    }
    cout<<-1;

    return 0;
}
