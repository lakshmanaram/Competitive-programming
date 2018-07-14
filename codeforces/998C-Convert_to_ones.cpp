#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long n;
	ll x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	long cont_z = 0, noz = 0;
	for (long i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			cont_z++;
		} else {
			if (cont_z > 0) {
				cont_z = 0;
				noz++;
			}
		}
	}
	if(cont_z > 0) noz++;
	ll ans = noz * y;
	long xc = 0;
	while (noz > 0) {
		// cout << xc * x + noz * y << endl;
		ans = min(ans, xc * x + noz * y);
		noz--;
		xc++;
	}
	cout << ans << endl;
	return 0;
}