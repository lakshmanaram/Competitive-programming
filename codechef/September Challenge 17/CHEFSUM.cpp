#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long> arr(n);
		long ans = 0;
		long ansval;
		for(long i=0;i<n;i++) {
			cin>>arr[i];
			if(i == 0) ansval = arr[i];
			if(arr[i] < ansval){
				ansval = arr[i];
				ans = i;
			}
		}
		cout<<ans+1<<endl;
	}
}