#include<bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	// set<vector<int> > b;
	long ans = 0;
	for(long i=1;i<=n;i++) {
		for(long j=i;j<=n;j++) {
			long k = i^j;
			if(i+j > k && i+k > j && j+k > i && k != 0 && k <= n  && k > i && k > j) {
				// vector<int> a;
				// a.push_back(i);
				// a.push_back(j);
				// a.push_back(k);
				// sort(a.begin(), a.end());
				ans++;
				// b.insert(a);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}