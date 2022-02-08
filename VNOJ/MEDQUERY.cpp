#include <iostream>
#include <set>
#define taskname "MEDQUERY"

using namespace std;

int n;
multiset<int> low,up;

inline void Refine(){
    if(low.size()>up.size()+1){
        multiset<int>::iterator it=prev(low.end());
        up.insert(*it);
        low.erase(it);
    }
    else if(low.size()<up.size()){
        multiset<int>::iterator it=up.begin();
        low.insert(*it);
        up.erase(it);
    }
}

inline void Insert(const int &x){
    if(x>*prev(low.end())) up.insert(x);
    else low.insert(x);
    Refine();
}

inline void Delete(const int &x){
    if(!low.count(x)) up.erase(up.find(x));
    else low.erase(low.find(x));
    Refine();
}

inline int Query(){
    return *prev(low.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(cin>>n,low.insert(-1),up.insert(1000000001);n--;){
        char type;
        int x;
        cin>>type>>x;
        if(type=='+') Insert(x);
        else Delete(x);
        cout<<Query()<<'\n';
    }
    return 0;
}
