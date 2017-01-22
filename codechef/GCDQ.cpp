#include <bits/stdc++.h>
using namespace std;
long gcd ( long a, long b ) {
	return (!b)?a:gcd(b,a%b);
}
int main() {
	long t;
	cin>>t;
	while(t--) {
		long n,q;
		scanf("%ld %ld", &n, &q);
		vector<long> arr(n);
		for(long i=0;i<n;i++)
			scanf("%ld", &arr[i]);
		vector<long> gcdf(n), gcdb(n);
		gcdf[0] = arr[0];
		for(long i=1;i<n;i++){
			gcdf[i] = gcd(gcdf[i-1],arr[i]);
		}
		reverse(arr.begin(),arr.end());
		gcdb[0] = arr[0];
		for(long i=1;i<n;i++){
			gcdb[i] = gcd(gcdb[i-1],arr[i]);
		}
		reverse(gcdb.begin(),gcdb.end());
		while(q--) {
			long l,r;
			scanf("%ld %ld", &l, &r);
			long x,y;
			x = (l==1)?arr[0]:gcdf[l-2];
			y = (r==n)?arr[n-1]:gcdb[r];
			printf("%ld\n",gcd(x,y));
		}
	}
	return 0;
}