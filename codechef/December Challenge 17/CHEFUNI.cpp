#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
ll check_b(vector<long> arr, long a, long b, long c){
	ll ans = 0;
	long diff = arr[2] - arr[1];
	if(diff >= arr[0]){
		ans += (arr[0]+arr[1])*b;
		arr[2] -= arr[0]+arr[1];
		arr[0] = arr[1] = 0;
	} else {
		long m = (arr[0]-diff)/2;
		ans += (diff+m+m)*b;
		arr[0] -= diff+m+m;
		arr[1] -= m;
		arr[2] -= diff+m;
		ans += arr[1]*b;
		arr[2] -= arr[1];
		arr[1] = 0;
	}
	ans += (arr[0] + arr[1] + arr[2])*a;
	return ans;
}
ll check_c(vector<long> arr, long a, long b, long c){
	ll ans = 0;
	long m = arr[0];
	ans += m * c;
	for(int i=0;i<3;i++) arr[i] -= m;
	ans += (arr[0] + arr[1] + arr[2])*a;
	return ans;
}
ll check_bc(vector<long> arr, long a, long b, long c){
	vector<long> x = arr;
	ll ans = 0;
	long diff = arr[2] - arr[1];
	if(diff >= arr[0]){
		ans += (arr[0]+arr[1])*b;
		arr[2] -= arr[0]+arr[1];
		arr[0] = arr[1] = 0;
	} else {
		long m = (arr[0]-diff)/2;
		ans += (diff+m+m)*b;
		arr[0] -= diff+m+m;
		arr[1] -= m;
		arr[2] -= diff+m;
		ans += arr[1]*b;
		arr[2] -= arr[1];
		arr[1] = 0;
	}
	ans += (arr[0] + arr[1] + arr[2])*a;
	
	arr = x;
	if(arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1) {
		ll tempans = 0;
		tempans += c;
		arr[0]--;
		arr[1]--;
		arr[2]--;
		long diff = arr[2] - arr[1];
		if(diff >= arr[0]){
			tempans += (arr[0]+arr[1])*b;
			arr[2] -= arr[0]+arr[1];
			arr[0] = arr[1] = 0;
		} else {
			long m = (arr[0]-diff)/2;
			tempans += (diff+m+m)*b;
			arr[0] -= diff+m+m;
			arr[1] -= m;
			arr[2] -= diff+m;
			tempans += arr[1]*b;
			arr[2] -= arr[1];
			arr[1] = 0;
		}
		tempans += (arr[0] + arr[1] + arr[2])*a;
		ans = min(ans, tempans);
	}
	return ans;
}
ll check_cb(vector<long> arr, long a, long b, long c){
	ll ans = 0;
	long m = arr[0];
	ans += m * c;
	for(int i=0;i<3;i++) arr[i] -= m;
	m = min(arr[1],arr[2]);
	ans += m*b;
	arr[2] -= m;
	arr[1] -= m;
	if(arr[0] < 0 || arr[1] < 0 || arr[2] < 0) while(1);
	ans += (arr[0] + arr[1] + arr[2])*a;
	return ans;
}
ll check_cb_mod(vector<long> arr, long a, long b, long c){
	ll ans = 0;
	long diff = arr[1] - arr[0];
	ans += diff*b;
	arr[1] -= diff;
	arr[2] -= diff;

	// right till here

	diff = arr[2]-arr[1];
	if(diff > arr[0]) diff = arr[0];
	ans += 2*diff*b;
	arr[1] -= diff;
	arr[0] -= diff;
	arr[2] -= 2*diff;
	ans += arr[0]*c;
	arr[1] -= arr[0];
	arr[2] -= arr[0];
	arr[0] -= arr[0];
	ans += (arr[0] + arr[1] + arr[2])*a;
	return ans;
}
int main(){
	long t;
	cin>>t;
	while(t--) {
		vector<long> arr(3);
		long a, b, c;
		long long ans = 0;
		scanf("%ld %ld %ld %ld %ld %ld", &arr[0], &arr[1], &arr[2], &a, &b, &c);
		sort(arr.begin(),arr.end());
		ans = (arr[0] + arr[1] + arr[2])*a;
		ans = min(ans, check_b(arr, a, b, c));
		ans = min(ans, check_c(arr, a, b, c));
		ans = min(ans, check_bc(arr, a, b, c));
		ans = min(ans, check_cb(arr, a, b, c));
		ans = min(ans, check_cb_mod(arr, a, b, c));
		cout<<ans<<endl;
	}
	return 0;
}