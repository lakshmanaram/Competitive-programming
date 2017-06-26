#include <bits/stdc++.h>
using namespace std;

vector<long long> powm;

int main() {
	long n;
	long long k;
	cin>>n>>k;
	long long mod = 1000000007;
	vector<long long> arr(n);
	for(long i=0;i<n;i++) cin>>arr[i];
	powm.resize(n+1);
	powm[0] = 1;
	for(long i=1;i<=n;i++) {
		powm[i] = powm[i-1]*2;
		powm[i] %= mod;
	}
	if( k >= n  || *max_element(arr.begin(),arr.end()) < k) {
		cout<<powm[n-1]<<endl;
	} else if(k == 0) 
		cout<<0<<endl;
	else {
		vector<long> hash(k+1,0);
		long counted = 0;
		vector<long long>  ans(arr.size(),0);
		vector<long long>  presum(arr.size(),1);
		ans[0] = 1;
		long i=-1;
		if(arr[0] <= k){
			counted = 1;
			hash[arr[0]] = 1;
		}
		for(long j=1;j < arr.size();j++) {
			ans[j] += presum[j-1];
			ans[j] %= mod;
			if(arr[j] <= k){
				hash[arr[j]]++;
				if(hash[arr[j]] == 1) {
					counted++;
				}
			}
			while(counted == k+1) {
				i++;
				if(arr[i]<=k){
					hash[arr[i]]--;
					if(hash[arr[i]] == 0)
						counted--;
				}
			}
			if(i == -1) ans[j]++;
			if(i-1>=0)
				ans[j] -= presum[i-1];
			ans[j] += mod;
			ans[j] %= mod;
			presum[j] = presum[j-1] + ans[j];
			presum[j] %= mod;
		}
		cout<<ans[arr.size()-1]<<endl;
	}
	return 0;
}