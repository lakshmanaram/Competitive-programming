#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	long long ans = 0;
	for(int i=1;i<n;i++) {
		if(arr[i]+arr[i-1] < k){
			ans += k-arr[i-1] - arr[i];
			arr[i] = k-arr[i-1];
		}
	}	
	cout<<ans<<endl;
	for(int i=00;i<n;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}