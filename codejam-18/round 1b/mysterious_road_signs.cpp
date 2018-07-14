#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
struct pt {
	long d, a, b;
};
int main(){
	long tt;
	cin >> tt;
	for(long t = 1; t <= tt; t++) {
		long s;
		cin >> s;
		vector<pt> arr(s);
		for (long i = 0; i < arr.size(); i++) {
			cin >> arr[i].d >> arr[i].a >> arr[i].b;
		}
		long ans = -1;
		long ans_count = 0;
		for (long i = 0; i < s; i++ ) {
			bool havem = true, haven = false;
			long m = arr[i].d + arr[i].a, n;
			long count = 1;
			for (long j = i + 1; j < s; j++, count++) {
				if (havem) {
					if (arr[j].d + arr[j].a == m) {
						continue;
					} else if (haven) {
						if (arr[j].d - arr[j].b == n) {
							continue;
						} else {
							break;
						}
					} else {
						n = arr[j].d - arr[j].b;
						haven = true;
					}
				}
			}
			long temp_count = count;
			havem = false, haven = true;
			n = arr[i].d - arr[i].b;
			count = 1;
			for (long j = i + 1; j < s; j++, count++) {
				if (haven) {
					if (arr[j].d - arr[j].b == n) {
						continue;
					} else if (havem) {
						if (arr[j].d + arr[j].a == m) {
							continue;
						} else {
							break;
						}
					} else {
						m = arr[j].d + arr[j].a;
						havem = true;
					}
				}
			}
			count = max(count, temp_count);
			if (count > ans) {
				ans = count;
				ans_count = 1;
			} else if (count == ans) {
				ans_count++;
			}
		}
		cout << "Case #" << t << ": " << ans << " " << ans_count << endl;
	}
	return 0;
}
