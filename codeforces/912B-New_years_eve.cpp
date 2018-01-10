#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(),S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
int main(){
	ll a, k;
	cin>>a>>k;
	ll p = 0;
	ll b = a;
	while(a){
		p++;
		a /= 2;
	}
	if(k > 1){
		ll ans = pow(2, p);
		ans--;
		cout<<ans<<endl;
	} else 
		cout<<b<<endl;
	return 0;
}