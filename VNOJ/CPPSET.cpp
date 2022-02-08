#include <bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a-1;i>=b;i--)
#define pb push_back
#define Kamisama

using namespace std;

template<typename T> inline void Read(T &x){
    register char c;
    bool neg=false;
    for(c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') neg=true;
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    if(neg) x=-x;
}

struct SkipLists;
struct Column;
struct Cell;
typedef long long ll;
typedef Column* PColumn;

struct SkipLists{
    static const int MaxLevel=20;
    int Size;
    PColumn head,tail;
    SkipLists();
    inline bool Empty();
    inline PColumn Lower_bound(const int &val);
    inline PColumn Upper_bound(const int &val);
    inline void Insert(const int &val);
    inline void Erase(const int &val);
    inline void Show();
}SL;

struct Column{
    int value;
    vector<Cell> cells;
};

struct Cell{
    PColumn prevC,nextC;
};

inline SkipLists::SkipLists(){
    head=new Column;
    tail=new Column;
    head->value=tail->value=0;
    rep(i,0,MaxLevel){
        head->cells.pb({NULL,tail});
        tail->cells.pb({head,NULL});
    }
}

inline bool SkipLists::Empty(){
    return head->cells[0].nextC==tail;
}

inline PColumn SkipLists::Lower_bound(const int &val){
    PColumn it=head;
    repd(i,MaxLevel,0){
        while(it->cells[i].nextC!=tail && it->cells[i].nextC->value<val)
            it=it->cells[i].nextC;
    }
    return it->cells[0].nextC;
}

inline PColumn SkipLists::Upper_bound(const int &val){
    PColumn it=head;
    repd(i,MaxLevel,0){
        while(it->cells[i].nextC!=tail && it->cells[i].nextC->value<=val)
            it=it->cells[i].nextC;
    }
    return it->cells[0].nextC;
}

inline void SkipLists::Insert(const int &val){
    PColumn chk=Lower_bound(val);
    if(chk!=tail && chk->value==val) return;
    PColumn NewCol=new Column;
    NewCol->value=val;
    NewCol->cells.pb({NULL,NULL});
    while(NewCol->cells.size()<MaxLevel && rand()%2==0) NewCol->cells.pb({NULL,NULL});
    PColumn it=head;
    repd(i,MaxLevel,0){
        while(it->cells[i].nextC!=tail && it->cells[i].nextC->value<val)
            it=it->cells[i].nextC;
        if(i<NewCol->cells.size()){
            PColumn nextIt=it->cells[i].nextC;
            it->cells[i].nextC=NewCol;
            nextIt->cells[i].prevC=NewCol;
            NewCol->cells[i].prevC=it;
            NewCol->cells[i].nextC=nextIt;
        }
    }
    Size++;
}

inline void SkipLists::Erase(const int &val){
    PColumn DelCol=Lower_bound(val);
    if(DelCol==tail || DelCol->value!=val) return;
    PColumn it=head;
    repd(i,MaxLevel,0){
        while(it->cells[i].nextC!=tail && it->cells[i].nextC->value<=val)
            it=it->cells[i].nextC;
        if(it==DelCol){
            PColumn prevIt=it->cells[i].prevC;
            PColumn nextIt=it->cells[i].nextC;
            prevIt->cells[i].nextC=nextIt;
            nextIt->cells[i].prevC=prevIt;
        }
    }
    delete DelCol;
    Size--;
}

inline void SkipLists::Show(){
    cerr<<"Set's size= "<<Size<<"\nSet: ";
    for(PColumn it=head;it!=tail;it=it->cells[0].nextC)
        cerr<<it->value<<' ';
    cerr<<'\n';
}

int main(){
    srand(time(NULL));
    int queryType,x;
    while(true){
        Read(queryType);
        if(queryType==0) break;
        if(queryType==1) Read(x),SL.Insert(x);
        if(queryType==2) Read(x),SL.Erase(x);
        if(queryType==3){
            if(SL.Empty()) cout<<"empty\n";
            else cout<<SL.head->cells[0].nextC->value<<'\n';
        }
        if(queryType==4){
            if(SL.Empty()) cout<<"empty\n";
            else cout<<SL.tail->cells[0].prevC->value<<'\n';
        }
        if(queryType==5){
            Read(x);
            if(SL.Empty()) cout<<"empty\n";
            else{
                PColumn res=SL.Upper_bound(x);
                if(res==SL.tail) cout<<"no\n";
                else cout<<res->value<<'\n';
            }
        }
        if(queryType==6){
            Read(x);
            if(SL.Empty()) cout<<"empty\n";
            else{
                PColumn res=SL.Lower_bound(x);
                if(res==SL.tail) cout<<"no\n";
                else cout<<res->value<<'\n';
            }
        }
        if(queryType==7){
            Read(x);
            if(SL.Empty()) cout<<"empty\n";
            else{
                PColumn res=SL.Lower_bound(x)->cells[0].prevC;
                if(res==SL.head) cout<<"no\n";
                else cout<<res->value<<'\n';
            }
        }
        if(queryType==8){
            Read(x);
            if(SL.Empty()) cout<<"empty\n";
            else{
                PColumn res=SL.Upper_bound(x)->cells[0].prevC;
                if(res==SL.head) cout<<"no\n";
                else cout<<res->value<<'\n';
            }
        }
    }
    return 0;
}