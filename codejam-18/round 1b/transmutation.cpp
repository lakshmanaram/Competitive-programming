#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
vector<pair<long, long> > arr;
vector<long> g;
set<long> seen;
bool get_arr (long i) {
	if(seen.find(i) != seen.end()) return false;
	seen.insert(i);
	if (arr[i].first == 0 || arr[i].second == 0)
		return false;
	if (g[arr[i].first] > 0 && g[arr[i].second] > 0){
		g[arr[i].first]--;
		g[arr[i].second]--;
		return true;
	} else if (g[arr[i].first] > 0 && g[arr[i].second] == 0) {
		if (get_arr(arr[i].second) && g[arr[i].first] > 0) {
			g[arr[i].first]--;
			return true;
		}
		return false;
	} else if (g[arr[i].first] == 0 && g[arr[i].second] > 0) {
		if (get_arr(arr[i].first)) {
			if(g[arr[i].second] > 0){
				g[arr[i].second]--;
				return true;
			}
		}
		return false;
	} else {
		if (get_arr(arr[i].first) && get_arr(arr[i].second))
			return true;
		else
			return false;
	}
}
int main(){
	long tt;
	cin >> tt;
	for(long t = 1; t <= tt; t++) {
		arr.clear();
		g.clear();
		long n;
		cin >> n;
		arr.resize(n);
		g.resize(n);
		for (long i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].first--;
			arr[i].second--;
		}
		for (long i = 0; i < n; i++) {
			cin >> g[i];
		}
		seen.clear();
		while(get_arr(0)) {
			seen.clear();
			g[0]++;
		}
		cout << "Case #" << t << ": " << g[0] << endl;
	}
	return 0;
}
