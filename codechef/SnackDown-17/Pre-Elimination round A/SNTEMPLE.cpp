#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		scanf("%ld",&n);
		vector<long long> a(n);
		for(long i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		long long ans = 0;
		long long prev = 0;
		for(long i=0;i<n;i++) {
			if(a[i] > prev) {
				ans += a[i] - (prev+1);
				a[i] = prev+1;
			}
			prev = a[i];
		} 
		prev = 0;
		long long newval = 0;
		for(long i=n-1; i>=0; i--) {
			if(a[i] > prev) {
				newval = prev+1;
				ans += a[i] - newval;
				a[i] = newval;
			}
			prev = a[i];
		}
		vector<long long>::iterator it = max_element(a.begin(),a.end()), it1;
		it1 = it;
		long long val = *it;
		while(it != a.begin()) {
			ans += (*it) - val;
			*it = val;
			val = max((long long)0,val-1);
			it--;
		}
		ans += (*it) - val;
		*it = val;
		it = it1;
		val = *it;
		while(it != a.end()) {
			ans += (*it) - val;
			*it = val;
			val = max((long long)0,val-1);
			it++; 
		}
		cout<<ans<<endl;
	}
}