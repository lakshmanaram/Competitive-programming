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
	ll a;
	cin >> n >> a;
	vll arr(n);
	for (long i = 0; i < n; i++) { 
		cin >> arr[i];
	}
	vll ans_arr;
	long odd, even;
	odd = even = 0;
	for (long i = 0; i < n-1; i++) {
		if (arr[i] & 1) odd++;
		else even++;
		if (odd == even) {
			ans_arr.pb(abs(arr[i+1] - arr[i]));
		}
	}
	sort(all(ans_arr));
	long ans = 0;
	for (long i = 0; i < ans_arr.size(); i++) {
		if (ans_arr[i] <= a) {
			a -= ans_arr[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}