#include <iostream>
using namespace std ;

main()
{
	int n , f[1001] , a[1001] , res = 0 ;
	cin >> n ;
	for( int i=0;i<n;i++) {
		cin >> a[i] ;
		f[i] = 1 ;
		for( int j=0;j<i;j++)
			if ( f[j] + 1 > f[i] && a[i] > a[j] ) f[i] = f[j] + 1 ;
		if ( f[i] > res ) res = f[i] ;
	}
	cout << res ;
}
