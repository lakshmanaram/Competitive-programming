#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long p,q,r;
		cin>>p>>q>>r;
		vector<long long> a(p),b(q),c(r);
		for(long i=0;i<p;i++)
			scanf("%lld", &a[i]);
		for(long i=0;i<q;i++)
			scanf("%lld", &b[i]);
		for(long i=0;i<r;i++)
			scanf("%lld", &c[i]);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		long long mod = 1000000007;
		long i,k;
		i=k=0;
		long long sumi, sumk;
		sumi=sumk=0;
		long long ans = 0;
		for(long j=0;j<b.size();j++) {
			while(i < p && a[i] <= b[j]) {
				sumi += a[i];
				i++;
			}
			while(k < r && c[k] <= b[j]) {
				sumk += c[k];
				k++;
			}
			sumi %= mod;
			sumk %= mod;
			long long prod = i;
			prod *= k;
			prod %= mod;
			ans += (((prod*b[j])%mod)*b[j])%mod;
			ans += (((sumi*k)%mod)*b[j])%mod;
			ans %=mod;
			ans += (((sumk*i)%mod)*b[j])%mod;
			ans %=mod;
			ans += (sumk*sumi)%mod;
			ans %=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}