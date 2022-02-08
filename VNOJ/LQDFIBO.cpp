#include <iostream>
#include <cstdio>
#include <iomanip>
#include <array>
#define taskname "TEST"
using namespace std;

struct bigNum:array<long long,20>{
    static const long long radix=1e18;
    static const int length=18;
    static const int nDigits=20;
    #define self (*this)
    bigNum(){self.fill(0);}
    bigNum(const long long &other){self.fill(0); self[0]=other;}
    inline bigNum& operator =(const long long &other){
        self.fill(0); self[0]=other;
        return self;
    }
    inline bigNum& operator =(const bigNum &other){
        copy(other.begin(),other.end(),self.begin());
        return self;
    }
    inline bigNum operator +(const bigNum &other){
        bigNum res;
        for(int i=0;i<nDigits;i++){
            res[i]+=self[i]+other[i];
            if(res[i]>=radix) res[i]-=radix, res[i+1]++;
        }
        return res;
    }
    friend inline ostream& operator <<(ostream &cout, const bigNum &num){
        int i=nDigits-1;
        for(;i && num[i]==0;i--);
        for(cout<<num[i--];i>=0;i--) cout<<setw(length)<<setfill('0')<<num[i];
        return cout;
    }
};

struct Hash{
    static const unsigned long long BaseH=257;
    static const int maxn=7e4+1;
    unsigned long long hashPow[maxn],hashing[maxn];
    inline void BuildHash(const string &str){
        hashing[0]=0;
        hashPow[0]=1;
        for(int i=1;i<(int)str.size();i++){
            hashing[i]=hashing[i-1]*BaseH+str[i];
            hashPow[i]=hashPow[i-1]*BaseH;
        }
    }
    inline unsigned long long Get(const int &i, const int &j){
        return hashing[j]-hashing[i-1]*hashPow[j-i+1];
    }
};

int n,m;
unsigned long long patHashing;
Hash tex,pat;
string s1,s2,s,f[15];

inline void Enter(){
    cin>>n>>s1>>s2>>s;
    m=s.size(); s=' '+s;
    pat.BuildHash(s); patHashing=pat.Get(1,m);
}

inline void BuildFibo(){
    f[1]=s1; f[2]=s2;
    for(int i=3;i<15;i++) f[i]=f[i-1]+f[i-2];
}

inline void Calculate(const int &id1, const int &id2, int &cnt){
    string text=' '+f[id1]+f[id2];
    tex.BuildHash(text); cnt=0;
    for(int i=f[id1].size()-m+2;i<=(int)f[id1].size();i++)
        cnt+=(tex.Get(i,i+m-1)==patHashing);
}

inline void Compute(const int &id, bigNum &res){
    f[id]=' '+f[id]; tex.BuildHash(f[id]);
    for(int i=1;i<=(int)f[id].size()-m;i++){
        res=res+bigNum(tex.Get(i,i+m-1)==patHashing);
    }
}

inline void Solve(){
    if(n<15){
        bigNum res; Compute(n,res);
        cout<<res;
    } else{
        int cntEven,cntOdd;
        bigNum preRes,curRes,temp;
        Calculate(13,12,cntEven); Calculate(14,13,cntOdd);
        Compute(13,preRes); Compute(14,curRes);
        for(int i=15;i<=n;i++){
            if(i&1) temp=curRes+preRes+bigNum(cntOdd);
            else temp=curRes+preRes+bigNum(cntEven);
            preRes=curRes;
            curRes=temp;
        }
        cout<<curRes;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);if(fopen(taskname".INP","r"))
    freopen(taskname".INP","r",stdin),
    freopen(taskname".OUT","w",stdout);
    Enter();
    BuildFibo();
    Solve();
    return 0;
}
