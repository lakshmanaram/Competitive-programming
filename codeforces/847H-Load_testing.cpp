#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<long long> arr(n);
	for(long i=0;i<n;i++) cin>>arr[i];
	vector<long long> ideal_left, ideal_right;
	ideal_left.pb(arr[0]);
	ideal_right.pb(arr[arr.size()-1]);
	for(long i=1;i<arr.size();i++)
		ideal_left.pb(max(arr[i], ideal_left[i-1]+1));
	for(long i=arr.size()-2;i>=0;i--)
		ideal_right.pb(max(arr[i], ideal_right[ideal_right.size()-1]+1));
	reverse(ideal_right.begin(), ideal_right.end());
	vector<long long> dleft, dright;
	for(long i=0;i<n;i++){
		dleft.push_back(ideal_left[i]-arr[i]);
		dright.push_back(ideal_right[i]-arr[i]);
	}
	// for(long i=0;i<n;i++){
	// 	cout<<dleft[i]<<" ";
	// }
	// cout<<endl;
	// for(long i=0;i<n;i++){
	// 	cout<<dright[i]<<" ";
	// }
	cout<<endl;
	for(long i=1;i<n;i++){
		dleft[i] += dleft[i-1];
		dright[n-1-i] += dright[n-i];
	}
	long long ans;
	for(long i=0;i<n;i++){
		if(i==0) ans = dleft[i] + dright[i] - min(ideal_left[i]-arr[i], ideal_right[i]-arr[i]);
		else ans = min(ans, dleft[i] + dright[i] - min(ideal_left[i]-arr[i], ideal_right[i]-arr[i]));
	}
	cout<<ans<<endl;
	return 0;
}