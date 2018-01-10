#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(),S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
int main(){
	ll a, b, x, y, z;
	cin>>a>>b>>x>>y>>z;
	x = 2*x;
	z = 3*z;
	x += y;
	z += y;
	// cout<<a<<" "<<b<<endl;
	// cout<<x<<" "<<z<<endl;
	ll ans = 0;
	ans += max(0LL, x-a);
	ans += max(0LL, z-b);
	cout<<ans<<endl;
	return 0;
}