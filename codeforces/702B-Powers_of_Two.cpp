#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	long long ans = 0;
	vector<long long> pow2;
	pow2.push_back(1);
	for(long long i = 2; i <= 2000000000; i *= 2){
		pow2.push_back(i);
	}
	for(long i=0;i<n;i++){
		for(long j = 0; j<i; j++){
			if(binary_search(pow2.begin(), pow2.end(), arr[i]+arr[j]))
				ans++;
		}
	}
	cout<<ans;
}