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
		vector<ll> arr;
		for(long i = 0; i < 4; ++i){
			ll x;
			cin>>x;
			arr.pb(x);
		}
		sort(all(arr));
		if( arr[0] == arr[1] && arr[2] == arr[3])
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}