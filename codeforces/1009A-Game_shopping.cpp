#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long n, m;
	cin >> n >> m;
	vll arr(m), cost(n);
	for (long i = 0; i < n; i++) cin >> cost[i];
	for (long i = 0; i < m; i++) cin >> arr[i];
	long i = 0, j = 0;
	long ans = 0;
	while(i < n && j < m) {
		if(cost[i] <= arr[j]) {
			j++;
			ans++;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}