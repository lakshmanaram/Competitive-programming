#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	ll n, a, b;
	cin>>n>>a>>b;
	ll aval = ceil(((double)a*n)/(a+b));
	ll bval = n-aval;
	// cout<<aval<<" "<<bval<<endl;
	ll ans = 0;
	if(aval > 0 && bval > 0)
		ans = max(ans, min(a/aval, b/bval));
	aval = floor(((double)a*n)/(a+b));
	bval = n-aval;
	if(aval > 0 && bval > 0)
		ans = max(ans, min(a/aval, b/bval));
	cout<<ans<<endl;
	return 0;
}