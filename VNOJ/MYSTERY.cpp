#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
 
#define ll              long long
 
using namespace std;
 
const int   base = 20122007;
ll          n,res = 1;
 
ll  g(int x)
{
    if (x == 1) return 3;
    ll tmp = g(x/2) % base;
    if (x % 2 == 0) return (tmp*tmp) % base;
    return ((tmp*tmp % base)*3) % base;
}
 
ll  f(int x)
{
    return (g(x) - 1 + base) % base;
}
 
int main()
{
    scanf("%lli",&n);
    for (int i=1;i*i<=n;i++) {
        if (n % i == 0) {
            if (i*i == n)
                res = res*f(i) % base;
            else
                res = ((res*f(i) % base) * f(n/i)) % base;
        }
    }
    printf("%lli",res);
    return 0;
}