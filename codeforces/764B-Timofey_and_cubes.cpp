#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	vector<ll> ans;
	stack<ll> st;
	bool start = false;
	for(long i=0;i<n/2;i++){
		if(start) {
			st.push(arr[n-1-i]);
			ans.push_back(arr[i]);
		} else {
			st.push(arr[i]);
			ans.push_back(arr[n-1-i]);
		}
		start = !start;
	}
	if(n&1)
		ans.push_back(arr[n/2]);
	for(long i=0; i< ans.size();i++)
		cout<<ans[i]<<" ";
	while(!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}

	return 0;
}