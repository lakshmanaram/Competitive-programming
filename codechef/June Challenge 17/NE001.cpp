#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long long> arr(n);
		for(long i=0;i<n;i++) cin>>arr[i];
		long count = 0;
		long long sum = 0;
		long long ans = 0;
		vector<long long> minarr; 
		for(long i=0;i<n;i++) {
			if(arr[i] >= 0) {
				count++;
				sum += arr[i];
			} else minarr.push_back(arr[i]);
		}			
		sort(minarr.begin(),minarr.end());
		reverse(minarr.begin(),minarr.end());
		for(long i=0;i<minarr.size();i++) {
			if((sum + minarr[i]) * (count+1) >= sum*count+minarr[i] ) {
				sum += minarr[i];
				count++;
			} else {
				ans += minarr[i];
			}
		}
		ans += sum*count;
		cout<<ans<<endl;
	}
	return 0;
}