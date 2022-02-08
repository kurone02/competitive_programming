#include <iostream>
using namespace std;
 
int main() {
	
	int n; string s;
	
	while(cin>>s){
		cin>>n;
		if(s=="[END]") return 0;
		if(n%5==0 || n%5==2) cout<<"Hanako\n";
		else cout<<"Taro\n";
	}
 
	return 0;
} 