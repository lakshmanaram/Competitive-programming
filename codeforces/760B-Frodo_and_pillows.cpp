#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	long long n,m,k;
	cin>>n>>m>>k;
	ll ans = 1;
	m -= n;
	long long aff, afb;
	aff = 0;
	afb = 0;
	// bool init = true;
	while(m > 0) {
		m -= aff+afb+1;
		ans++;
		aff++;
		if(aff == k)
			aff = k-1;
		if(afb + k < n)
			afb++;
		if(aff + afb + 1 == n) {
			// cout<<"coming in at ans = "<<ans<<" m = "<<m<<endl;
			ans += m / n;
			break;
		}
		// init = !init;
	}
	if(m < 0)
		ans--;
	cout<<ans;
	return 0;
}