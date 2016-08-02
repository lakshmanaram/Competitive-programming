#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++){
		cin>>arr[i];
	}	
	long maxv = 1, count= 1;
	for(long i=1;i<n;i++){
		if(arr[i] > arr[i-1])
			count++;
		else
			count = 1;
		maxv = max(count,maxv);
	}
	cout<<maxv;
}