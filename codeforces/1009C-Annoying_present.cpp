#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long double ans = 0;
	long n, m;
	cin >> n >> m;
	long double c = n/2;
	long double d = n - c - 1;
	c *= c+1;
	d *= d+1;
	for (long i = 0; i < m; i++) {
		long double a, b;
		cin >> a >> b;
		ans += a;
		if (b > 0) {
			long double p = b*(n-1);
			p /= 2.0;
			ans += p;
		} else {
			long double p = b*(c+d);
			p /= 2.0;
			p /= n;
			ans += p; 
		}
	}
	for(long i = 1; i <= 10000; i++) {
	long double a = i/10001.0, b = (10001-i)/10001.0;
	cout << fixed << setprecision(7) << 100000*(a+b)*1000 << endl;
}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}