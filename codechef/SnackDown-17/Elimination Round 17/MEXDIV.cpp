#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<long long> powm;
long long get_val(long i, long j, long n) {
	return powm[j-i]-1;
}
int main() {
	long n;
	long long k;
	cin>>n>>k;
	long long mod = 1000000007;
	vector<long long> arr(n);
	for(long i=0;i<n;i++) cin>>arr[i];
	powm.resize(n+1);
	powm[0] = 1;
	for(long i=1;i<=n;i++) {
		powm[i] = powm[i-1]*2;
		powm[i] %= mod;
	}
	if( k > n  || *max_element(arr.begin(),arr.end()) < k) {
		cout<<powm[n-1]<<endl;
	} else if(k == 0) 
		cout<<0<<endl;
	else {
		vector<long> hash(k+1,0);
		long counted = 0;
		long i=0,j=-1;
		vector<pair<long, long> > ans;
		while(i<n && j < n) {
			if(counted != k+1) {
				j++;
				if(arr[j] <= k) {
					hash[arr[j]]++;
					if(hash[arr[j]] == 1)
						counted++;
				}
			} else {
				if(hash[arr[i]] == 1) {
					ans.push_back(mp(i,j));
					counted--;
					hash[arr[i]] = 0;
				}
				i++;
			}
		}
		while(i<n && counted) {
			if(hash[arr[i]] == 1) {
				ans.push_back(mp(i,j));
				counted--;
				hash[arr[i]] = 0;
			}
			i++;
		}
		long long ansval = powm[n-1];
		long prev = 0;
		for(long i=0;i<ans.size();i++) {
			ansval -= get_val(ans[i].first,ans[i].second,n);
			if(i!=0) {
				ansval += get_val(prev,ans[i].second,n);
			}
			prev = ans[i].first;
		}
		// long long ansval = 0;
		// long seen_till = 0;
		// long excess = 0;
		// for(long i=0;i<ans.size();i++) {
		// 	cout<<ans[i].first<<" "<<ans[i].second<<endl;
		// 	if(seen_till < ans[i].first) {
		// 		excess += ans[i].first - seen_till;
		// 		ansval += powm[ans[i].second-ans[i].first]-1;
		// 		ansval %= mod;
		// 		seen_till = ans[i].second;
		// 	} else {
		// 		ansval += powm[ans[i].second-ans[i].first]-1;
		// 		ansval -= powm[seen_till - ans[i].first] -1;
		// 		seen_till = ans[i].second;
		// 	}
		// 	cout<<ansval<<endl;
		// }
		ansval *= powm[excess];
		ansval %= mod;
		cout<<ansval<<endl;
	}
	return 0;
}