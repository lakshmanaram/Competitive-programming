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
		ll a, b, c, n;
		S(n);
		S(a);
		S(b);
		S(c);
		if(a < b) swap(a, b);
		if(a < c) swap(a, c);
		if(b > c) swap(b, c);
		vector<ll> facs, revfacs;
		for(long i=1;i<=sqrt(n)+1;i++){
			if(n%i == 0){
				facs.pb(i);
				ll x = n/i;
				if(x > i){
					revfacs.pb(x);
				} else break;
			}
		}
		reverse(all(revfacs));
		facs.insert(facs.end(), all(revfacs));
		ll ans = 0;
		for(long i=0;i<facs.size();i++){
			ll x = facs[i];
			if(x > a) break;
			ll num = n/x;
			for(ll j=1;j<=sqrt(num) && j <= b;j++){
				if(num % j == 0){
					ll k = num/j;
					if(j <= b && k <= c) ans++;
					if(j <= c && k <= b && j != k) ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}