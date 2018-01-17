#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
ll max_sum_subarray(vector<ll> arr){
	ll ans = arr[0], current_max = 0;
	for(long i=0;i<arr.size();i++) {
		current_max += arr[i];
		if(current_max > ans)
			ans = current_max;
		if(current_max < 0)
			current_max = 0;
	}
	return ans;
}
ll max_sum_subarray_part(vector<ll> arr){
	for(long i=1;i<arr.size();i++) {
		arr[i] += arr[i-1];
	}
	return *max_element(all(arr));
}
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n, k;
		cin>>n>>k;
		vector<ll> arr(n);
		ll ms = 0;
		for(long i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			ms += arr[i];
		}
		if(k > 1) {
			vll tarr = arr;
			for(long i = 0; i < n; ++i){
				arr.push_back(arr[i]);
			}
			ll temp = max_sum_subarray(arr);
			ll ans = temp;
			temp = max_sum_subarray_part(tarr);
			reverse(all(tarr));
			temp += max_sum_subarray_part(tarr);
			ans = max(ans, temp);
			ans = max(ans, temp+ms*(k-2));
			cout<<ans<<endl;
		} else {
			cout<<max_sum_subarray(arr)<<endl;
		}
	}	
	return 0;
}