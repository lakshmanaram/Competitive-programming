#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long> a(n),b(n);
		for(long i=0; i<n;i++)
			scanf("%ld",&a[i]);
		for(long i=0; i<n;i++)
			scanf("%ld",&b[i]);
		long long ans1, ans2;
		ans1 = ans2 = 0;
		for(long i=0;i<n;i++){
			if(i%2)
				ans1 += a[i];
			else
				ans1 += b[i];
		}
		for(long i=0;i<n;i++){
			if(!(i%2))
				ans2 += a[i];
			else
				ans2 += b[i];
		}
		cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}