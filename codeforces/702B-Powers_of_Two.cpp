#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	long long ans = 0;
	map<long long, long> ansmap;
	for(long i=0;i<n;i++){
		if(ansmap.count(arr[i]) != 0){
			ans += ansmap[arr[i]];
			// cout<<ansmap[arr[i]]<<" for "<<arr[i]<<endl;
		}
		int tempj = log2(arr[i]);
		for(long long j=pow(2,tempj+1); j < 2000000000; j*=2){
			if(ansmap.count(j-arr[i]) != 0)
				ansmap[j-arr[i]]++;
			else
				ansmap[j-arr[i]] = 1;
		}
	}
	cout<<ans;
	return 0;
} 