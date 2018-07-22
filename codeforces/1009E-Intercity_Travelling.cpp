#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll mod = 998244353;
int main(){
	long n;
	scanf("%ld", &n);
	vll arr(n);
	for (long i =0; i< n; i++)
		scanf("%lld", &arr[i]);
	vll sarr;
	ll sum = 0;
	for (long i = 0; i < arr.size(); i++) {
		sum += arr[i];
		sum %= mod;
		sarr.pb(sum);
	}
	vll mul;
	mul.pb(1);
	sum = 1;
	ll pow = 1;
	for (long i = 1; i < n; i++) {
		mul.pb((sum + pow)%mod);
		sum += (sum + pow)%mod;
		sum %= mod;
		pow *= 2;
		pow %= mod;
	}
	// for (long i = 0; i < n; i++)
	// 	cout << mul[i] << " ";
	// cout << endl;
	ll ans = 0;
	reverse(all(sarr));
	for (long i = 0; i < n; i++) {
		ans += (mul[i] * sarr[i])%mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}