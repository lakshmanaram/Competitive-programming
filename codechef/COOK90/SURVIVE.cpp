#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		ll n, k, s;
		S(n);
		S(k);
		S(s);
		if(s < 7){
			if(n < k) cout<<"-1"<<endl;
			else {
				double temp = k;
				temp *= s;
				temp /= n;
				ll ans = ceil(temp);
				printf("%lld\n", ans);	
			}
			continue;
		}
		if(6*(n-k) < k){
			cout<<-1<<endl;
		} else {
			double temp = k;
			temp *= s;
			temp /= n;
			ll ans = ceil(temp);
			printf("%lld\n", ans);
		}
	}
	return 0;
}