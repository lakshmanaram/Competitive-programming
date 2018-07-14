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
	cin >> n;
	vll arr(n);
	for (long i = 0; i < n; i++) { 
		cin >> arr[i];
	}
	vll::iterator it = min_element(arr.begin(), arr.end());
	ll ts = accumulate(arr.begin(), arr.end(), 0);
	ll x = *it;
	ll y = ts - x;
	if (n == 1 || x == y) {
		cout << -1 << endl;
	} else {
		cout << 1 << endl << distance(arr.begin(), it)+1 << endl;
	}
	return 0;
}