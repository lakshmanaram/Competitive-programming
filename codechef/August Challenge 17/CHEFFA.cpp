#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<vector<vector<long long> > > marr;
vector<long> arr;
long long recurse_util(long prev, long cur, long index){
	if(marr.size() <= index)
		marr.resize(index+1);
	if(marr[index].size() <= prev)
		marr[index].resize(prev+1);
	if(marr[index][prev].size() <= cur)
		marr[index][prev].resize(cur+1, -1);
	if(prev <= 0 && cur <= 0 && index > 70) return 1;
	if(marr[index][prev][cur] == -1){
		long long ans = 0;
		int val = 0;
		while(prev - val >= 0 && cur - val >= 0){
			ans += recurse_util(cur-val, arr[index+1]+val, index+1);
			ans %= mod;
			val++;
		}
		marr[index][prev][cur] = ans%mod;
	}	
	// cout<<p.first<<" "<<p.second<<" at "<<index<<" has value "<<marr[index][p]<<endl;
	return marr[index][prev][cur];
}
void solve(){
	marr.clear();
	while(arr.size() < 100) arr.push_back(0);
	cout<<recurse_util(arr[0], arr[1], 1)%mod<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		arr.clear();
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i];
		solve();
	}
	return 0;
}