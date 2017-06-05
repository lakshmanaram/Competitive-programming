#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;
long long mod = 1000000007;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		arr.resize(n);
		for(long i=0;i<arr.size();i++) cin>>arr[i];
		long long ans = arr[0];
		long long sum = arr[0];
		long long prod = 1;
		for(long long i=1;i<arr.size();i++) {
			long long temp = 0;
			temp = 2*ans;
			temp %= mod;
			temp += (prod*arr[i])%mod;
			temp -= sum;
			temp += mod;
			temp %= mod;
			temp += (sum*arr[i])%mod;
			temp %= mod;
			ans = temp;
			sum = (sum*arr[i])%mod;
			sum += (prod*arr[i])%mod;
			sum %= mod;
			prod *= 2;
			prod %= mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}