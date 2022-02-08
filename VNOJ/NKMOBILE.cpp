#include<bits/stdc++.h>

using namespace std;

const int maxn=1030;

int n,type;
int bit[maxn][maxn];

inline void update(int x,int y,int val){
    for(int i=x;i<=n;i+=i&-i)
        for(int j=y;j<=n;j+=j&-j) bit[i][j]+=val;
}

inline int get(int x,int y){
    int res=0;
    for(int i=x;i;i-=i&-i)
        for(int j=y;j;j-=j&-j) res+=bit[i][j];
    return res;
}

inline int getsum(int x1,int y1,int x2,int y2){
    return get(x2,y2)-get(x2,y1-1)-get(x1-1,y2)+get(x1-1,y1-1);
}

int main(){
    cin>>type>>n;
    while(cin>>type){
        if(type==3) break;
        if(type==1){
            int x,y,A;
            cin>>x>>y>>A; x++,y++;
            update(x,y,A);
        }
        if(type==2){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            x1++,y1++,x2++,y2++;
            cout<<getsum(x1,y1,x2,y2)<<'\n';
        }
    }
    return 0;
}
