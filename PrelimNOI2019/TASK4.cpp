#include <bits/stdc++.h>
#include "squarerect.h"

using namespace std;

bool am_i_square(int n,int q){
    int xmin,xmax,ymin,ymax;
    xmax=ymax=0;
    ymin=xmin=101;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(inside_shape(i,j)){
            xmin=min(xmin,i);ymin=min(ymin,j);
            xmax=max(xmax,i);ymax=max(ymax,j);
        }
    }
    if(xmax-xmin==ymax-ymin) return true;
    return false;
}
