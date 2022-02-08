#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

typedef long long ll;

using namespace std;

ll l,r; string s;
int d,k;
ll f[20][20][13][2][2];
ll kq;

inline ll dp(int pos,int cnt,int pred,bool pre,bool greater10){
    ll &res=f[pos][cnt][pred][pre][greater10];
    if(res!=-1) return res;
    if(pos>=s.size()) return cnt<=k&&greater10;
    res=0;
    if(pos==0){
        up(x,0,s[pos]-'0') res+=dp(pos+1,cnt,x,pre&&(x==s[pos]-'0'),x>0);
        //cerr<<res<<' '<<pos<<' '<<cnt<<' '<<pred<<' '<<pre<<'\n';
        return res;
    }
    int limit=(pre)? s[pos]-'0' : 9;
    up(x,0,limit) res+=dp(pos+1,cnt+(abs(pred-x)<=d&&greater10),x,pre&&(x==limit),greater10||x);
    //cerr<<res<<' '<<pos<<' '<<cnt<<' '<<pred<<' '<<pre<<' '<<limit<<'\n';
    return res;
}

inline string nts(ll x){
    string res;
    while(x) res.pb(x%10+'0'),x/=10;
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>l>>r>>d>>k;
    fill_n(&f[0][0][0][0][0],sizeof(f)/sizeof(f[0][0][0][0][0]),-1);
    s=nts(r);
    kq=dp(0,0,0,1,0);
    fill_n(&f[0][0][0][0][0],sizeof(f)/sizeof(f[0][0][0][0][0]),-1);
    s=nts(l-1);
    kq-=dp(0,0,0,1,0);

    cout<<kq;

    return 0;
}
