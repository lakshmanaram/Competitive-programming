#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long tt;
	cin >> tt;
	for (long t = 1; t <= tt; t++) {
		cout << "Case #" << t << ": ";
		long n, l;
		cin >> n >> l;
		vector<string> arr(n);
		for (long i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (l == 1) {
			cout << "-\n";
			continue;
		}
		bool found = false;
		for (long i = 1; i < l; i++) {
			map<char, set<char> > m;
			set<char> prev;
			for (long j = 0; j < n; j++){
				prev.insert(arr[j][i-1]);
				if (m.find(arr[j][i]) == m.end()) {
					set<char> temp;
					temp.insert(arr[j][i-1]);
					m[arr[j][i]] = temp;
				} else {
					m[arr[j][i]].insert(arr[j][i-1]);
				}
			}
			for (auto it = m.begin(); it != m.end(); it++) {
				if ((it->second).size() != prev.size()) {
					for (auto sit = prev.begin(); sit != prev.end(); sit++) {
						if ((it->second).find(*sit) == (it->second).end()) {
							string ans = "";
							for (long k = 0; k < l; k++) {
								if (k == i-1) {
									ans += *sit;
								} else if (k == i) {
									ans += it->first;
								} else {
									ans += arr[0][k];
								}
							}
							cout << ans << endl;
							found = true;
							break;
						}
					}
					if (found)
						break;
				}
			}
			if (found)
				break;
		}
		if (!found) {
			cout << "-\n";
		}
	}
	return 0;
}