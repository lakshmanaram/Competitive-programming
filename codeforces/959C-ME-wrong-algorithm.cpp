#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	ll n;
	cin >> n;
	if (n <= 5) {
		cout << -1 << endl;
	} else  {
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "2 4" << endl;
		for(long i = 5; i <= n; i++) {
			cout << "1 " << i << endl;
		}
	}
	for(long i = 2; i <= n; i++) {
		cout << "1 " << i << endl;
	}
	return 0;
}