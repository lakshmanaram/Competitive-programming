#include <bits/stdc++.h>
using namespace std;
int main() {
	long n, na, nb;
	cin>>n>>na>>nb;
	vector<long> arr(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	double ans=0;
	double temp = 0;
	long i=0;
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());
	for(;i<min(na,nb);i++){
		temp += arr[i];
	}
	ans = temp / min(na,nb);
	long x = i;
	temp = 0;
	for(;i<x+max(na,nb);i++){
		temp += arr[i];
	}
	ans += temp / max(na,nb);
	cout.precision(8);
	cout<<std::fixed<<ans<<endl;
	return 0;
}
