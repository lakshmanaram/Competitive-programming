#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long n;
	cin>>n;
	vll arr(n);
	for(long i=0;i<n;i++) scanf("%lld", &arr[i]);
	ll ans = 0;
	for(long i=1;i<n;i++){
		for(long j=0;j<i;j++){
			if(arr[j] > arr[i]){
				ans++;
			}
		}
	}
	ll m;
	cin>>m;
	bool f = true;
	if(ans&1) f = false;
	while(m--){
		ll l, r;
		scanf("%lld %lld", &l, &r);
		ll x = r-l;
		x = (x*(x+1))/2;
		if(x&1) f = !f;
		if(f) cout<<"even\n";
		else cout<<"odd\n";
	}
	return 0;
}