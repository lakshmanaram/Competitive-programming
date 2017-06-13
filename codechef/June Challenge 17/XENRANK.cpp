#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long long u,v;
		cin>>u>>v;
		long long ans = u+v;
		ans = ans*(ans+1)/2;
		ans += u+1;
		cout<<ans<<endl;
	}
	return 0;
} 
