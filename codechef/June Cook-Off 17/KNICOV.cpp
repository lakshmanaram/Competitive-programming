#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){ 

	long t;
	cin>>t;
	while(t--) {
		long n,m;
		cin>>n>>m;
		long x = min(n,m);
		m = max(n,m);
		n = x;
		if(n == 1)
			cout<<m<<endl;
		else {
			long ans = ((m-1)/6 + 1)*4;
			if(m%6 == 1) ans -= 2;
			if(n == 3) {
				if(m %6 == 2) {
					if(m >= 14) ans--;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}