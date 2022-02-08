#include <bits/stdc++.h>
using namespace std;
const int maxn=1507;
 
int cnt[maxn];
 
void initialize(int n){
  
}
 
int hasEdge(int u, int v){
  return ++cnt[max(u,v)]==max(u,v);
}