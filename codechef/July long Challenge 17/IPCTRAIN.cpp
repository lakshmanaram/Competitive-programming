#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--){
		long n,d;
		cin>>n>>d;
		vector<pair<long, pair<long, long> > > arr(n);
		for(long i=0;i<n;i++){
			cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		long long ans = 0;
		vector<int> a(d+1,0);
		for(long i=0;i<arr.size();i++){
			long begin = arr[i].second.first;
			long days = arr[i].second.second;
			long long val = arr[i].first;
			vector<long> temp;
			while(days != 0 && begin != d+1){
				if(a[begin]!=0){
					temp.push_back(begin);
					begin = a[begin];
				} else {
					temp.push_back(begin);
					begin++;
					days--;
				}
			}
			for(long i=0;i<temp.size();i++)
				a[temp[i]] = begin;
			ans += days*val;
		}
		cout<<ans<<endl;
	}
	return 0;
}