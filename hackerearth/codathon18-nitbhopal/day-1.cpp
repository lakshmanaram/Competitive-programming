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
		long n;
		scanf("%ld", &n);
		vector<ll> arr(n);
		for(long i=0;i<n;i++){
			scanf("%lld", &arr[i]);
		}
		ll ans = 0;
		for(long i=0;i<arr.size()-1;i++){
			ans += arr[i];
			if(!(ans & 1)) ans++;
		}
		ans += arr[n-1];
		cout<<ans<<endl;
	}
	return 0;
}