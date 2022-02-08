#include <cstdio>
#include <vector>
#include "network.h"
using namespace std;
const int maxn=1e3+7;
 
vector<int> disList[maxn],path;
 
void findRoute(int n, int a, int b){
  int pathLength=ping(a,b);
  for(int i=1;i<=n;i++) if(i!=a && i!=b) disList[ping(a,i)].push_back(i);
  path.push_back(b);
  for(pathLength--;pathLength>=0;pathLength--){
    for(int c: disList[pathLength]) if(!ping(c,b)){
      b=c;
      path.push_back(b);
      break;
    }
  }
  for(int i=(int)path.size()-1;i>=0;i--) travelTo(path[i]);
}