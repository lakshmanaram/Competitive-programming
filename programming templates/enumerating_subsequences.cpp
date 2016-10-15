#include <bits/stdc++.h>
using namespace std;
void enumerate_subsequences (vector<long long> arr, int i, vector<long long> so_far) {
	if(i == arr.size()){
		for(long j=0;j<so_far.size();j++){
			cout<<so_far[j]<<" ";
		}
		cout<<endl;
	} else {
		enumerate_subsequences(arr,i+1,so_far);
		so_far.push_back(arr[i]);
		enumerate_subsequences(arr,i+1,so_far);
	}
}
int main() {
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++) {
		cin>>arr[i];
	}
	vector<long long> emptyarr;
	enumerate_subsequences(arr,0,emptyarr);
	return 0;
}