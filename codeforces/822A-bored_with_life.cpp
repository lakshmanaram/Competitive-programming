#include <bits/stdc++.h>
using namespace std;
long long fac(long n){
	if(n <= 1)
		return 1;
	return n*fac(n-1);
}
int main() {
	long long a,b;
	cin>>a>>b;
	cout<<fac(min(a,b));
}
