#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long k;
		cin>>k;
		vector<long long> arr(n);
		for (long i = 0; i < arr.size(); ++i)
			cin>>arr[i];
		arr.push_back(-1);
		sort(arr.begin(),arr.end());
		long ans = -1;
		for(long i=1;i<arr.size();ans = arr[i], i++){
			if(arr[i] == arr[i-1]) continue;
			if(arr[i] - arr[i-1] -1 <= k){
				k -= arr[i] - arr[i-1] -1;
				continue;
			}
			break;
		}
		cout<<ans+k+1<<endl;
	}
	return 0;
}