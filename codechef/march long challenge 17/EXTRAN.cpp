#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		scanf("%ld",&n);
		vector<long> a(n);
		for(long i=0; i<n;i++)
			scanf("%ld",&a[i]);
		long min1, min2, max1;
		max1 = max(a[0],a[1]);
		min1 = min(a[0],a[1]);
		min2 = max(a[0],a[1]);
		set<long> arr;
		long i;
		for(i=0;i<n;i++){
			long s = arr.size();
			arr.insert(a[i]);
			if(s == arr.size()) {
				printf("%ld\n",a[i]);
				break;
			}
			if(i < 2)
				continue;
			if(a[i] <= min1) {
				min2 = min1;
				min1 = a[i];
			}
			else if (a[i] < min2)
				min2 = a[i];
			if(a[i] > max1)
				max1 = a[i];
		}
		if(i == n) {
			if(max1 - min2 == n-2)
				printf("%ld\n",min1);
			else
				printf("%ld\n",max1);
		}
	}
	return 0;
}