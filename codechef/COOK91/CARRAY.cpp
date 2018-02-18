#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		ll n, k, b;
		cin>>n>>k>>b;
		vector<ll> arr(n);
		for(long i=0;i<arr.size();i++) cin>>arr[i];
		set<pair<ll, long> > s;
		sort(all(arr));
		long ans = 0;
		for(long i=0;i<arr.size();i++){
			ll y = arr[i]*k + b;
			if(s.empty()){
				s.insert(mp(y, 1));
				ans = max(ans, 1L);
			} else {
				auto val = s.upper_bound(mp(arr[i], arr.size()));
				if(val != s.begin()) {
					val--;
					long count = val->second;
					count++;
					auto val2 = s.upper_bound(mp(y, arr.size()));
					val2--;
					if(val2->second < count){
						s.insert(mp(y, count));
						ans = max(ans, count);
					}
				}
			}
		} 
		printf("%ld\n", ans);
	}
	return 0;
}