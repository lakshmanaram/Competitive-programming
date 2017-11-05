#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		ll p;
		cin>>p;
		long cakewalk = 0, hard = 0;
		for (long i = 0; i < n; ++i){
			ll x;
			cin>>x;
			if(x >= p/2) cakewalk++;
			else if (x <= p/10)	hard++;
		}
		if(cakewalk == 1 && hard == 2) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}