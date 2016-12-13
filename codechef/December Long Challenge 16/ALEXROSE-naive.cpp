#include <bits/stdc++.h>
using namespace std;
vector<long> arr;
long k,n;
vector<map<long long, long> > memo;
long func(long so_far, long i, long total) {
	// cout<<"so_far = "<<so_far<<" i = "<<i<<" total = "<<total<<endl;
	if(so_far == total){
		return so_far;
	}
	else if(so_far > total)
		return n;
	else if(i==arr.size())
		return n;
	else {
		long x;
		if(memo[i+1][k-arr[i]+so_far] == 0){
			memo[i+1][k-arr[i]+so_far] = func(k-arr[i]+so_far,i+1,total-arr[i]); // not cutting any on this slot.
		}
		x = memo[i+1][k-arr[i]+so_far];
		if(so_far != 0){
			if(so_far >= arr[i]){
				if(memo[i+1][so_far-arr[i]] == 0) {
					memo[i+1][so_far-arr[i]] = func(so_far-arr[i],i+1,total-arr[i]);
				}
				x = min(x,memo[i+1][so_far-arr[i]]+arr[i]); // cutting these
			}
			else{
				if(memo[i+1][k-(arr[i]-so_far)] == 0){
					memo[i+1][k-(arr[i]-so_far)] = func(k-(arr[i]-so_far),i+1,total-arr[i]);
				}
				x = min(x,so_far+memo[i+1][k-(arr[i]-so_far)]); // cutting these
			}
		}
		return x;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		arr.clear();
		memo.clear();
		long ans = n;
		vector<long long> iarr(n);
		for(long i=0;i<n;i++)
			cin>>iarr[i];
		sort(iarr.begin(),iarr.end());
		pair<long long, long > element;
		element.first = iarr[0];
		element.second = 1;
		long total = 0;
		for(long i=1;i<iarr.size();i++) {
			if(iarr[i] == element.first) {
				element.second++;
			} else {
				element.second %= k;
				if(element.second != 0){
					arr.push_back(element.second);
					total += element.second;
				}
				element.second = 1;
				element.first = iarr[i];
			}
		}
		element.second %= k;
		total += element.second;
		if(element.second!=0)
			arr.push_back(element.second);
		if(arr.size() == 0)
			ans = 0;
		else{
			memo.resize(arr.size());
			ans = func(0,0,total);
		}
		cout<<ans<<endl;
	}
	return 0;
}