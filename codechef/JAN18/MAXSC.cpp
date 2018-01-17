#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n;
		cin>>n;
		vector<ll> temp(n, 0);
		vector<vector<ll> > arr(n, temp);
		for(long i=0;i<n;i++){
			for(long j = 0; j < n; ++j){
				cin>>arr[i][j];
			}
		}
		for(long i = 0; i < n; ++i){
			sort(all(arr[i]));
		}
		bool flag = false;
		ll to_search = arr[n-1][n-1]+1;
		ll ans = 0;
		for(long i = n-1; i>=0 ;i--){
			vector<ll>::iterator it = lower_bound(all(arr[i]), to_search);
			if(it == arr[i].begin()){
				flag = true;
				break;
			}
			it--;
			ans += *it;
			to_search = *it;
		}
		if(flag){
			cout<<"-1\n";
		} else {
			cout<<ans<<endl;
		}
	}
	return 0;
}