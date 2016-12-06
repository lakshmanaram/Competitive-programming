#include <bits/stdc++.h>
using namespace std;
int main() {
	long n;
	long x;
	cin>>n>>x;
	vector<long> arr(n);
	map<long,long> m;
	for(long i=0;i<n;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	long long ans = 0;
	for(long i=0;i<n;i++){
		long temp = arr[i]^x;
		if(temp == arr[i]) {
			ans += m[temp]-1;
		} else {
			ans += m[temp];
		}
	}
	cout<<ans/2;
	return 0;
}