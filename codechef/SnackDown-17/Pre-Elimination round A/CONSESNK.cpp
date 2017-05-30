#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long t;
	cin>>t;
	while(t--) {
		long long n,l,a,b;
		cin>>n>>l>>a>>b;
		vector<long long> arr(n);
		for(long i=0;i<n;i++) cin>>arr[i];
		sort(arr.begin(),arr.end());
		long long ans = 0;
		long long val = a;
		long long start = a;
		vector<long long> diff;
		for(long i=0;i<n;i++) {
			ans += abs(arr[i]-val);
			if(arr[i] > val) diff.push_back(arr[i]-val);
			val+=l;
		}
		sort(diff.begin(),diff.end());
		//cout<<ans<<endl;
		long long temp = ans;
		for(long i=0;i<diff.size();i++) {
			if(a+diff[i] > b-n*l) break;
			if(i!=0)
				temp -= (2*(diff.size()-i)-n)*(diff[i]-diff[i-1]);
			else
				temp -= (2*(diff.size()-i)-n)*(diff[i]);
			if(ans > temp) ans = temp;
			//cout<<ans<<" "<<diff[i]<<endl;
		}
		temp = 0;
		val = b-n*l;
		for(long i=0;i<n;i++) {
			temp += abs(arr[i]-val);
			val+=l;
		}
		if(ans > temp) ans = temp;
		cout<<ans<<endl;
	}
	return 0;
}
