#include <bits/stdc++.h>
using namespace std;
vector<vector<long> > divisor(750001);
void pre() {
    for(long i=1; i<=750000; i++) {
        long j = i;
        while( j <= 750000 ) {
            divisor[j].push_back( i );
            j += i;
        } 
    }
}
long long mod = 1000000007;
int main() {
	pre();
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long> a(n);
		vector<long> dp(750001,0);
		long ans = 0;
		for(long i=0;i<n;i++){
			scanf("%ld",&a[i]);
			dp[a[i]] = 1;
		}
		sort(a.begin(),a.end());
		vector<long>::iterator it,divisorit;
		for(it = a.begin();it!=a.end();it++) {
			long temp = 0;
			for(divisorit = divisor[*it].begin();divisorit != divisor[*it].end();divisorit++) {
				temp += dp[*divisorit];
				temp %= mod;
			}
			dp[*it] = temp;
			// cout<<*it<<" "<<dp[*it]<<endl;
			ans += dp[*it];
			ans %= mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
