#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin>>n;
	long long prev = 1,i=2, ans = 0;
	while(n >= i) {
		i += prev;
		prev = i - prev;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
