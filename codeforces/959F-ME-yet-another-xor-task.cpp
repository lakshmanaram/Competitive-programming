#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
ll mod = 1000000007;
using namespace std;
int main(){
	long n, q;
	scanf("%ld %ld", &n, &q);
	vector<long long> arr(n);
	for (long i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	vector<pair<long, pair<long long, long> > > qs;
	for (long i = 0; i < q; i++) {
		long a;
		long long b;
		scanf("%ld %lld", &a, &b);
		qs.pb(mp(a-1, mp(b, i)));
	}
	vector<ll> ans(q);
	sort(all(qs));
	long start = 0;
	set<ll> sa;
	ll j = 1;
	sa.insert(0);
	for (long i = 0; i < qs.size(); i++) {
		while (start <= qs[i].first) {
			if (sa.find(arr[start]) != sa.end()) {
				j <<= 1;
				j %= mod;
			} else {
				vector<ll> temps;
				for (auto it = sa.begin(); it != sa.end(); it++) {
					temps.pb((*it)^arr[start]);
				}
				for (long i = 0; i < temps.size(); i++) {
					sa.insert(temps[i]);
				}
				sa.insert(arr[start]);
			}
			start++;
		}
		if (sa.find(qs[i].second.first) != sa.end()) {
			ans[qs[i].second.second] = j;
		} else {
			ans[qs[i].second.second] = 0;
		}
	}
	for (long i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}