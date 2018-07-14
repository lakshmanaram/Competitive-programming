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
		long n;
		cin >> n;
		vector<long long> arr(n);
		for (long i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<long long> ans(n+1, -1);
		for (long i = arr.size()-1; i >= 0; i--) {
			bool flag = false;
			for (long j = ans.size()-1; j >= 0; j--) {
				if (!flag) {
					if (j != -1) {
						flag = true;
						j += 2;
						continue;
					} else
						continue;
				}
				if (j == 0) {
					ans[0] = max(ans[0], 6*arr[i]);
				} else {
					if (ans[j-1]-arr[i] >= 0)
						ans[j] = max(ans[j], min(ans[j-1]-arr[i], 6*arr[i]));
				}
			}
		}
		for (long i = 0; i < ans.size(); i++) {
			if (ans[i] == -1) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}