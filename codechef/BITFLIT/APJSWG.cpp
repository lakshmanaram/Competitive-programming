#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		vector<long> a(n);
		for(long i=0;i<n;i++)
			cin>>a[i];
		long i;
		bool flag = true;
		int ans = 0;
		for(i=a.size()-1;i>=0;i--) {
			if(a[i]!=i+1) {
				if((i>=1) && (a[i-1] == i+1)) {
					long t = a[i];
					a[i] = a[i-1];
					a[i-1] = t;
					ans++;
				} else if((i>=2) && (a[i-2]==i+1)) {
					long t = a[i-1];
					a[i-1] = a[i-2];
					a[i-2] = t;
					t = a[i];
					a[i] = a[i-1];
					a[i-1] = t;
					ans += 2;
				} else {
					flag = false;
					break;
				}
			}
		}
		if(flag)
			cout<<ans<<endl;
		else
			cout<<"Not Allowed\n";
	}
	return 0;
}