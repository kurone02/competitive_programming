#include <iostream>
#include <cstdio>
#define taskname "TEST"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long s,e;
    cin>>s>>e;
    for(long long i=s;i<=e;i++){
        long long x=i;
        int d[20]={};
        int sz=0;
        while(x){
            d[++sz]=x%10;
            x/=10;
        }
        bool found=true;
        for(int i=1;i<=sz;i++)
            if(d[i]!=d[sz-i+1]) found=false;
        if(found) cout<<"Palindrome!\n";
        else cout<<i<<'\n';
    }
    return 0;
}
