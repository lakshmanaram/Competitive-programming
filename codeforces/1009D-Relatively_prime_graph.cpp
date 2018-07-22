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
	vector<pair<long, long> > edges;
	vector<vector<long> > arr (n+1);
	arr[1].pb(0);
	for (long i = 1; i <= n; i++) {
		long val = i;
		if(val == 1) val = 2;
		while (val <= n) {
			for (long j = 0; j < arr[i].size(); j++) {
				long v = arr[i][j] + val;
				if (v <= n) {
					arr[v].pb(i);
					edges.pb(mp(i, v));
				} else break;
				if (edges.size() == m) break;
			}
			val += i;
			if (edges.size() == m) break;
		}
		if (edges.size() == m) break;
	}
	// for (long i = 0; i < arr.size(); i++) {
	// 	for (long j = 0; j < arr[i].size(); j++) {
	// 		cout << arr[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	if (edges.size() == m && m >= n-1) {
		printf("Possible\n");
		for (long i = 0; i < edges.size(); i++) {
			printf("%ld %ld\n", edges[i].first, edges[i].second);
		}
	} else {
		printf("Impossible\n");
	}
	return 0;
}