#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int main() {
	ll n,m,z;
	cin>>n>>m>>z;
	ll ans = n*m;
	ans /= gcd(n,m);
	cout<<(ll)z/ans;

	return 0;
}