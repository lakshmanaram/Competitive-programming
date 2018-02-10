#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll gcd(ll a, ll b){
	return (b==0)?a:gcd(b, a%b);
}
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		ll a, b, x, y;
		S(a);
		S(b);
		S(x);
		S(y);
		if(a == b){
			printf("%lld 2\n%lld %lld\n", abs(x-y), a, b);
			continue;
		}
		ll val = abs(x - y);
		ll g = gcd(a, b);
		ll ans = min(val%g, g - (val%g));
		pair<ll, ll> v = extendedEuclid(a, b).second, w;
		w = v;
		if(w.first > 0) {
			w.first -= b;
			w.second += a;
		} else {
			w.first += b;
			w.second -= a;
		}
		ll q1, q2, q3, q4;
		q1 = abs(v.first);
		q2 = abs(v.second);
		q3 = abs(w.first);
		q4 = abs(w.second);
		v.first = q1*a*((val/g) + 1);
		v.second = q2*b*((val/g) + 1);
		w.first = q3*a*((val/g) + 1);
		w.second = q4*b*((val/g) + 1);
		ll tans, xa, xb;
		tans = abs(x + abs(v.first) - y - abs(v.second));
// 		cout<<"x = "<<x<<" y = "<<y<<endl;
		xa = abs(v.first);
		xb = abs(v.second);
// 		cout<<"tans here1 = "<<tans<<" "<<xa<<" "<<xb<<endl;;
		// cout<<"where it all starts "<<v.first<<" "<<v.second<<" "<<w.first<<" "<<w.second<<endl;
		if(tans > abs(x + abs(w.first) - y - abs(w.second))){
			tans = abs(x + abs(w.first) - y - abs(w.second));
			xa = abs(w.first);
			xb = abs(w.second);
// 			cout<<"tans here2 = "<<tans<<" "<<xa<<" "<<xb<<endl;;
		} 
		v.first = q1*a*((val/g));
		v.second = q2*b*((val/g));
		w.first = q3*a*((val/g));
		w.second = q4*b*((val/g));
		if(tans > abs(x + abs(v.first) - y - abs(v.second))){
			tans = abs(x + abs(v.first) - y - abs(v.second));
			xa = abs(v.first);
			xb = abs(v.second);
// 			cout<<"tans here3 = "<<tans<<" "<<xa<<" "<<xb<<endl;;
		} 
		if(tans > abs(x + abs(w.first) - y - abs(w.second))){
			tans = abs(x + abs(w.first) - y - abs(w.second));
			xa = abs(w.first);
			xb = abs(w.second);
// 			cout<<"tans here4 = "<<tans<<" "<<xa<<" "<<xb<<endl;
		} 
		if(tans != ans) while(1);
		printf("%lld 2\n", tans);
		printf("%lld %lld\n", xa, xb);
	}
	return 0;
}