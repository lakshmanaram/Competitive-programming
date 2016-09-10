#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	for(long i=0;i<n-1;i++)
		arr[i] = arr[i]+arr[i+1];
	for(long i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}