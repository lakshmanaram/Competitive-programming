#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n, q;
		cin>>n>>q;
		vector<long long> arr(n, 0);
		vector<pair<int, pair<long, long> > > m(q);
		for(long i=0;i<q;i++) {
			scanf("%d %ld %ld", &m[i].first, &m[i].second.first, &m[i].second.second);
		}
		vector<long long> mextra(q,0);
		while(q--){
			if(q != mextra.size()-1)
				mextra[q] += mextra[q+1];
			else mextra[q] = 1;
			mextra[q] %= mod;
			pair<long, long> query = m[q].second;
			if(m[q].first == 2) {
				if(query.first != 1){
					mextra[query.first-2] -= mextra[q];
					mextra[query.first-2] += mod;
					mextra[query.first-2] %= mod;
				}
				mextra[query.second-1] += mextra[q];
				mextra[query.second-1] %= mod;
			} else {
				if(query.first != 1){
					arr[query.first-2] -= mextra[q];
					arr[query.first-2] += mod;
					arr[query.first-2] %= mod;

				}
				arr[query.second-1] += mextra[q];
				arr[query.second-1] %= mod;
			}
		} 
		// for(long i=0;i<arr.size();i++)
		// 	printf("%lld ",mextra[i]);
		// printf("\n");
		for(long i=arr.size()-1;i >= 0; i--){
			if(i != arr.size()-1)
				arr[i] += arr[i+1];
			arr[i] %= mod;
		}
		for(long i=0;i<arr.size();i++)
			printf("%lld ",arr[i]);
		printf("\n");
	}
	return 0;
}