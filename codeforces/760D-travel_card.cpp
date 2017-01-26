#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	long n;
	cin>>n;
	vector<ll> arr(n);
	ll x;
	for(long i=0; i< n; i++)
		scanf("%lld", &arr[i]);
	long it, sit, it1;
	sit = 0;
	ll a, b;
	a = 0;
	b = 0;
	vector<ll> dp(n);
	it = it1 = 0;
	for(long i = 0; i < n; i++,sit++) {
		b = a + 20;
		while(it != arr.size() && arr[it] <= arr[sit] - 90) 
			it++;
		if(it == 0)
			b = min(b,(ll)50);
		else {
			it--;
			b = min(b,dp[it]+50);
		}
		while(it1 != arr.size() && arr[it1] <= arr[sit] - 1440) 
			it1++;
		if(it1 == 0)
			b = min(b,(ll)120);
		else {
			it1--;
			b = min(b,dp[it1]+120);
		}
		// cout<<"it = "<<*it<<" it1 = "<<*it1<<" sit = "<<*sit<<endl;
		dp[sit] = b;
		printf("%lld\n",b-a);
		// cout<<a<<" b = "<<b<<endl;
		a = b;
	}
	return 0;
}