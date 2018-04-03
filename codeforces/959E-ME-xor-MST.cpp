#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
map<ll, ll> m, am;
ll ans( ll n ) {
	if(n == 0) return 0;
	ll k = 1;
	while (k <= n) {
		k <<= 1;
	}
	k >>= 1;
	return m[k] + ans(n-k);
}
int main(){
	m[1] = 1;
	ll cum = 1;
	ll val = 2;
	while( val <= 1000000000000LL) {
		m[val] = cum + val;
		cum += m[val];
		val <<= 1;
	}
	ll n;
	cin>> n;
	cout<< ans(n-1);
	return 0;
}